`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:46:12 10/07/2019 
// Design Name: 
// Module Name:    modu 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module modu(output F1,output F2,output F3,input w,input x,input y,input z);
	wire not_w;
	wire not_x;
	wire not_y;
	wire not_z;
	
	not(not_w,w);
	not(not_x,x);
	not(not_y,y);
	not(not_z,z);
	
	wire F1_A,F1_B,F1_C,F1_D;
	and(F1_A,w,not_x,not_y);
	and(F1_B,w,x,z);
	and(F1_C,not_w,x,y);
	and(F1_D,not_w,y,not_z);
	
	or(F1,F1_A,F1_B,F1_C,F1_D);
	
	wire F2_A,F2_B,F2_C,F2_D;
	and(F2_A,not_w,y,not_z);
	and(F2_B,x,y,z);
	and(F2_C,w,not_y,z);
	and(F2_D,w,not_x,not_y);
	
	or(F2,F2_A,F2_B,F2_C,F2_D);
	
	wire F3_A,F3_B,F3_C,F3_D,F3_E,F3_F;
	and(F3_A,w,not_x,not_y);
	and(F3_B,w,not_y,z);
	and(F3_C,w,x,z);
	and(F3_D,x,y,z);
	and(F3_E,not_w,x,y);
	and(F3_F,not_w,y,not_z);

	or(F3,F3_A,F3_B,F3_C,F3_D,F3_E,F3_F);
endmodule
