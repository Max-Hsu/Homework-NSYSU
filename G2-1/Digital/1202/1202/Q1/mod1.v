`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:41:04 12/02/2019 
// Design Name: 
// Module Name:    mod1 
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
module Q1 (output reg state,input x , y , clock, reset);
	reg next_state;
	parameter S0 = 1'b0, S1 = 1'b1;
	always @ (posedge clock, negedge reset) // state transition
		if (reset == 0) state <= S0;
		else state <= next_state;
	always @ (x,y,state) // Form the next state
		case (state)
			S0: 	if (~(x^y)) next_state = S0;
					else next_state = S1;
			S1: 	if (~(x^y)) next_state = S1;
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

module mod1(output the_state , input x ,input y , input clock ,input reset);
	wire xor1,xor2;
	xor(xor1,x,y);
	xor(xor2,the_state,xor1);
	D_flip_flop_AR_b D1(the_state,xor2,clock,reset);
	

endmodule
