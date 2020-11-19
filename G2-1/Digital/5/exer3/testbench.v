// Verilog test fixture created from schematic C:\Users\Max-Hsu\Desktop\homework\G2-1\Digital\5\exer3\sch.sch - Mon Oct 07 10:28:55 2019

`timescale 1ns / 1ps

module sch_sch_sch_tb();

// Inputs
   reg w;
   reg x;
   reg y;
   reg z;

// Output
   wire y3;
   wire y2;
   wire y1;
   wire y0;

// Bidirs

// Instantiate the UUT
   sch UUT (
		.w(w), 
		.x(x), 
		.y(y), 
		.z(z), 
		.y3(y3), 
		.y2(y2), 
		.y1(y1), 
		.y0(y0)
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
