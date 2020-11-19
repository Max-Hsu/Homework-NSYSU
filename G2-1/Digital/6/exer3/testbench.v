`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:13:23 10/14/2019
// Design Name:   vera
// Module Name:   C:/Users/Max-Hsu/Desktop/homework/G2-1/Digital/6/exer3/testbench.v
// Project Name:  exer3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: vera
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
	reg z;

	// Outputs
	wire f7;
	wire f8;
	wire f9;

	// Instantiate the Unit Under Test (UUT)
	vera uut (
		.f7(f7), 
		.f8(f8), 
		.f9(f9), 
		.x(x), 
		.y(y), 
		.z(z)
	);

	initial begin
		// Initialize Inputs
		x = 0;
		y = 0;
		z = 0;
		#100;
		x = 0;
		y = 0;
		z = 1;
		#100;
		x = 0;
		y = 1;
		z = 0;
		#100;
		x = 0;
		y = 1;
		z = 1;
		#100;
		x = 1;
		y = 0;
		z = 0;
		#100;
		x = 1;
		y = 0;
		z = 1;
		#100;
		x = 1;
		y = 1;
		z = 0;
		#100;
		x = 1;
		y = 1;
		z = 1;
		#100;	
		// Add stimulus here

	end
      
endmodule

