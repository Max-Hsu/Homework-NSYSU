`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:29:37 12/02/2019
// Design Name:   Q1
// Module Name:   C:/Users/user/Desktop/1202/Q2/testbenchbeha.v
// Project Name:  Q2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Q1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testbenchbeha;

	// Inputs
	reg x;
	reg clock;
	reg reset;

	// Outputs
	wire [1:0] state;

	// Instantiate the Unit Under Test (UUT)
	Q1 uut (
		.state(state), 
		.x(x), 
		.clock(clock), 
		.reset(reset)
	);

	initial #200 $finish;
	initial begin clock = 0;forever #5 clock = ~clock;end
	initial fork
		reset = 0;
		x = 0;
		#3  reset = 1;
		#10 x = 1;
		#30 x = 0;
		#50 x = 1;
	join
      
endmodule

