// Verilog test fixture created from schematic C:\Users\Max-Hsu\Desktop\homework\G2-1\Digital\test1\asch.sch - Sun Sep 22 17:18:31 2019

`timescale 1ns / 1ps

module asch_asch_sch_tb();

// Inputs
   reg I1;
   reg I2;

// Output
   wire O1;

// Bidirs

// Instantiate the UUT
   asch UUT (
		.I1(I1), 
		.I2(I2), 
		.O1(O1)
   );
// Initialize Inputs

   initial begin
		I1 = 0;
		I2 = 0;
		#100;
		
		I1 = 1;
		I2 = 0;
		#100;
		
		I1 = 0;
		I2 = 1;
		#100;
		
		I1 = 1;
		I2 = 1;
		#100;
	end	
endmodule
