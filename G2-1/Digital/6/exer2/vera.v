`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:40:14 10/14/2019 
// Design Name: 
// Module Name:    vera 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module vera(output f4 , output f5 ,output f6 ,input x ,input y , input z);
	wire not_x,not_y,not_z;
	not(not_x,x);
	not(not_y,y);
	not(not_z,z);
	
	wire f4a,f4b;
	and(f4a,x,not_y);
	and(f4b,not_x,y);
	or(f4,f4a,f4b,z);
	
	wire f5a,f5b;
	nand(f5a,not_x,y);
	nand(f5b,x,not_y);
	nand(f5,f5a,f5b,not_z);
	
	wire f6a,f6b,f6c;
	or(f6a,x,not_y);
	or(f6b,not_x,y);
	and(f6c,f6a,f6b,not_z);
	not(f6,f6c);


endmodule
