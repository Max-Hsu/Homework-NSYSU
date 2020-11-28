module get_twiddle_factor()
reg [63:0] p = 4179340454199820289;
reg [63:0] omega = 68630377364883;
reg [63:0] m = 57;

//twiddle factor table
reg [63:0] twiddle_table [63:0][63:0];
twiddle_table[0][0] = 1;		//make first index 0-63 , index two
//for loop to clean first index to 0 