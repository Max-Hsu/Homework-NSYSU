/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/user/Desktop/1202/Q1/mod1.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};



static void Always_24_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;

LAB0:    t1 = (t0 + 3280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(24, ng0);
    t2 = (t0 + 3848);
    *((int *)t2) = 1;
    t3 = (t0 + 3312);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(25, ng0);
    t4 = (t0 + 1800U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB8;

LAB5:    if (t18 != 0)
        goto LAB7;

LAB6:    *((unsigned int *)t6) = 1;

LAB8:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 2360);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2200);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);

LAB11:    goto LAB2;

LAB7:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB8;

LAB9:    xsi_set_current_line(25, ng0);
    t28 = ((char*)((ng2)));
    t29 = (t0 + 2200);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 1, 0LL);
    goto LAB11;

}

static void Always_27_1(char *t0)
{
    char t9[8];
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;

LAB0:    t1 = (t0 + 3528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 3864);
    *((int *)t2) = 1;
    t3 = (t0 + 3560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(28, ng0);
    t4 = (t0 + 2200);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB5:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t7, 1);
    if (t8 == 1)
        goto LAB6;

LAB7:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 1, t2, 1);
    if (t8 == 1)
        goto LAB8;

LAB9:
LAB10:    goto LAB2;

LAB6:    xsi_set_current_line(29, ng0);
    t10 = (t0 + 1320U);
    t11 = *((char **)t10);
    t10 = (t0 + 1480U);
    t12 = *((char **)t10);
    t14 = *((unsigned int *)t11);
    t15 = *((unsigned int *)t12);
    t16 = (t14 ^ t15);
    *((unsigned int *)t13) = t16;
    t10 = (t11 + 4);
    t17 = (t12 + 4);
    t18 = (t13 + 4);
    t19 = *((unsigned int *)t10);
    t20 = *((unsigned int *)t17);
    t21 = (t19 | t20);
    *((unsigned int *)t18) = t21;
    t22 = *((unsigned int *)t18);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB11;

LAB12:
LAB13:    memset(t9, 0, 8);
    t26 = (t13 + 4);
    t27 = *((unsigned int *)t26);
    t28 = (~(t27));
    t29 = *((unsigned int *)t13);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB17;

LAB15:    if (*((unsigned int *)t26) == 0)
        goto LAB14;

LAB16:    t32 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t32) = 1;

LAB17:    t33 = (t9 + 4);
    t34 = (t13 + 4);
    t35 = *((unsigned int *)t13);
    t36 = (~(t35));
    *((unsigned int *)t9) = t36;
    *((unsigned int *)t33) = 0;
    if (*((unsigned int *)t34) != 0)
        goto LAB19;

LAB18:    t41 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t41 & 1U);
    t42 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t42 & 1U);
    t43 = (t9 + 4);
    t44 = *((unsigned int *)t43);
    t45 = (~(t44));
    t46 = *((unsigned int *)t9);
    t47 = (t46 & t45);
    t48 = (t47 != 0);
    if (t48 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(30, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB22:    goto LAB10;

LAB8:    xsi_set_current_line(31, ng0);
    t3 = (t0 + 1320U);
    t4 = *((char **)t3);
    t3 = (t0 + 1480U);
    t5 = *((char **)t3);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    *((unsigned int *)t13) = t16;
    t3 = (t4 + 4);
    t7 = (t5 + 4);
    t10 = (t13 + 4);
    t19 = *((unsigned int *)t3);
    t20 = *((unsigned int *)t7);
    t21 = (t19 | t20);
    *((unsigned int *)t10) = t21;
    t22 = *((unsigned int *)t10);
    t23 = (t22 != 0);
    if (t23 == 1)
        goto LAB23;

LAB24:
LAB25:    memset(t9, 0, 8);
    t11 = (t13 + 4);
    t27 = *((unsigned int *)t11);
    t28 = (~(t27));
    t29 = *((unsigned int *)t13);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t11) == 0)
        goto LAB26;

LAB28:    t12 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t12) = 1;

LAB29:    t17 = (t9 + 4);
    t18 = (t13 + 4);
    t35 = *((unsigned int *)t13);
    t36 = (~(t35));
    *((unsigned int *)t9) = t36;
    *((unsigned int *)t17) = 0;
    if (*((unsigned int *)t18) != 0)
        goto LAB31;

LAB30:    t41 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t41 & 1U);
    t42 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t42 & 1U);
    t26 = (t9 + 4);
    t44 = *((unsigned int *)t26);
    t45 = (~(t44));
    t46 = *((unsigned int *)t9);
    t47 = (t46 & t45);
    t48 = (t47 != 0);
    if (t48 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB34:    goto LAB10;

LAB11:    t24 = *((unsigned int *)t13);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t13) = (t24 | t25);
    goto LAB13;

LAB14:    *((unsigned int *)t9) = 1;
    goto LAB17;

LAB19:    t37 = *((unsigned int *)t9);
    t38 = *((unsigned int *)t34);
    *((unsigned int *)t9) = (t37 | t38);
    t39 = *((unsigned int *)t33);
    t40 = *((unsigned int *)t34);
    *((unsigned int *)t33) = (t39 | t40);
    goto LAB18;

LAB20:    xsi_set_current_line(29, ng0);
    t49 = ((char*)((ng2)));
    t50 = (t0 + 2360);
    xsi_vlogvar_assign_value(t50, t49, 0, 0, 1);
    goto LAB22;

LAB23:    t24 = *((unsigned int *)t13);
    t25 = *((unsigned int *)t10);
    *((unsigned int *)t13) = (t24 | t25);
    goto LAB25;

LAB26:    *((unsigned int *)t9) = 1;
    goto LAB29;

LAB31:    t37 = *((unsigned int *)t9);
    t38 = *((unsigned int *)t18);
    *((unsigned int *)t9) = (t37 | t38);
    t39 = *((unsigned int *)t17);
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t17) = (t39 | t40);
    goto LAB30;

LAB32:    xsi_set_current_line(31, ng0);
    t32 = ((char*)((ng3)));
    t33 = (t0 + 2360);
    xsi_vlogvar_assign_value(t33, t32, 0, 0, 1);
    goto LAB34;

}


extern void work_m_00000000000436280675_3225947821_init()
{
	static char *pe[] = {(void *)Always_24_0,(void *)Always_27_1};
	xsi_register_didat("work_m_00000000000436280675_3225947821", "isim/testbench_isim_beh.exe.sim/work/m_00000000000436280675_3225947821.didat");
	xsi_register_executes(pe);
}
