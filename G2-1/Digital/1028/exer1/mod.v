`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:07:03 10/28/2019 
// Design Name: 
// Module Name:    mod 
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

module mod_4(output [3:0]Sum , output C4 , input [3:0]A,input [3:0] B ,input C0);
	wire C1,C2,C3;
	wire P0,G0,P0C0;
	xor(P0,A[0],B[0]);
	and(G0,A[0],B[0]);
	and(P0C0,C0,P0);
	or(C1,P0C0,G0);
	
	wire G1,P1,P1G0,P1P0C0;
	and(G1,A[1],B[1]);
	xor(P1,A[1],B[1]);
	and(P1G0,P1,G0);
	and(P1P0C0,P1,P0,C0);
	or(C2,G1,P1G0,P1P0C0);
	
	wire G2,P2,P2G1,P2P1G0,P2P1P0C0;
	and(G2,A[2],B[2]);
	xor(P2,A[2],B[2]);
	and(P2G1,P2,G1);
	and(P2P1G0,P2,P1,G0);
	and(P2P1P0C0,P2,P1,P0,C0);
	or(C3,G2,P2G1,P2P1G0,P2P1P0C0);
	
	wire G3,P3,P3G2,P3P2G1,P3P2P1G0,P3P2P1P0C0;
	and(G3,A[3],B[3]);
	xor(P3,A[3],B[3]);
	and(P3G2,P3,G2);
	and(P3P2G1,P3,P2,G1);
	and(P3P2P1G0,P3,P2,P1,G0);
	and(P3P2P1P0C0,P3,P2,P1,P0,C0);
	or(C4,G3,P3G2,P3P2G1,P3P2P1G0,P3P2P1P0C0);
	
	xor(Sum[0],P0,C0);
	xor(Sum[1],P1,C1);
	xor(Sum[2],P2,C2);
	xor(Sum[3],P3,C3);
	
endmodule


module mod_8(output [7:0]Sum , output C8 , input [7:0]A,input [7:0]B ,input C0);
	wire C4;
	mod_4 low(Sum[3:0],C4,A[3:0],B[3:0],C0);
	mod_4 high(Sum[7:4],C8,A[7:4],B[7:4],C4);

endmodule
