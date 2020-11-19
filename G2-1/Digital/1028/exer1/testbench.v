`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:50:28 10/28/2019
// Design Name:   mod_8
// Module Name:   C:/Users/user/Desktop/1028/exer1/testbench.v
// Project Name:  exer1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mod_8
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
	reg [7:0] A;
	reg [7:0] B;
	reg C0;

	// Outputs
	wire [7:0] Sum;
	wire C8;

	// Instantiate the Unit Under Test (UUT)
	mod_8 uut (
		.Sum(Sum), 
		.C8(C8), 
		.A(A), 
		.B(B), 
		.C0(C0)
	);

	initial begin
		// Initialize Inputs
		A = 100;
		B = 200;
		C0 = 0;
		// Wait 100 ns for global reset to finish
		#100;
		A = 10;
		B = 40;
		C0 = 1;
		// Wait 100 ns for global reset to finish
		#100;        
		// Add stimulus here

	end
      
endmodule

