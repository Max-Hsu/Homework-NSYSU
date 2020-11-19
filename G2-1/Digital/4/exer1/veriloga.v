`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:36:19 09/29/2019 
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
module veriloga(output F1 , output F2 ,input w , input x ,input y ,input z);
	assign F1 = ((~w)&(~x)&(~y)&(z))|((~w)&(~x)&(y)&(~z))|((~w)&(~x)&(y)&(z))|((~w)&(x)&(y)&(~z))|((w)&(~x)&(y)&(z))|((w)&(x)&(~y)&(~z))|((w)&(x)&(y)&(~z))|((w)&(x)&(y)&(z));
	assign F2 = ((w)|(x)|(y)|(z))&((w)|(~x)|(y)|(z))&((w)|(~x)|(y)|(~z))&((w)|(~x)|(~y)|(~z))&((~w)|(x)|(y)|(z))&((~w)|(x)|(y)|(~z))&((~w)|(x)|(~y)|(z))&((~w)|(~x)|(y)|(~z));

endmodule
