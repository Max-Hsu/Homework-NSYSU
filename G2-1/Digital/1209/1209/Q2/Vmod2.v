`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:00:59 12/02/2019 
// Design Name: 
// Module Name:    mod2 
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
module Q1 (output reg [1:0]state,output reg pin,input x , clock, reset);
	reg [1:0]next_state;
	parameter S0 = 2'b00, S1 = 2'b01 ,S2 = 2'b10 ,S3 = 2'b11;
	always @ (posedge clock, negedge reset) // state transition
		if(state == S3)pin = 1;
		else pin = 0;
	always @ (posedge clock, negedge reset)
		if (reset == 0) state <= S0;
		else 	state <= next_state;
	always @ (state,x) // Form the next state
		case (state)
			S0: 	if (x) next_state = S1;
					else next_state = S0;
			S1: 	if (x) next_state = S2;
					else next_state = S0;
			S2: 	if (x) next_state = S3;
					else next_state = S0;
			S3: 	if (x) next_state = S3;
					else next_state = S0;
		endcase
endmodule


module D_flip_flop_AR_b (Q, D, Clk, rst);
	output Q;
	input D, Clk, rst;
	reg Q;
	
	always @ (posedge Clk, negedge rst)
		if (rst == 0) Q <= 1'b0;
		else Q <= D;
endmodule

module mod1(output Y , input x , input clock ,input reset);
	wire A1,B1;
	and(Y,A1,B1);
	wire proc_A,proc_B;
	wire ApBX,AXp,BpX,BXp,ApB;
	wire nA,nB,nX;
	wire xa,xb;
	not(nA,A1);
	not(nB,B1);
	not(nX,x);
	and(ApBX,nA,B1,x);
	and(AXp,A1,nX);
	and(BpX,nB,x);
	and(BXp,B1,nX);
	and(ApB,B1,nA);
	or(proc_A,ApBX,AXp);
	or(proc_B,BpX,BXp,ApB);
	xor(xa,proc_A,A1);
	xor(xb,proc_B,B1);
	D_flip_flop_AR_b A(A1,xa,clock,reset);
	D_flip_flop_AR_b B(B1,xb,clock,reset);
	

endmodule