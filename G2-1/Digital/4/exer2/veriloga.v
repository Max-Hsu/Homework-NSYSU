`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:11:33 09/30/2019 
// Design Name: 
// Module Name:    veriloga 
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
module veriloga(output O1,output O2,output O3,output O4,input x,input y ,input z);
	wire O1_A;
	nor(O1_A,x,y);
	nor(O1,O1_A,z);
	
	wire O1_C;
	nor(O1_C,y,x);
	nor(O2,O1_C,z);
	
	wire O2_A;
	nor(O2_A,x,y);
	nor(O3,O2_A,z);
	
	wire O2_C;
	nor(O2_C,y,z);
	nor(O4,O2_C,x);

endmodule
