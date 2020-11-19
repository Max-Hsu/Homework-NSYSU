`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:24:21 10/07/2019
// Design Name:   DataFlow
// Module Name:   C:/Users/Max-Hsu/Desktop/homework/G2-1/Digital/5/exer1/testbench.v
// Project Name:  exer1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DataFlow
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
	reg w;
	reg x;
	reg y;
	reg z;

	// Outputs
	wire F1;
	wire F2;

	// Instantiate the Unit Under Test (UUT)
	DataFlow uut (
		.F1(F1), 
		.F2(F2), 
		.w(w), 
		.x(x), 
		.y(y), 
		.z(z)
	);

	initial begin
		w=0;
		x=0;
		y=0;
		z=0;
		#50;
		
		
		w=0;
		x=0;
		y=0;
		z=1;
		#50;
		
		
		w=0;
		x=0;
		y=1;
		z=0;
		#50;
		
		w=0;
		x=0;
		y=1;
		z=1;
		#50;
		
		w=0;
		x=1;
		y=0;
		z=0;
		#50;
		
		w=0;
		x=1;
		y=0;
		z=1;
		#50;
		
		w=0;
		x=1;
		y=1;
		z=0;
		#50;
		
		w=0;
		x=1;
		y=1;
		z=1;
		#50;
		
		w=1;
		x=0;
		y=0;
		z=0;
		#50;
		
		w=1;
		x=0;
		y=0;
		z=1;
		#50;
		
		w=1;
		x=0;
		y=1;
		z=0;
		#50;
		
		w=1;
		x=0;
		y=1;
		z=1;
		#50;
		
		w=1;
		x=1;
		y=0;
		z=0;
		#50;
		
		w=1;
		x=1;
		y=0;
		z=1;
		#50;
		
		w=1;
		x=1;
		y=1;
		z=0;
		#50;
		
		w=1;
		x=1;
		y=1;
		z=1;
		#50;
		// Add stimulus here

	end
      
endmodule

