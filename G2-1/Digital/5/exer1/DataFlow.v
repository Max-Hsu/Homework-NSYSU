`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:19:11 10/07/2019 
// Design Name: 
// Module Name:    DataFlow 
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
module DataFlow(output F1 ,output F2,input w,input x,input y ,input z);
	assign F1=((~w)&(~y))|((~w)&(~z))|((x)&(~z))|((w)&(~y)&(~z))|((w)&(~y)&(z));
	assign F2=(~y)|((x)&(~z))|((~w)&(~z));


endmodule
