
`timescale 1 ns / 100 ps

`include "alu.v"

module alu_top
    #(
        parameter WORD_SIZE    = 8
       ,parameter ALU_CON_SIZE = 4
    )
        (
            input                                 clk
           ,input                                 rstn
           ,input             [ALU_CON_SIZE-1:0]  alu_con
           ,input      signed [WORD_SIZE-1   :0]  data_in_1
           ,input      signed [WORD_SIZE-1   :0]  data_in_2
           
           ,output reg signed [WORD_SIZE-1   :0]  data_out
        );
    
    
            wire              [WORD_SIZE-1   :0] data_out_tmp;
    
    alu
        #(
            .WORD_SIZE    (WORD_SIZE   ),
            .ALU_CON_SIZE (ALU_CON_SIZE)
            ) alu_0 (
                .alu_con  (alu_con     ),
                .data_in_1(data_in_1   ),
                .data_in_2(data_in_2   ),
                .data_out (data_out_tmp)
            );
    
    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            data_out <= 0;
        end else begin
            data_out <= data_out_tmp;
        end
    end



endmodule
