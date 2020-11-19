/******************************************************************************/
/* MEASURE.C: Remote Measurement Recorder                                     */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <stdio.h>                       /* standard I/O .h-file              */
#include <ctype.h>                       /* character functions               */
#ifndef MCB2130
  #include <LPC21xx.h>     //remember to change back into <LPC21xx.h> "./Philips/LPC21xx.h"              /* LPC21xx definitions               */
#else
  #include <LPC213x.H>                   /* LPC213x definitions               */
  #define  ADCR    AD0CR
  #define  ADDR    AD0DR
#endif

#include "measure.h"                     /* global project definition file    */


																							/* initialize circular buffer  */
volatile	float L_floor 	=	1;	//1
volatile	int L_state		=	0;  //0 for closed , 1 for opening , 2 for full open , 3 for closing
//int L_ele_prev_floor = -1;
volatile	int L_Direction = -1;	//0 for up , 1 for down
volatile 	int continous_time_button[16];
volatile 	int button_on[16];
volatile 	int off_timer[16];
volatile 	int user_request[16];
volatile 	char state_button[16];
volatile 	int indicate = 1;
//volatile 	int finish_button = 0;
//volatile 	int changes = 0;
volatile 	int time_counter = -1;
volatile	int request_all_from_button[16];
volatile 	int ajar;
/* Default Interrupt Function: may be called when timer ISR is disabled */
void petrinet(void);
void DefISR (void) __irq  {
  ;
}


/******************************************************************************/
/*                Timer Counter 0 interrupt service function                  */
/*                executes each 1ms                                           */
/******************************************************************************/
void wait (void)  {                        /* wait function */
  int  d;

  for (d = 0; d < 1000000; d++);           /* only to delay for LED flashes */
}
__irq void tc0 (void) {
	volatile unsigned long tempa;
	volatile unsigned long run;
	volatile int counter;
	int i;
	//counter was 0 for first element
	//trying to use pin 6 and pin 7 for replacement for pin 8 and 9
	//the reason for replacement is no response from the simulation

	if(time_counter!=-1){
		time_counter++;
	}
	if(indicate){
		for(i = 0 ; i<16;i++){
			state_button[i] = 0;
		}
		indicate = 0;
	}
	//originally was 0x100 for pin 8 , and the counter was 0
	tempa = IOPIN0 & (262143<<6);
	
	counter = 0;


	for(run = 0x40 ; run<=0x1000000 ; run<<=1){
		unsigned int val;
		if(run == 0x100){
			run = run <<2;
		}
		val = tempa & run;
		if(state_button[counter]<3){
			if(val){
				state_button[counter] +=1;
			}
			else{
				state_button[counter] = 0;
			}
		}
		else{
			if(val){
				state_button[counter] = 3;
			}
			else{
				if(state_button[counter]<5){
					state_button[counter] +=1;
				}
				else{
					state_button[counter] = 0;
				}
			}
		}
		
		counter++;
	}
		petrinet();
  	T0IR = 1;                                    //Clear interrupt flag        
  	VICVectAddr = 0;                             //Acknowledge Interrupt       
	
}

