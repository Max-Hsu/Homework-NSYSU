`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:03:01 10/14/2019 
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
module vera(output f7 ,output f8 ,output f9 ,input x,input y,input z);

	wire not_x,not_y,not_z;
	not(not_x,x);
	not(not_y,y);
	not(not_z,z);

	wire f7a,f7b;
	or(f7a,x,y,z);
	or(f7b,not_x,not_y,z);
	and(f7,f7a,f7b);
	
	wire f8a,f8b;
	nor(f8a,x,y,z);
	nor(f8b,not_x,not_y,z);
	nor(f8,f8a,f8b);
	
	wire f9a,f9b,f9c;
	and(f9a,not_x,not_y,not_z);
	and(f9b,x,y,not_z);
	or(f9c,f9a,f9b);
	not(f9,f9c);
	
	
endmodule
