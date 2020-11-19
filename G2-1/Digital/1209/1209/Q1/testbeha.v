`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:49:45 12/09/2019
// Design Name:   Q1
// Module Name:   C:/Users/user/Desktop/1209/Q1/testbeha.v
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

module testbeha;

	// Inputs
	reg x;
	reg clock;
	reg reset;

	// Outputs
	wire [1:0] state;
	wire pin;

	// Instantiate the Unit Under Test (UUT)
	Q1 uut (
		.state(state), 
		.pin(pin), 
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

