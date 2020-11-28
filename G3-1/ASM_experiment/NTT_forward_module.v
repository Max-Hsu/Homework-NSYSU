module NTT_forward_Mod(Forward_Poly_in , Forward_Poly_out ,clk);
input reg [63:0] Forward_Poly_in [63:0];
input clk;
reg [63:0] p =4179340454199820289;
output reg [63:0] Forward_Poly_out [63:0];

always @(posedge clk)
