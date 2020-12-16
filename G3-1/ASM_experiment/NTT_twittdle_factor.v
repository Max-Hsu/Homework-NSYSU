module twiddle_factor_table(len)
input [5:0] len;
reg [5:0] pre_value = 4;
//twiddle factor table
reg [63:0] ntt_twiddle_table [63:0][63:0];
						//make first index 0-63 , index two
//for loop to clean first index to 0 
endmodule
module rst_counter(clk,len,rst,pre_value,counter_x , counter_y)
	
	parameter [63:0] p = 4179340454199820289;
	parameter [63:0] omega = 68630377364883;
	parameter [63:0] m = 57;
	reg [9:0] counter_x;
	reg [9:0] counter_y;
	reg [9:0] iterator;
	reg [9:0] current_process;
	reg set_enable;
	always @(*)
	begin
		if (current_process == pre_value)
		begin
			pre_value = iterator;
			set_enable = 0;
		end
		else if (current_process > pre_value)
		begin
			set_enable = 1;
		end
		else
		begin
			
		end
	end
	always @(*)
	begin
		if (len > iterator)
		begin
			iterator = len;
			current_process = len;
		end
	end
	always @(*)
	begin
		if (counter_y == 0)
		begin
			sliced_ntt_twiddle_table[counter_x][counter_y] <= 0;
		end
		else if(counter_y == 1)
		begin
			//special modexp not yet implemented
		end
		else
		begin
			//two case if iterator is bigger than current_process , use half of the previous value (bigger one)
			/*
				for method 1 , how to acquire another slice?
			*/

			//second case ,  the modmul fuction not yet implemented
		end
	end
endmodule
module set_counter(input set_enable , 
		input rst , 
		input [5:0] iterator ,
		input [5:0] current_process ,
		output reg [9:0] counter_x , 
		output reg [9:0] counter_y ,
		input [9:0] len)

	always @(posedge clk)
	begin
		if(rst)
		begin
			counter_x <= 0;
			counter_y <= 0;
		end
		else if(set_enable)
		begin
			counter_y <= counter_y +1 ;
			if (counter_y > len)
			begin
				counter_x <= counter_x + 1;
				counter_y <= 0;
			end
			if(counter_x > len)
			begin
				counter_x <= 0;
				counter_y <= 0;
				current_process <= current_process - 1;
			end
		end
	end
endmodule

module  modexp(a , exp ,modulus ,clk, result)
	input [63:0] a;
	input [63:0] exp;
	input [63:0] modulus;
	input clk;
	output [63:0] result;
	wire [127:0] base;
	reg [63:0] b_part;
	modmul umodmul(.clk(clk),
		      	.a(a),
			.b(b_part),
			.modulus(modulus),
			.result(result))
	
	assign base = a % modulus;
	always @(posedge clk)	
	begin
		if(exp >0)
		begin
			if(exp & 1)
			begin
				
		exp = exp >>1;
	end
endmodule

module  modmul(a,b,modulus,result,clk)
	input [63:0] a;
	input [63:0] b;
	input [63:0] modulus;
	input clk;
	output reg [63:0] result = 64'b0;
	always @(posedge clk)
	begin
		result <= ({64'b0,a}*{64'b0,b}) % {64'b0,modmodulus};
		//*!!!well watch out for % will make a be circuit , if the circuit is too big
		//*try to use a loop to reach the multiply value and subtract it.////////////////////////
	end
endmodule