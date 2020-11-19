`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:53:51 09/29/2019
// Design Name:   veriloga
// Module Name:   C:/Users/Max-Hsu/Desktop/homework/G2-1/Digital/4/exer1/testbench.v
// Project Name:  exer1
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
	reg w;
	reg x;
	reg y;
	reg z;
	reg u,i,o,p;
	// Outputs
	wire F1;
	wire F2;

	// Instantiate the Unit Under Test (UUT)
	veriloga uut (
		.F1(F1), 
		.F2(F2), 
		.w(w), 
		.x(x), 
		.y(y), 
		.z(z)
	);

	initial begin
		// Initialize Inputs
		
      for (u = 0 ;u <= 1 ;u=u+1)begin
			for (i = 0 ;i<= 1; i=i+1)begin
				for(o = 0; o <= 1 ;o=o+1)begin
					for(p = 0 ;p <= 1 ;p= p+1)begin
						w=u;
						x=i;
						y=o;
						z=p;
						#50;
					end
				end
			end
		end
		/*
		
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
		*/
	end
      
endmodule

