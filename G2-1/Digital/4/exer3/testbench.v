// Verilog test fixture created from schematic C:\Users\Max-Hsu\Desktop\homework\G2-1\Digital\4\exer3\scha.sch - Mon Sep 30 09:55:38 2019

`timescale 1ns / 1ps

module scha_scha_sch_tb();

// Inputs
   reg w;
   reg x;
   reg y;
   reg z;

// Output
   wire F1;
   wire F2;
   wire F3;

// Bidirs

// Instantiate the UUT
   scha UUT (
		.w(w), 
		.x(x), 
		.y(y), 
		.z(z), 
		.F1(F1), 
		.F2(F2), 
		.F3(F3)
   );
// Initialize Inputs
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
	end
endmodule
