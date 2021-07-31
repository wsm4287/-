`timescale 1 ns / 100 ps

`include "lab3_point_calculator.v"

module lab3_top
	#(
		parameter WORD_SIZE 	= 32,
		parameter CLOCK_PERIOD 	= 1,
		parameter TEST_CASE = 68
	)
	(
	);

	reg clk;
	reg rstn;
	reg [2:0] selector;
	reg [WORD_SIZE-1:0] operand1,operand2;

	reg [WORD_SIZE -1:0] data1[0:TEST_CASE - 1];
	reg [WORD_SIZE -1:0] data2[0:TEST_CASE - 1];
	reg [WORD_SIZE -1:0] ans[0:TEST_CASE - 1];
	reg [2:0] sel[0:TEST_CASE - 1];
	reg ans_flag[0:TEST_CASE - 1];

	integer counter;

	wire [WORD_SIZE-1:0] result;
	wire flag,done;	




	point_calculator testing
	(
		.clk(clk),
		.rstn(rstn),
		.selector(selector),
		.operand1(operand1),
		.operand2(operand2),
		.result(result),
		.flag(flag),
		.done(done)
	);

	always @ (*) begin
		#CLOCK_PERIOD clk <= ~clk;
	end

	always @ (posedge clk) begin
		#0.1
		if(done == 1) begin
			if(ans_flag[counter] == 0 && flag == 0)begin
				if(ans[counter] == result) begin
					$display("selector : %b opernad1 : %h operand2 : %h ans : %h your ans : %h <right>",sel[counter],data1[counter],data2[counter],ans[counter],result);
				end
				else begin
					$display("selector : %b opernad1 : %h operand2 : %h ans : %h your ans : %h <wrong>",sel[counter],data1[counter],data2[counter],ans[counter],result);
				end
	
			end
			else if(ans_flag[counter] == 1 && flag == 1)begin
				$display("selector : %b opernad1 : %h operand2 : %h your flag bit is 1 <right>",sel[counter],data1[counter],data2[counter]);
			end
			else if(ans_flag[counter] == 1 && flag == 0)begin
				$display("selector : %b opernad1 : %h operand2 : %h your flag bit is 0 <wrong>",sel[counter],data1[counter],data2[counter]);
			end
			else begin
				$display("selector : %b opernad1 : %h operand2 : %h your flag bit is 1 <wrong>",sel[counter],data1[counter],data2[counter]);
			end
			#0.1
			counter <= counter + 1;
			#0.1
			if(counter == TEST_CASE) begin
				$finish();
			end
		end
	end


	always @ (negedge clk) begin
		selector <= sel[counter];
		operand1 <= data2[counter];
		operand2 <= data1[counter];		
	end



	initial begin
		clk<= 1'b1;
		rstn <=1'b0;
		selector <= 3'b0;
		operand1 <= 'b0;
		operand2 <= 'b0;
		counter <= 0;
	    //test case example
		data1[0] <= 32'b0;
		data2[0] <= 32'b0;
		sel[0] <= 3'b0;
		ans[0] <= 32'b0;
		ans_flag[0] <= 1'b0;

		data1[1] <= 32'h7fffffff;
		data2[1] <= 32'h7fffffff;
		sel[1] <= 3'b0;
		ans[1] <= 32'bz;
		ans_flag[1] <= 1'b1;

		data1[2] <= 32'b0;
		data2[2] <= 32'hfffffffe;
		sel[2] <= 3'b111;
		ans[2] <= 32'b0;
		ans_flag[2] <= 1'b0;

		data1[3] <= 32'b0;
		data2[3] <= 32'h7fffffff;
		sel[3] <= 3'b001;
		ans[3] <= 32'b0;
		ans_flag[3] <= 1'b0;

		data1[4] <= 32'hffffffff;
		data2[4] <= 32'h7fffffff;
		sel[4] <= 3'b0;
		ans[4] <= 32'h7ffffffe;
		ans_flag[4] <= 1'b0;

		data1[5] <= 32'h7fffffff;
		data2[5] <= 32'b0;
		sel[5] <= 3'b010;
		ans[5] <= 32'h46ffffff;
		ans_flag[5] <= 1'b0;

		data1[6] <= 32'h7fffffff;
		data2[6] <= 32'h0001000f;
		sel[6] <= 3'b001;
		ans[6] <= 32'b0;
		ans_flag[6] <= 1'b1;

		data1[7] <= 32'h7fffffff;
		data2[7] <= 32'h0000000f;
		sel[7] <= 3'b001;
		ans[7] <= 32'h00078000;
		ans_flag[7] <= 1'b0;

      data1[8] <= 32'h00001111;
      data2[8] <= 32'h00000001;
      sel[8] <= 3'b000;
      ans[8] <= 32'h00001112;
      ans_flag[8] <= 1'b0;

      data1[9] <= 32'h00001111;
      data2[9] <= 32'h00000001;
      sel[9] <= 3'b000;
      ans[9] <= 32'h00001112;
      ans_flag[9] <= 1'b0;

      data1[10] <= 32'h00011111;
      data2[10] <= 32'h00000010;
      sel[10] <= 3'b000;
      ans[10] <= 32'h00011121;
      ans_flag[10] <= 1'b0;

      data1[11] <= 32'h00011111;
      data2[11] <= 32'h00000001;
      sel[11] <= 3'b000;
      ans[11] <= 32'h00011112;
      ans_flag[11] <= 1'b0;

      data1[12] <= 32'h00081111; // 0000 0000 0000 1000 0001 0001 0001 0001
      data2[12] <= 32'h00000000;
      sel[12] <= 3'b010;
      ans[12] <= 32'h41011110; // 0100 0001 0000 0001 0001 0001 0001 0000
      ans_flag[12] <= 1'b0;

      data1[13] <= 32'h00010000; // 0000 0000 0000 0001 0000 0000 0000 0000
      data2[13] <= 32'h00000000;
      sel[13] <= 3'b010;
      ans[13] <= 32'h3F800000; //0011 1111 1 000 0000 0000 0000 0000 0000
      ans_flag[13] <= 1'b0;

      data1[14] <= 32'h00001111;
      data2[14] <= 32'h00000001;
      sel[14] <= 3'b000;
      ans[14] <= 32'h00001112;
      ans_flag[14] <= 1'b0;

      data1[15] <= 32'h00001111;
      data2[15] <= 32'h00000001;
      sel[15] <= 3'b000;
      ans[15] <= 32'h00001112;
      ans_flag[15] <= 1'b0;

      data1[16] <= 32'h00001111;
      data2[16] <= 32'h00000001;
      sel[16] <= 3'b000;
      ans[16] <= 32'h00001112;
      ans_flag[16] <= 1'b0;

      data1[17] <= 32'h00001111;
      data2[17] <= 32'h00000001;
      sel[17] <= 3'b000;
      ans[17] <= 32'h00001112;
      ans_flag[17] <= 1'b0;

      data1[18] <= 32'h00011111;  // 0000 0000 0000 0001 . 0001 0001 0001 0001
      data2[18] <= 32'h00000000;  // 0/011 1111 1/000 1000 1000 1000 0000 0000
      sel[18] <= 3'b010;
      ans[18] <= 32'h03F888880;
      ans_flag[18] <= 1'b0;

      data1[19] <= 32'h00010000;   //0011 1111 1000
      data2[19] <= 32'h00000000;
      sel[19] <= 3'b010;
      ans[19] <= 32'h3F800000;
      ans_flag[19] <= 1'b0;

      data1[20] <= 32'h44EB0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000
      data2[20] <= 32'h43D40000;   //0100 0011 1 101 0100 0000 0000 0000 0000
      sel[20] <= 3'b100;
      ans[20] <= 32'h45100000;
      ans_flag[20] <= 1'b0;

      data1[21] <= 32'h44EB0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[21] <= 32'hC3D40000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[21] <= 3'b100;
      ans[21] <= 32'h44B60000;
      ans_flag[21] <= 1'b0;


      data1[22] <= 32'hC4EB0000;   //1 100 0100 1 110 1011 0000 0000 0000 0000
      data2[22] <= 32'h43D40000;   //0100 0011 1 101 0100 0000 0000 0000 0000
      sel[22] <= 3'b100;
      ans[22] <= 32'hC4B60000;
      ans_flag[22] <= 1'b0;

      data1[23] <= 32'h44EB0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000
      data2[23] <= 32'hC3D40000;   //1100 0011 1 101 0100 0000 0000 0000 0000
      sel[23] <= 3'b100;
      ans[23] <= 32'h44B60000;
      ans_flag[23] <= 1'b0;

      data1[24] <= 32'h44C00000;   //0 100 0100 1 100 0000 0000 0000 0000 0000
      data2[24] <= 32'h43800000;   //0 100 0011 1 000 0000 0000 0000 0000 0000
      sel[24] <= 3'b101;
      ans[24] <= 32'h48C00000;  //0 100 1000 1 100 0000 0000 0000 0000
      ans_flag[24] <= 1'b0;

      data1[25] <= 32'h43F88888; // 0 100 0011 1 111 1000 1000 1000 1000 1000 
      data2[25] <= 32'h00000000; 
      sel[25] <= 3'b110;
      ans[25] <= 32'h01F11110;
      ans_flag[25] <= 1'b0;


      data1[26] <= 32'h80000001;   //10000000000000000000000000000001
      data2[26] <= 32'h0000000f;   //00000000000000000000000000001111
      sel[26] <= 3'b0;            
      ans[26] <= 32'h80000010;      //10000000000000000000000000010000
      ans_flag[26] <= 1'b0;
      
      data1[27] <= 32'hffffffff;   //1111 1111 1111 1111 1111 1111 1111 1111 -2^-16
      data2[27] <= 32'hffffffff;  //1111 1111 1111 1111 1111 1111 1111 1111 -2^-16
      sel[27] <= 3'b1;            
      ans[27] <= 32'h00000000;      // 2^-32 =0
      ans_flag[27] <= 1'b0;
      
      data1[28] <= 32'h00008000;   //0000 0000 0000 0000 1000 0000 0000 0000 1/2
      data2[28] <= 32'h00002000;   //0000 0000 0000 0000 0010 0000 0000 0000 1/8
      sel[28] <= 3'b1;            
      ans[28] <= 32'h00001000;      //0000 0000 0000 0000 0001 0000 0000 0000 1/16
      ans_flag[28] <= 1'b0;
      
      data1[29] <= 32'h0;   //0
      data2[29] <= 32'h40002000;   //01000000000000000010000000000000
      sel[29] <= 3'b1;            
      ans[29] <= 32'h0;      //0
      ans_flag[29] <= 1'b0;
       
      data1[30] <= 32'he000203f;   //1110 0000 0000 0000 0010 0000 0011 1111    -8191.8740386962890625
      data2[30] <= 32'h00000004;   //0000 0000 0000 0000 0000 0000 0000 0100   2^-14
      sel[30] <= 3'b1;            
      ans[30] <= 32'hffff8001;      //1111 1111 1111 1111 1000 0000 0000 0001   -0.4999847412109375 
      ans_flag[30] <= 1'b0;         //
      
      data1[31] <= 32'h40000000;   //0100 0000 0000 0000 0000 0000 0000 0000 2^30
      data2[31] <= 32'hfffe0000;   //1111 1111 1111 1110 0000 0000 0000 0000 -2
      sel[31] <= 3'b1;            
      ans[31] <= 32'h80000000;      //10000000000000000000000000000000 -2^31
      ans_flag[31] <= 1'b0;
      
      data1[32] <= 32'he0ff0104;   //1110 0000 1111 1111 0000 0001 0000 0100
      data2[32] <= 32'h3df21f5e;   //0011 1101 1111 0010 0001 1111 0101 1110
      sel[32] <= 3'b1;            
      ans[32] <= 32'hz;      //overflow
      ans_flag[32] <= 1'b1;

      data1[33] <= 32'h0193f2e3;   //0000 0001 1001 0011 1111 0010 1110 0011     403.9487762451171875
      data2[33] <= 32'hfedc102f;   //1111 1110 1101 1100 0001 0000 0010 1111           -291.9367828369140625
      sel[33] <= 3'b1;            
      ans[33] <= 32'hz;      //   overflow;
      ans_flag[33] <= 1'b1;

      data1[34] <= 32'h00400000;   //0000 0000 0100 0000 0000 0000 0000 0000   64
      data2[34] <= 32'h00001000;   //0000 0000 0000 0000 0001 0000 0000 0000   1/16           
      sel[34] <= 3'b1;            
      ans[34] <= 32'h00040000;      //   0000 0000 0000 0100 0000 0000 000 0000    4
      ans_flag[34] <= 1'b0;

      data1[35] <= 32'h5;      //5 3
      data2[35] <= 32'h3;
      sel[35] <= 3'b11;
      ans[35] <= 32'h5;
      ans_flag[35] <= 1'b0;
      
      data1[36] <= 32'hffffffff;      //- +
      data2[36] <= 32'h2;
      sel[36] <= 3'b11;
      ans[36] <= 32'h2;
      ans_flag[36] <= 1'b0;

      data1[37] <= 32'hfffffffe;   //-2 -4
      data2[37] <= 32'hfffffffc;
      sel[37] <= 3'b11;
      ans[37] <= 32'hfffffffe;
      ans_flag[37] <= 1'b0;


      data1[38] <= 32'hF7000001;  
      data2[38] <= 32'h71800600;
      sel[38] <= 3'b100;
      ans[38] <= 32'hF6FFE000;
      ans_flag[38] <= 1'b0;


      data1[39] <= 32'h71800600;  
      data2[39] <= 32'h00000001;
      sel[39] <= 3'b100;
      ans[39] <= 32'h71800600;
      ans_flag[39] <= 1'b0;

      data1[40] <= 32'h71800600;  
      data2[40] <= 32'h80000001;
      sel[40] <= 3'b100;
      ans[40] <= 32'h71800600;
      ans_flag[40] <= 1'b0;

      data1[41] <= 32'h71800600;  
      data2[41] <= 32'hF1800001;
      sel[41] <= 3'b100;
      ans[41] <= 32'h6B3FE000;
      ans_flag[41] <= 1'b0;

      data1[42] <= 32'h71800600;  
      data2[42] <= 32'hF1800001;
      sel[42] <= 3'b101;
      ans[42] <= 32'h72000601;
      ans_flag[42] <= 1'b1;

      data1[43] <= 32'h71800600;  
      data2[43] <= 32'h40000001;
      sel[43] <= 3'b100;
      ans[43] <= 32'h71800600;
      ans_flag[43] <= 1'b0;

      data1[44] <= 32'h0;  
      data2[44] <= 32'hFFFFFFFF;
      sel[44] <= 3'b101;
      ans[44] <= 32'hFFFFFFFF;
      ans_flag[44] <= 1'b0;

      data1[45] <= 32'h70000000;  
      data2[45] <= 32'h7F7FFFFF;
      sel[45] <= 3'b101;
      ans[45] <= 32'hFFFFFFFF;
      ans_flag[45] <= 1'b1;

      data1[46] <= 32'h70000000;  
      data2[46] <= 32'h7F7FFFFF;
      sel[46] <= 3'b100;
      ans[46] <= 32'h7F7FFFFF;
      ans_flag[46] <= 1'b0;

      data1[47] <= 32'hFF000001;  
      data2[47] <= 32'h71800600;
      sel[47] <= 3'b100;
      ans[47] <= 32'hFF000001;
      ans_flag[47] <= 1'b0;

      data1[48] <= 32'h0;  
      data2[48] <= 32'h7F7FFFFF;
      sel[48] <= 3'b101;
      ans[48] <= 32'h0;
      ans_flag[48] <= 1'b0;

      data1[49] <= 32'h31800600;  
      data2[49] <= 32'hFF000001;
      sel[49] <= 3'b101;
      ans[49] <= 32'hF1000601;
      ans_flag[49] <= 1'b0;

      data1[50] <= 32'h71800600;  
      data2[50] <= 32'h00000001;
      sel[50] <= 3'b101;
      ans[50] <= 32'h27000600;
      ans_flag[50] <= 1'b0;

      data1[51] <= 32'h71800600;  
      data2[51] <= 32'h60540001;
      sel[51] <= 3'b101;
      ans[51] <= 32'hF1000601;
      ans_flag[51] <= 1'b1;

      data1[52] <= 32'h31800600;  
      data2[52] <= 32'h00000001;
      sel[52] <= 3'b101;
      ans[52] <= 32'hF1000601;
      ans_flag[52] <= 1'b1;

      data1[53] <= 32'h71800600;  
      data2[53] <= 32'h4D540001;
      sel[53] <= 3'b101;
      ans[53] <= 32'h7F5409F1;
      ans_flag[53] <= 1'b0;

		data1[54] <= 32'h80000000;
		data2[54] <= 32'hffffffff;
		sel[54] <= 3'b0;
		ans[54] <= 32'bz;
		ans_flag[54] <= 1'b1;

		data1[55] <= 32'hffffffff;
		data2[55] <= 32'b0;
		sel[55] <= 3'b010;
		ans[55] <= 32'hB7800000;
		ans_flag[55] <= 1'b0;

		data1[56] <= 32'hfffffffe;
		data2[56] <= 32'b0;
		sel[56] <= 3'b010;
		ans[56] <= 32'hB8000000;
		ans_flag[56] <= 1'b0;

		data1[57] <= 32'hffff0000;
		data2[57] <= 32'b0;
		sel[57] <= 3'b010;
		ans[57] <= 32'hBF800000;
		ans_flag[57] <= 1'b0;

		data1[58] <= 32'hB7800000;
		data2[58] <= 32'b0;
		sel[58] <= 3'b110;
		ans[58] <= 32'hffffffff;
		ans_flag[58] <= 1'b0;

		data1[59] <= 32'hB8000000;
		data2[59] <= 32'b0;
		sel[59] <= 3'b110;
		ans[59] <= 32'hfffffffe;
		ans_flag[59] <= 1'b0;

		data1[60] <= 32'hBF800000;
		data2[60] <= 32'b0;
		sel[60] <= 3'b110;
		ans[60] <= 32'hffff0000;
		ans_flag[60] <= 1'b0;

      data1[61] <= 32'hFF0B0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[61] <= 32'hFF040000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[61] <= 3'b100;
      ans[61] <= 32'h44B60000;
      ans_flag[61] <= 1'b1;

      data1[62] <= 32'h7F0B0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[62] <= 32'hFF040000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[62] <= 3'b100;
      ans[62] <= 32'h7CE00000;
      ans_flag[62] <= 1'b0;

      data1[63] <= 32'h7F0B0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[63] <= 32'h7F040000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[63] <= 3'b100;
      ans[63] <= 32'h7CE00000;
      ans_flag[63] <= 1'b1;


      data1[64] <= 32'h6F0B0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[64] <= 32'h6F040000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[64] <= 3'b100;
      ans[64] <= 32'h6F878000;
      ans_flag[64] <= 1'b0;

      data1[65] <= 32'h6F0B0000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[65] <= 32'h6F040000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[65] <= 3'b100;
      ans[65] <= 32'h6F878000;
      ans_flag[65] <= 1'b0;

      data1[66] <= 32'h3B002000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[66] <= 32'h00840000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[66] <= 3'b101;
      ans[66] <= 32'h00004210;
      ans_flag[66] <= 1'b0;


      data1[67] <= 32'h3F002000;   //0 100 0100 1 110 1011 0000 0000 0000 0000 exp=137
      data2[67] <= 32'h00840000;   //1100 0011 1 101 0100 0000 0000 0000 0000 exp=135
      sel[67] <= 3'b101;
      ans[67] <= 32'h00421080;
      ans_flag[67] <= 1'b0;

	#CLOCK_PERIOD
	#0.1
	rstn <= 1'b1;

	#10000000
	$display("It's too long operation time");
	$finish();
	end


endmodule
