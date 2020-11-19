`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:19:09 12/02/2019
// Design Name:   Q1
// Module Name:   C:/Users/user/Desktop/1202/Q1/testbench.v
// Project Name:  Q1
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

module testbench;

	// Inputs
	reg x;
	reg y;
	reg clock;
	reg reset;

	// Outputs
	wire state;

	// Instantiate the Unit Under Test (UUT)
	Q1 uut (
		.state(state), 
		.x(x), 
		.y(y), 
		.clock(clock), 
		.reset(reset)
	);
	initial #200 $finish;
	initial begin clock = 0;forever #5 clock = ~clock;end
	initial fork
		reset = 0;
		x = 0;
		y = 0;
		#3  reset = 1;
		#10 x = 1;
		#20 y = 1;
		#30 x = 0;
		#40 y = 0;
	join
      
endmodule

