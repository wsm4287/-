    
`timescale 1 ns / 100 ps

module test_bench
    #(
        parameter WORD_SIZE    = 8
       ,parameter ALU_CON_SIZE = 4
    )
        (
            input                                 clk
           ,input                                 rstn
           ,output reg        [ALU_CON_SIZE-1:0]  alu_con
           ,output     signed [WORD_SIZE-1   :0]  data_in_1
           ,output     signed [WORD_SIZE-1   :0]  data_in_2
           
           ,input      signed [WORD_SIZE-1   :0]  data_out
        );

    localparam ADD = 4'b0010,
               SUB = 4'b0110,
               AND = 4'b0000,
               OR  = 4'b0001,
               NOR = 4'b1111;
    integer i, seed, score;
    real clk_period;
    reg  signed [WORD_SIZE/2-1:0] tmp_data_1;
    reg  signed [WORD_SIZE/2-1:0] tmp_data_2;
    assign data_in_1 = tmp_data_1;
    assign data_in_2 = tmp_data_2;
    initial begin 
        if (!$value$plusargs("seed=%d",seed)) begin
            seed <= 1'b0;
        end
        clk_period = 0.5;
    end

    reg                            test;
    reg         [ALU_CON_SIZE-1:0] test_alu_con;
    reg  signed [WORD_SIZE-1   :0] test_data_1;
    reg  signed [WORD_SIZE-1   :0] test_data_2;
    wire signed [WORD_SIZE-1   :0] test_data_out;
    assign test_data_out = (test_alu_con == ADD) ? test_data_1 + test_data_2:
                           (test_alu_con == SUB) ? test_data_1 - test_data_2:
                           (test_alu_con == AND) ? test_data_1 & test_data_2:
                           (test_alu_con == OR ) ? test_data_1 | test_data_2:
                           (test_alu_con == NOR) ? ~(test_data_1 | test_data_2):
                                                   1'b0;

    always @(posedge clk) begin
        if (test) begin
            if (data_out == test_data_out) begin
                if (test_alu_con == ADD || test_alu_con == SUB) begin
                    $display("data1: %d, data2: %d, your answer: %d, correct answer: %d <OK!>", test_data_1, test_data_2, data_out, test_data_out);
                end else begin
                    $display("data1: %b, data2: %b, your answer: %b, correct answer: %b <OK!>", test_data_1, test_data_2, data_out, test_data_out);
                end
                score = score+1;
            end else begin
                if (test_alu_con == ADD || test_alu_con == SUB) begin
                    $display("data1: %d, data2: %d, your answer: %d, correct answer: %d <Wrong!>", test_data_1, test_data_2, data_out, test_data_out);
                end else begin
                    $display("data1: %b, data2: %b, your answer: %b, correct answer: %b <Wrong!>", test_data_1, test_data_2, data_out, test_data_out);
                end
            end
        end
    end
    
    /*always @(posedge clk) begin
        if (test) begin
            if (data_out == test_data_out) begin
                if (alu_con == ADD || alu_con == SUB) begin
                    $display("data1: %d, data2: %d, your answer: %d, correct answer: %d <OK!>", data_in_1, data_in_2, data_out, test_data_out);
                end else begin
                    $display("data1: %b, data2: %b, your answer: %b, correct answer: %b <OK!>", data_in_1, data_in_2, data_out, test_data_out);
                end
                score = score+1;
            end else begin
                if (alu_con == ADD || alu_con == SUB) begin
                    $display("data1: %d, data2: %d, your answer: %d, correct answer: %d <Wrong!>", data_in_1, data_in_2, data_out, test_data_out);
                end else begin
                    $display("data1: %b, data2: %b, your answer: %b, correct answer: %b <Wrong!>", data_in_1, data_in_2, data_out, test_data_out);
                end
            end
        end
    end*/

    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            score = 0;
            test         <= 0;
            alu_con      <= 0;
            test_alu_con <= 0;
            tmp_data_1   <= 0;
            tmp_data_2   <= 0;
            test_data_1  <= 0;
            test_data_2  <= 0;
        end else begin
            #clk_period;
            #clk_period;
            alu_con <= ADD;
            test_alu_con <= alu_con;
            test_data_1 <= data_in_1;
            test_data_2 <= data_in_2;
            for (i = 0; i < 10; i=i+1) begin
                if (i == 1) begin
                    $display("-----Addition-----");
                end
                tmp_data_1 <= $random(seed); 
                tmp_data_2 <= $random(seed);
                test_alu_con <= alu_con;
                test_data_1 <= data_in_1;
                test_data_2 <= data_in_2;
                #clk_period;
                #clk_period;
                test <= 1'b1;
            end

            alu_con <= SUB;
            test_alu_con <= alu_con;
            for (i = 0; i < 10; i=i+1) begin
                if (i == 1) begin
                    $display("-----Subtraction-----");
                end
                tmp_data_1 <= $random(seed); 
                tmp_data_2 <= $random(seed);
                test_alu_con <= alu_con;
                test_data_1 <= data_in_1;
                test_data_2 <= data_in_2;
                #clk_period;
                #clk_period;
            end
            
            alu_con <= AND;
            test_alu_con <= alu_con;
            for (i = 0; i < 10; i=i+1) begin
                if (i == 1) begin
                    $display("-----AND operation-----");
                end
                tmp_data_1   <= $random(seed); 
                tmp_data_2   <= $random(seed);
                test_alu_con <= alu_con;
                test_data_1  <= data_in_1;
                test_data_2  <= data_in_2;
                #clk_period;
                #clk_period;
            end

            alu_con <= OR;
            test_alu_con <= alu_con;
            for (i = 0; i < 10; i=i+1) begin
                if (i == 1) begin
                    $display("-----OR operation-----");
                end
                tmp_data_1   <= $random(seed); 
                tmp_data_2   <= $random(seed);
                test_alu_con <= alu_con;
                test_data_1  <= data_in_1;
                test_data_2  <= data_in_2;
                #clk_period;
                #clk_period;
            end

            alu_con <= NOR;
            test_alu_con <= alu_con;
            for (i = 0; i < 11; i=i+1) begin
                if (i == 1) begin
                    $display("-----NOR operation-----");
                end
                tmp_data_1   <= $random(seed); 
                tmp_data_2   <= $random(seed);
                test_alu_con <= alu_con;
                test_data_1  <= data_in_1;
                test_data_2  <= data_in_2;
                #clk_period;
                #clk_period;
            end
            test <= 1'b0;
            #clk_period;
            #clk_period;
            $display("-----Simulation Complete-----");
            $display("Total : <%d/50> score", score);
            $display("-----------------------------");
            #200;
        end
    end
endmodule

