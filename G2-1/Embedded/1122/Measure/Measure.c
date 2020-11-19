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

//#include "measure.h"                     /* global project definition file    */


extern void init_serial (void); 

/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
int main (void)  {                             /* main entry for program      */

	unsigned int val;
	unsigned int crval;
	PINSEL1 = 0x15400000;                        /* Select AIN0..AIN3           */
	IODIR1  = 0xFF0000;                          /* P1.16..23 defined as Outputs*/
	ADCR    = 0x002E0401;                        /* Setup A/D: 10-bit @ 3MHz    */

	init_serial ();                              /* initialite serial interface */
                          /* display command menu        */
	while (1)  {                                 /* loop forever                */
		crval = 0x01000000 | 1;
		ADCR |= crval;                           /* Start A/D Conversion        */
		do {
			val = ADDR;                            /* Read A/D Data Register      */
		} while ((val & 0x80000000) == 0);       /* Wait for end of A/D Convers.*/
		ADCR &= ~crval;                          /* Stop A/D Conversion         */
		val = (val >> 8) & 0xFF;                 /* Extract AIN Value           */
		printf("%d %f\n",val,(float)val*3.3/256);                 /* result of A/D process       */ 
    if((float)val<(float)256/3.3-1){
			IOSET1 = 1<<16;
		}
		else{
			IOCLR1 = 1<<16;
		}
	}
}
