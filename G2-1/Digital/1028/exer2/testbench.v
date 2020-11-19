`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:18:31 10/28/2019
// Design Name:   mod
// Module Name:   C:/Users/user/Desktop/1028/exer2/testbench.v
// Project Name:  exer2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mod
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
	reg [3:0] A0;
	reg [3:0] A1;
	reg [3:0] B0;
	reg [3:0] B1;
	reg P0;

	// Outputs
	wire [3:0] C0;
	wire [3:0] C1;
	wire C2;

	// Instantiate the Unit Under Test (UUT)
	mod uut (
		.A0(A0), 
		.A1(A1), 
		.B0(B0), 
		.B1(B1), 
		.C0(C0), 
		.C1(C1), 
		.C2(C2), 
		.P0(P0)
	);

	initial begin
		// Initialize Inputs
		A0 = 7;
		A1 = 2;
		B0 = 3;
		B1 = 9;
		P0 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

