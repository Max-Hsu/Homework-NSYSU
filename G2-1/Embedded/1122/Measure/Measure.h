/******************************************************************************/
/* MEASURE.H: struct type and extern definitions for MEASURE project          */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

struct clock {                           /* structure of the clock record     */
  unsigned char    hour;                 /* hour                              */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned short   msec;                 /* milliseconds                      */
};

struct mrec  {                           /* structure for measurement records */
  struct   clock   time;                 /* time of measurement               */
  unsigned long   port0;                 /* state of port 0                   */
  unsigned char  analog [4];             /* voltage on analog Pins AD0 .. AD3 */
};

struct interval  {                       /* structure for interval record     */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned short   msec;                 /* milli second                      */
};

/* external functions: */
extern void init_serial (void);          /* initialize serial interface       */
extern int  sendchar (int ch);           /* write character to serial port    */
extern int  getkey (void);               /* read character from serial port   */
extern void getline (char *line, int n);          /* input line               */
extern void measure_display (struct mrec disp);   /* display mrec             */
extern void set_time (char *buffer);              /* set current time         */
extern void set_interval (char *buffer);          /* set interval time        */


//extern char   ERROR [];                  /* ERROR message string              */
//extern struct mrec current;              /* current measurements              */
//extern struct interval setinterval;      /* interval setting values           */
//extern struct interval interval;         /* interval counter                  */
