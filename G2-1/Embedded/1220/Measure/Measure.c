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
	int  x=1000000;
  for (d = 0; d < x; d++);           /* only to delay for LED flashes */
}

int main (void) {
  unsigned int i;                          /* LED var */

  IODIR1 = 0x00FF0000;                     /* P1.16..23 defined as Outputs */

  while (1)  {                             /* Loop forever */
    for (i = 1<<16; i < 1<<23; i <<= 1) {  /* Blink LED 0,1,2,3,4,5,6 */
      IOSET1 = i;                          /* Turn on LED */
      wait ();                             /* call wait function */
      IOCLR1 = i;                          /* Turn off LED */
    }
    for (i = 1<<23; i > 1<<16; i >>=1 ) {  /* Blink LED 7,6,5,4,3,2,1 */
      IOSET1 = i;                          /* Turn on LED */
      wait ();                             /* call wait function */
      IOCLR1 = i;                          /* Turn off LED */
    }
  }
}