void L_elevator_up(float floor){
	unsigned long i;
	unsigned long j;
	i = 3<<28;
	j = 1<<28;
	//printf("up req\n");
	IOCLR1 = i;
	IOSET1 = j;
	//L_ele_prev_floor = (int)(floor);
	L_Direction = 0;
}
void L_elevator_down(float floor){
	unsigned long i;
	unsigned long j;
	i = 3<<28;
	j = 2<<28;
	//printf("down req\n");
	IOCLR1 = i;
	IOSET1 = j;
	//L_ele_prev_floor = (int)(floor);
	L_Direction = 1;
}
void L_elevator_opening(){	//idk is the IOPIN works...
	unsigned long i;
	i = 3<<28;
	//printf("open req\n");
	//IOCLR1 = (3<<28);
	IOSET1 = i;
	L_state = 1;
}
void L_elevator_closing(){
	unsigned long i;
	i = 3<<28;
	//printf("close req\n");
	//IOCLR1 = (3<<28);
	IOSET1 = i;
	time_counter = -1;
	L_state = 3;
}
void L_elevator_opened(){
	unsigned long i;
	i = 3<<28;
	//printf("full open\n");
	IOCLR1 = i;
	//IOSET1 = (3<<28);
	L_state = 2;
	time_counter = 0;
}
void L_elevator_closed(){
	unsigned long i;
	i = 3<<28;
	//printf("full closed\n");
	IOCLR1 = i;
	//IOSET1 = (3<<28);
	L_state = 0;
}
void L_nothing(){
	//IOSET1 = (3<<28);
	//L_ele_prev_floor = -1;
	L_Direction = -1;
}
void save_request(float floor){					//if the current floor requests is also in the same floor , the request will be discarded
	int i;
	int requests [] = {1,2,3,5,6,7,8,9,10,11};
	for(i=0;i<10;i++){
		if(request_all_from_button[requests[i]]){
			user_request[requests[i]] = 1;
		}
	}
	if(floor == 1){
		user_request[requests[0]]=0;
		user_request[requests[3]]=0;
		user_request[requests[6]]=0;
	}
	if(floor == 2){ //consider the direction which elevator is going....
		user_request[requests[1]]=0;
		user_request[requests[4]]=0;
		if(L_Direction == 0){
			user_request[requests[7]]=0;
		}
		else if(L_Direction == 1){
			user_request[requests[8]]=0;
		}
		else if(L_Direction == -1){
			user_request[requests[7]]=0;
			user_request[requests[8]]=0;
		}
		
	}
	if(floor == 3){
		user_request[requests[2]]=0;
		user_request[requests[5]]=0;
		user_request[requests[9]]=0;
	}
	
}
void L_wait5ms(){
	time_counter = 0;
}
void petrinet(void){ 
	int L_floor_into_int_by_mul2;
	int i;
	unsigned long clear;
	clear = 0x0FFF0000;
		/* for debug */
		/*  
		if(finish_button){
			for(int i = 0; i<16;i++){
				cout<<i<<"\t"<<button_on[i]<<"\n";
			}
			finish_button = 0;
			cout<<"\n\n";
  		}*/
		/* need to conservate some button signal until place reached

		*/
		//"i" was 1
		for(i=0 ; i<16 ; i++){
			//request_all_from_button[i] = (user_request[i]|button_on[i])?1:0;
			request_all_from_button[i] = (user_request[i]||(state_button[i]>=3))?1:0;
			//printf("%d %d\n",i,request_all_from_button[i]);
		}
		
		if(L_floor == 1){
			L_floor_into_int_by_mul2 = 2;
		}
		else if(L_floor == 2){
			L_floor_into_int_by_mul2 = 4;
		}
		else if(L_floor == 3){
			L_floor_into_int_by_mul2 = 6;
		}
		else if(L_floor == 1.5){
			L_floor_into_int_by_mul2 = 3;
		}
		else if(L_floor == 2.5){
			L_floor_into_int_by_mul2 = 5;
		}
		switch (L_floor_into_int_by_mul2)
		{
			case 2: //1st floor
					//need also to deal with others floor's request eg./*P0.16*/,P0.17,P0.18,P0.19(/*8*/,9,10,11)
					//and the floor request from user eg /*P0.9*/,P0.10,P0.11(/*1*/,2,3)
					//printf("In floor 1\t");
					if(request_all_from_button[13]){
						if(L_Direction == 0){
							L_floor = 1.5; 
						}
					}
					else{
						switch (L_state){
							case 0:
							if(request_all_from_button[8]&request_all_from_button[1]){
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
							}
							else if(request_all_from_button[8]|request_all_from_button[1]|request_all_from_button[0]){
								//printf("triggered : %d",request_all_from_button[8]|request_all_from_button[1]|request_all_from_button[0]);
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
							}
							else if(request_all_from_button[9]|request_all_from_button[10]|request_all_from_button[11]|request_all_from_button[2]|request_all_from_button[3]){
								L_elevator_up(L_floor);//elevator send go up;
								save_request(L_floor);//save the requests;
							}
							
							else{
								L_nothing();
								save_request(L_floor);
							}
							
								break;
							case 1:
								if(request_all_from_button[12]){//finished closing
									//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
									ajar = 1;
								}
								else if(ajar == 1 &&(!request_all_from_button[12])){
									ajar = 0;
									L_elevator_opened();
								}
									save_request(L_floor);//save the requests;
								break;
							case 2:
								if(time_counter>5000){
									L_elevator_closing();//drive door close
									//change L_state to closing;(reset time_counter = -1)
								}
									save_request(L_floor);//save the requests;
								break;
							case 3:
								if(request_all_from_button[12]){//finished closing
									//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
									ajar = 1;
								}
								else if(ajar == 1 &&(!request_all_from_button[12])){
									ajar = 0;
									L_elevator_closed();
								}
									save_request(L_floor);//save the requests;
								break;
						}
					}
				break;
			case 4: //2nd floor
				//printf("in floor 2\t");
				if(request_all_from_button[13]){
					if(L_Direction == 1){
						L_floor = 1.5; 
					}
					else if(L_Direction == 0){
						L_floor = 2.5;
					}
				}
				else{
					switch (L_state)
					{
					//need also to deal with others floor's request eg.P0.16,/*P0.17,P0.18*/,P0.19(8,/*9,10*/,11)
					//and the floor request from user eg P0.9,/*P0.10*/,P0.11(1,/*2*/,3)
						case 0:
							if(request_all_from_button[9]&request_all_from_button[10]&request_all_from_button[2]){
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
							}
							else if(request_all_from_button[9]|request_all_from_button[10]|request_all_from_button[2]|request_all_from_button[0]){
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
								L_nothing();
							}
							//user inside decide the direction first??
							//request from the user inside the elevator
							else if(request_all_from_button[1]|request_all_from_button[3]){
								//have to deal the which the direction should go first
								if(L_Direction == -1){		//currently the elevator is not moving
									if(request_all_from_button[3]){
										L_elevator_up(L_floor);
									}//elevator send go up;
									else if(request_all_from_button[1]){
										L_elevator_down(L_floor);
									}
									save_request(L_floor);//save the requests;
								}
								else if(L_Direction == 0){	//5ms delay //the elevator is moving up
									if(time_counter == -1){
										L_wait5ms();
									}
									if(time_counter>5){
										L_elevator_up(L_floor);
										save_request(L_floor);
										time_counter = -1;
									}
								}
								else if(L_Direction == 1){	//5ms delay //the elevator is moving down
									if(time_counter == -1){
										L_wait5ms();
									}
									if(time_counter>5){
										L_elevator_down(L_floor);
										save_request(L_floor);
										time_counter = -1;
									}
								}
								
							}
							else if(request_all_from_button[8]|request_all_from_button[11]){
								if(L_Direction == -1){
									if(request_all_from_button[8]){
										L_elevator_down(L_floor);
										save_request(L_floor);
									}
									else if(request_all_from_button[11]){
										L_elevator_up(L_floor);
										save_request(L_floor);
									}
								}
								else if(L_Direction == 0){
									L_elevator_up(L_floor);
									save_request(L_floor);
								}
								else if(L_Direction == 1){
									L_elevator_down(L_floor);
									save_request(L_floor);
								}
							}
							
							else{
								L_nothing();
								save_request(L_floor);
							}
							
							break;
						case 1:
							if(request_all_from_button[12]){//finished closing
								//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
								ajar = 1;
							}
							else if(ajar == 1 &&(!request_all_from_button[12])){
								ajar = 0;
								L_elevator_opened();
							}
								save_request(L_floor);//save the requests;
							break;
						case 2:
							if(time_counter>5000){
								L_elevator_closing();//drive door close
								//change L_state to closing;(reset time_counter = -1)
							}
							//printf("%d",time_counter);
							save_request(L_floor);//save the requests;
							break;
						case 3:
							if(request_all_from_button[12]){//finished closing
								//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
								ajar = 1;
							}
							else if(ajar == 1 &&(!request_all_from_button[12])){
								ajar = 0;
								L_elevator_closed();
							}
								save_request(L_floor);//save the requests;
							break;
					}
				}
				break;
			case 6:
				//printf("In floor 3\t");
				if(request_all_from_button[13]){
					if(L_Direction == 1){
						L_floor = 2.5; 
					}
				}
				else{
					switch (L_state)
					{
					//need also to deal with others floor's request eg.P0.16,P0.17,P0.18,/*P0.19*/(8,9,10,/*11*/)
					//and the floor request from user eg P0.9,P0.10,/*P0.11*/(1,2,/*3*/)
						case 0:
							if(request_all_from_button[11]&request_all_from_button[3]){
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
							}
							else if(request_all_from_button[11]|request_all_from_button[3]|request_all_from_button[0]){
								L_elevator_opening();//drive to open the door;(also change L_state)
								save_request(L_floor);//save the requests;
							}
							else if(request_all_from_button[9]|request_all_from_button[10]|request_all_from_button[8]|request_all_from_button[2]|request_all_from_button[1]){
								L_elevator_down(L_floor);//elevator send go up;
								save_request(L_floor);//save the requests;
							}
							
							else{
								L_nothing();
								save_request(L_floor);
							}
							
							break;
						case 1:
							if(request_all_from_button[12]){//finished closing
								//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
								ajar = 1;
							}
							else if(ajar == 1 &&(!request_all_from_button[12])){
								ajar = 0;
								L_elevator_opened();
							}
								save_request(L_floor);//save the requests;
							break;
						case 2:
							if(time_counter>5000){
								L_elevator_closing();//drive door close
								//change L_state to closing;(reset time_counter = -1)
							}
								save_request(L_floor);//save the requests;
							break;
						case 3:
							if(request_all_from_button[12]){//finished closing
								//L_elevator_opened();//change L_state to opened;(do time_counter also by assign 0)
								ajar = 1;
							}
							else if(ajar == 1 &&(!request_all_from_button[12])){
								ajar = 0;
								L_elevator_closed();
							}
								save_request(L_floor);//save the requests;
							break;
					}
				}
				break;
			case 3: //floor 1.5
				if(request_all_from_button[13]==0){
					//printf("bye%d\n",request_all_from_button[13]);
					if(L_Direction == 1){
						L_floor = 1;
					}
					else if(L_Direction == 0){
						L_floor = 2;
					}
					IOCLR1 = (3<<28);
				}
				else{
					save_request(L_floor);
				}
				break;
			case 5:	//floor 2.5
				if(request_all_from_button[13]==0){
					if(L_Direction == 1){
						L_floor = 2;
					}
					else if(L_Direction == 0){
						L_floor = 3;
					}
					IOCLR1 = (3<<28);
				}
				else{
					save_request(L_floor);
				}
				break;
		default:
			printf("no");
  		}
		
		IOCLR1 = clear;
		for(i = 0; i<12;i++){
			IOSET1 = request_all_from_button[i]<<(i+16);
		}
		
		//printf("\n");
		//printf("\nstate:%d\tfloor:%f\tdirection:%d\n",L_state,L_floor,L_Direction);
		//finish_button = 0;
		
	}
