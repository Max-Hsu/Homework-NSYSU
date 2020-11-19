`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:43:25 09/30/2019
// Design Name:   veriloga
// Module Name:   C:/Users/Max-Hsu/Desktop/homework/G2-1/Digital/4/exer2/testbench.v
// Project Name:  exer2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: veriloga
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
	wire O1;
	wire O2;
	wire O3;
	wire O4;

	// Instantiate the Unit Under Test (UUT)
	veriloga uut (
		.O1(O1), 
		.O2(O2), 
		.O3(O3), 
		.O4(O4), 
		.x(x), 
		.y(y), 
		.z(z)
	);

	initial begin
		// Initialize Inputs
		x = 0;
		y = 0;
		z = 0;
		
		#50;

		x = 0;
		y = 0;
		z = 1;
		
		#50;

		x = 0;
		y = 1;
		z = 0;
		
		#50;

		x = 0;
		y = 1;
		z = 1;
		
		#50;

		x = 1;
		y = 0;
		z = 0;
		
		#50;
		
		x = 1;
		y = 0;
		z = 1;
		
		#50;

		x = 1;
		y = 1;
		z = 0;
		
		#50;

		x = 1;
		y = 1;
		z = 1;
		
		#50;



        
		// Add stimulus here

	end
      
endmodule

