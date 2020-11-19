`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:32:10 12/02/2019
// Design Name:   mod1
// Module Name:   C:/Users/user/Desktop/1202/Q2/testbenchmod.v
// Project Name:  Q2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mod1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testbenchmod;

	// Inputs
	reg x;
	reg clock;
	reg reset;

	// Outputs
	wire the_state_a;
	wire the_state_b;

	// Instantiate the Unit Under Test (UUT)
	mod1 uut (
		.the_state_a(the_state_a), 
		.the_state_b(the_state_b), 
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

