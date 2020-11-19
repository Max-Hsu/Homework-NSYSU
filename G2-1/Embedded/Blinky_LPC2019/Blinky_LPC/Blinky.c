/******************************************************************************/
/* BLINKY.C: LED Flasher                                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <LPC21xx.H>                       /* LPC21xx definitions */

void wait (void)  {                        /* wait function */
  int  d;

  for (d = 0; d < 1000000; d++);           /* only to delay for LED flashes */
}
void PortInitialize(int port , unsigned long addr){
	if(port == 1){
		IODIR1 = addr; 
	}
}
void Port1_3rdByteSet(char num){
	unsigned long connum;
	int adding;
	IOCLR1 = 255<<16;
	connum = num;
	for (adding=0;adding<16;adding++){
		connum*=2;
	}
	IOSET1 =  connum;
}
int current_step = 0;
char halfmotor[8] = {3,2,6,4,12,8,9,1};
void shiftTo23(char num){
	Port1_3rdByteSet(num<<4);														//shift 4 more bits to the assigned place
}
void fullstep(int direction){
	if(direction){
		current_step-=2;																	//counter clock-wise
	}
	else{
		current_step+=2;																	//clock-wise
	}
	if(current_step<0){																	//offset check
		current_step+=8;
	}
	else if(current_step>7){														//offset check
		current_step-=8;
	}
		shiftTo23(halfmotor[current_step]);								//call the writing function
		wait();
}
void halfstep(int direction){
	if(direction){
		current_step-=1;																	//counter clock-wise
	}
	else{
		current_step+=1;																	//clock-wise
	}
	if(current_step<0){																	//offset check
		current_step+=8;
	}
	else if(current_step>7){														//offset check
		current_step-=8;
	}
		shiftTo23(halfmotor[current_step]);								//call the writing function
		wait();
}
void rotate(int direction , int mode , int number){		//this function deals with numbers of step problem
	int step;
	if(number>0){																				//if the step is more than zero
		if(mode){
			if(current_step%2){															//and if current is the half-step status
				halfstep(direction);													//so first proceed with half-step
				for(step = 0;step<number-1;step++){						//and do the rest of full-step
					fullstep(direction);
				}
			}
			else{
				for(step=0;step<number;step++){								//or do the full-step
					fullstep(direction);
				}
			}
		}
		else{
			for(step=0;step<number;step++){									//half-step don't have to worry about
				halfstep(direction);
			}
		}
	}
	else if(number==-1){																//number = -1 means do the circle forever
		if(mode){																					//same as upon code
			if(current_step%2){
				halfstep(direction);
			}
			else{
				while(1){
					fullstep(direction);
				}
			}
		}
		else{
			while(1){
				halfstep(direction);
			}
		}
	}
	else{
		shiftTo23(halfmotor[current_step]);								//if step = 0 then means no movement
		wait();
	}
}
int main (void) {
	PortInitialize(1,0x00FF0000);
	rotate(1,1,0);//p23-p20 becomes 0011
  rotate(1,1,0);//p23-p20 stays 0011
  rotate(0,0,0);//p23-p20 stays 0011
  rotate(1,1,1);//p23-p20 becomes 1001
  rotate(1,1,1);//p23-p20 becomes 1100
  rotate(0,0,0);//p23-p20 stays 1100
  rotate(1,0,3);//p23-p20 becomes 0100 => 0110 => 0010
  rotate(0,1,3);//p23-p20 becomes 0110 => 1100 => 1001
  rotate(0,0,-1);//p23-p20becomes 0001 => 0011 => 0010 =>
 }