/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
int main (void)  {                             /* main entry for program      */
                                      /* index for command buffer    */
                                   /* index for circular buffer   */
	int i;
	int m_L_state;
	int m_L_Direction;
	float m_L_floor;

	IODIR1  = 	0xFFFF0000;                          /* P1.16..23 defined as Outputs*/
	IODIR0  = 	0x00000000;                                	//how to define input for port 0
	
  	init_serial ();                              /* initialite serial interface */

  	/* setup the timer counter 0 interrupt */
  	T0MR0 = 14999;                               /* 1mSec = 15.000-1 counts     */
  	T0MCR = 3;                                   /* Interrupt and Reset on MR0  */
  	T0TCR = 1;                                   /* Timer0 Enable               */
  	VICVectAddr0 = (unsigned long)tc0;           /* set interrupt vector in 0   */
  	VICVectCntl0 = 0x20 | 4;                     /* use it for Timer 0 Interrupt*/
  	VICIntEnable = 0x00000010;                   /* Enable Timer0 Interrupt     */
  	VICDefVectAddr = (unsigned long) DefISR;     /* un-assigned VIC interrupts  */
	for(i=0 ; i<16;i++){
		continous_time_button[i] = 0;
		button_on[i] = 0;
		off_timer[i] = 0;
	}
	ajar = 0;
	L_Direction = -1;
	m_L_state = 0;
	m_L_Direction = 0;
	m_L_floor = 0;
	while(1){
		if((m_L_state!=L_state)||(m_L_Direction!=L_Direction)||(m_L_floor!=L_floor)){
			printf("floor:%f\t",L_floor);
			if(L_state == 0){
				printf("full closed\t");
			}
			else if(L_state == 1){
				printf("opening\t\t");
			}
			else if(L_state == 2){
				printf("full opened\t");
			}
			else if(L_state == 3){
				printf("closing\t\t");
			}
			
			if(L_Direction == 1){
				printf("down\n");
			}
			else if(L_Direction == 0){
				printf("up\n");
			}
			else if(L_Direction == -1){
				printf("not moving\n");
			}
			m_L_floor = L_floor;
			m_L_state = L_state;
			m_L_Direction = L_Direction;
			//printf("%d\t%f\t%d\n",L_state,L_floor,L_Direction);
		}
		/*
		printf("%d\t%f\t%d\n",L_state,L_floor,L_Direction);
		*/
		/*for(i=0 ; i<16;i++){
			printf("%d:%d \n",i,request_all_from_button[i]);
		}*/
	}
}
