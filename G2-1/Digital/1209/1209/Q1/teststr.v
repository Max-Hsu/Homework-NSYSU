`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:54:10 12/09/2019
// Design Name:   mod1
// Module Name:   C:/Users/user/Desktop/1209/Q1/teststr.v
// Project Name:  Q1
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

module teststr;

	// Inputs
	reg x;
	reg clock;
	reg reset;

	// Outputs
	wire Y;

	// Instantiate the Unit Under Test (UUT)
	mod1 uut (
		.Y(Y), 
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
		#15 x = 0;
		#25 x = 1;
		#35 x = 1;
		#45 x = 1;
		#55 x = 1;
		#65 x = 1;
		#75 x = 0;
		#85 x = 1;
		#95 x = 1;
		#105 x = 0;
		
	join
      
endmodule

