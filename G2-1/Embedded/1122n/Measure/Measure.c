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
  #include <LPC21xx.H>                   /* LPC21xx definitions               */
#else
  #include <LPC213x.H>                   /* LPC213x definitions               */
  #define  ADCR    AD0CR
  #define  ADDR    AD0DR
#endif

#include "measure.h"                     /* global project definition file    */

volatile int button_counter = 0;
volatile int continous_time_button = 0;
volatile int button_on = 0;
volatile int off_timer = 0;
volatile int led_cycle = -1;
void wait (int timea)  {                        /* wait function */
  int  d;
  for (d = 0; d < timea*10; d++);           /* only to delay for LED flashes */
}


/* Default Interrupt Function: may be called when timer ISR is disabled */
void DefISR (void) __irq  {
  ;
}

/******************************************************************************/
/*                Timer Counter 0 interrupt service function                  */
/*                executes each 1ms                                           */
/******************************************************************************/
__irq void tc0 (void) {
  unsigned int val;
	val = IOPIN0 & 0x10000;
	led_cycle++;
	if(led_cycle>99){
		led_cycle = 0;
	}
	if(led_cycle<50){
		if(button_counter/2+button_counter%2>led_cycle){
			IOSET1 = 1<<16;
		}
		else{
			IOCLR1 = 1<<16;
		}
	}
	else{
		if(button_counter/2>led_cycle-50){
			IOSET1 = 1<<16;
		}
		else{
			IOCLR1 = 1<<16;
		}
	}
	if(val >0){
		continous_time_button++;
		off_timer = 0;
	}
	else{
		continous_time_button = 0;
		off_timer++;
	}
	if(continous_time_button >=3){
		if(button_on ==0){
			button_on = 1 ;
			if(button_counter<100){
				button_counter++;
			}
		}

	}
	else if(off_timer >= 3){
		button_on = 0 ;
	}
	
  T0IR = 1;                                    /* Clear interrupt flag        */
  VICVectAddr = 0;                             /* Acknowledge Interrupt       */
	
}





/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
int main (void)  {                             /* main entry for program      */
                                      /* index for command buffer    */
  int idx;                                     /* index for circular buffer   */

	IODIR1  = 0xFF0000;                          /* P1.16..23 defined as Outputs*/
	IODIR0 = 0x000000;                                	//how to define input for port 0
	
  init_serial ();                              /* initialite serial interface */

  /* setup the timer counter 0 interrupt */
  T0MR0 = 14999;                               /* 1mSec = 15.000-1 counts     */
  T0MCR = 3;                                   /* Interrupt and Reset on MR0  */
  T0TCR = 1;                                   /* Timer0 Enable               */
  VICVectAddr0 = (unsigned long)tc0;           /* set interrupt vector in 0   */
  VICVectCntl0 = 0x20 | 4;                     /* use it for Timer 0 Interrupt*/
  VICIntEnable = 0x00000010;                   /* Enable Timer0 Interrupt     */
  VICDefVectAddr = (unsigned long) DefISR;     /* un-assigned VIC interrupts  */

																								/* initialize circular buffer  */
	idx = 0;
  while (1)  {                                 /* loop forever                */
		if(idx!=button_counter){
			idx = button_counter;
			printf("%d\n",idx);
		}		
  }
}
