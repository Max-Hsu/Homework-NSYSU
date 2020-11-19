// Verilog test fixture created from schematic C:\Users\Max-Hsu\Desktop\homework\G2-1\Digital\6\exer1\scha.sch - Mon Oct 14 09:38:06 2019

`timescale 1ns / 1ps

module scha_scha_sch_tb();

// Inputs
   reg w;
   reg y;
   reg x;
   reg z;

// Output
   wire f1;
   wire f2;
   wire f3;

// Bidirs

// Instantiate the UUT
   scha UUT (
		.w(w), 
		.y(y), 
		.x(x), 
		.z(z), 
		.f1(f1), 
		.f2(f2), 
		.f3(f3)
   );
// Initialize Inputs
	initial begin
		// Initialize Inputs
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
