`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:56:48 10/28/2019 
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

module mod(input [3:0]A0,input [3:0]A1,input [3:0]B0 ,input [3:0]B1,output [3:0]C0,output [3:0]C1,output C2,input P0);
	wire add0;
	wire add1;
	wire add2;
	wire add3;
	wire CA0;
	wire ca0,ca1,or1;
	wire ca2,ca3,or2;
	wire [3:0]CX;
	wire [3:0]CY;
	wire [3:0]Low_6;
	wire [3:0]High_6;
	mod_4 low(CX,add0,A0,B0,P0);
	assign ca0 = CX[3]&CX[1];
	assign ca1 = CX[3]&CX[2];
	assign or1 = add0|ca0|ca1;
	assign Low_6 = {1'b0,or1,or1,1'b0};
	mod_4 low_x(C0,add1,CX,Low_6,P0);
	assign CA0=add0|add1;
	
	mod_4 high(CY,add2,A1,B1,CA0);
	assign ca2 = CY[3]&CY[1];
	assign ca3 = CY[3]&CY[2];
	assign or2 = add2|ca2|ca3;
	assign High_6 = {1'b0,or2,or2,1'b0};
	mod_4 high_x(C1,add3,CY,High_6,P0);
	assign C2 = add2|add3;
	
	
endmodule
