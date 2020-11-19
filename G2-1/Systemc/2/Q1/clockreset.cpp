/***********************************************************************
 * Filename : clockreset.cpp
 * Author: Paul Stynen
 *
 * Copyright (c) 1996-2003
 * CoWare, Inc.
 * 2121 North First St.
 * San Jose, CA 95131
 * USA
 *
 * Purpose: clock + reset generator
 ***********************************************************************/
#include "clockreset.h"

void Clock::do_it()
{
  clk = clk_intern;
}

void Reset::do_it()
{
//  rst = 1;
//  wait(15, SC_NS);
  rst = 0;
  wait(ticks - 15, SC_NS);
  rst = 1;
  // process suspends forever
}
