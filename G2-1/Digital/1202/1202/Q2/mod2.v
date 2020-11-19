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
module Q1 (output reg [1:0]state,input x , clock, reset);
	reg [1:0]next_state;
	parameter S0 = 2'b00, S1 = 2'b01 ,S2 = 2'b10 ,S3 = 2'b11;
	always @ (posedge clock, negedge reset) // state transition
		if (reset == 0) state <= S0;
		else state <= next_state;
	always @ (state , x) // Form the next state
		case (state)
			S0: 	if (x) next_state = S0;
					else next_state = S1;
			S1: 	if (x) next_state = S2;
					else next_state = S3;
			S2: 	if (x) next_state = S2;
					else next_state = S3;
			S3: 	if (x) next_state = S3;
					else next_state = S0;
		endcase
endmodule



module JK_flip_flop_A (Q, ORG, D, Clk, rst);
	output Q;
	input D, ORG,Clk, rst;
	reg Q;
	always @ (posedge Clk, negedge rst )
		if (rst == 0) Q <= 1'b0;
		else Q <= (ORG&(~Q))|((~ORG)&Q)|(D&Q);
endmodule

module JK_flip_flop_B (Q, ORG, D, Clk, rst);
	output Q;
	input D, ORG,Clk, rst;
	reg Q;
	always @ (posedge Clk, negedge rst )
		if (rst == 0) Q <= 1'b0;
		else Q <= ((~D)&(~Q))|((~D)&(~ORG)&(Q))|(D&ORG&Q);
endmodule

module mod1(output the_state_a , output the_state_b , input x , input clock ,input reset);
	JK_flip_flop_A A(the_state_a,the_state_b,x,clock,reset);
	JK_flip_flop_B B(the_state_b,the_state_a,x,clock,reset);

endmodule