`timescale 1 ns / 100 ps

module test_module_a
	(
		result
	);

	output reg result;

	reg [2:0] data_in;
	wire test_data_out;	
	wire data_out;
	integer i,score;	
	module_a verifya(data_in,data_out);
	module_a_verify test_a(data_in,test_data_out);

	initial begin
	data_in <= 000;
	result <= 0;
	score <= 0;
	for(i=0;i<8;i = i + 1)begin
	    #10
            if (data_out == test_data_out) begin
                    $display("data %b, your answer: %b, correct answer: %b <OK!>", data_in, data_out, test_data_out);
                score = score+1;
            end else begin
                    $display("data %b, your answer: %b, correct answer: %b <Wrong!>", data_in, data_out, test_data_out);
            end
	    #10 data_in<=data_in + 1;
	end
	$display("Total : <%d/8> output is correct", score);
	if(score==8)begin result <= 1; end
	end
endmodule

module test_module_b
	(
		clk,
		rstn,
		result
	);
	input	    clk;
	input       rstn;

	output reg result;
	integer score,i;

	reg [1:0] data_in;
	reg  test_data_out;
	reg [5:0] data;
	wire data_out;
	integer seed;

	module_b verify(clk,rstn,data_in,data_out);
   	initial begin 
		result<=1'b0;
        	if (!$value$plusargs("seed=%d",seed)) begin
            		seed <= 0;
        	end
    	end


	always @ (clk or negedge rstn) begin
		if(!rstn)begin
			data <= 0;		
			test_data_out<=0;
		end else begin
		if(clk)begin
			#0.1
			data[1:0]<=data_in;
			if({data[5:2],data_in} == 6'b011001)begin
				test_data_out <= 1'b1;
			end else begin
				test_data_out <= 1'b0;
			end
		end else begin
			data[5:2] <= data[3:0];			
		end
		end			
	end
    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            score = 0;
            i = 0;
            data_in <= 2'b00;
        end else begin
                data_in <= $random(seed); 
		i <= i + 1;
		#0.1
		if(i>=50) begin
           	 	$display("Total : <%d/50> score", score);
           		// $display("-----------------------------");
	    		if(score == 50)begin result<=1'b1;end
		end
	end
     end
	always @(negedge clk)begin
	if(rstn)begin
            if (data_out == test_data_out) begin
                    $display("data %b, your answer: %b, correct answer: %b <OK!>", data_in, data_out, test_data_out);
                score = score+1;
            end else begin
                    $display("data %b, your answer: %b, correct answer: %b <Wrong!>", data_in, data_out, test_data_out);
            end
	end
	end

endmodule


module test_module_c
	(
		result
	);

	output reg result;

	reg [2:0] data_in;
	wire [1:0] test_data_out;	
	wire [1:0] data_out;
	integer i,score;	
	module_c verifyc(data_in,data_out);
	module_c_verify test_c(data_in,test_data_out);

	initial begin
	data_in <= 000;
	result <= 0;
	score <= 0;
	i <=0;
	#3050
	for(i=0;i<8;i = i + 1)begin
	    #20
            if (data_out == test_data_out) begin
                    $display("data %b, your answer: %b, correct answer: %b <OK!>", data_in, data_out, test_data_out);
                score = score+1;
            end else begin
                    $display("data %b, your answer: %b, correct answer: %b <Wrong!>", data_in, data_out, test_data_out);
            end
	    #20 data_in<=data_in + 1;
	end
	$display("Total : <%d/8> output is correct", score);
	if(score==8)begin result <= 1; end
	end

endmodule

module module_c_verify
    #(
    ) 
        (
            input  [2:0 ] data_in
           ,output [1:0 ] data_out

        );
            wire   [13:0] line;
   
   
    logic_and    and_1   (.data_in_1(data_in[0 ]),.data_in_2(data_in[1 ]),.data_out(line    [0 ]));
    logic_and    and_2   (.data_in_1(data_in[1 ]),.data_in_2(data_in[2 ]),.data_out(line    [1 ]));
    logic_or_2   or_1    (.data_in_1(line   [0 ]),.data_in_2(line   [1 ]),.data_out(line    [2 ]));
    logic_and    and_3   (.data_in_1(data_in[2 ]),.data_in_2(data_in[1 ]),.data_out(line    [3 ]));
    logic_and    and_4   (.data_in_1(data_in[0 ]),.data_in_2(data_in[1 ]),.data_out(line    [4 ]));
    logic_or_2   or_2    (.data_in_1(line   [3 ]),.data_in_2(line   [4 ]),.data_out(line    [5 ]));
    logic_and    and_5   (.data_in_1(line   [2 ]),.data_in_2(line   [5 ]),.data_out(line    [6 ]));
    logic_xor    xor_1   (.data_in_1(data_in[1 ]),.data_in_2(data_in[2 ]),.data_out(line    [7 ]));
    logic_and    and_6   (.data_in_1(line   [6 ]),.data_in_2(line   [7 ]),.data_out(line    [8 ]));
    logic_nand   nand_1  (.data_in_1(data_in[1 ]),.data_in_2(data_in[2 ]),.data_out(line    [9 ]));
    logic_invert invert_1(.data_in  (data_in[0 ]),.data_out (line   [10]));
    logic_nor    nor_1   (.data_in_1(line   [10]),.data_in_2(line   [9 ]),.data_out(line    [11]));
    logic_xor    xor_2   (.data_in_1(line   [8 ]),.data_in_2(line   [11]),.data_out(data_out[0 ]));
    logic_or_2   or_3    (.data_in_1(data_in[1 ]),.data_in_2(data_in[2 ]),.data_out(line    [12]));
    logic_and    and_7   (.data_in_1(data_in[0 ]),.data_in_2(line   [12]),.data_out(line    [13]));
    logic_xor    xor_3   (.data_in_1(line   [7 ]),.data_in_2(line   [13]),.data_out(data_out[1 ]));
 
endmodule

module module_a_verify
    (
         input  [2:0] data_in
        
        ,output      data_out
    );
    //data_in[0]->a, data_in[1]->b, data_in[2]->c
    wire a_and_b;
    wire nota;
   wire nota_and_c;

    logic_and    logic_and_0    (.data_in_1(data_in[0]), .data_in_2(data_in[1]), .data_out(a_and_b   ));
    logic_invert logic_invert_0 (.data_in  (data_in[0]), .data_out (nota      ));
    logic_and    logic_and_1    (.data_in_1(nota      ), .data_in_2(data_in[2]), .data_out(nota_and_c));
    logic_or_2   logic_or_0     (.data_in_1(a_and_b   ), .data_in_2(nota_and_c), .data_out(data_out));
   
endmodule