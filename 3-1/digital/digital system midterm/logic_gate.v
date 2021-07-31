
`timescale 1 ns / 100 ps

module d_ff_0
        (
            input      clk
           ,input      rstn
           ,input      d

           ,output reg q           
           ,output reg q_bar
        );
    
    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            q <= 1'b0;
            q_bar <= 1'b1;
        end else begin
            q <= d;
            q_bar <= ~d;
        end
    end      

endmodule

module d_ff_1
        (
            input      clk
           ,input      rstn
           ,input      d
           
           ,output reg q           
           ,output reg q_bar
        );
    
    always @(posedge clk or negedge rstn) begin
        if (!rstn) begin
            q <= 1'b1;
            q_bar <= 1'b0;
        end else begin
            q <= d;
            q_bar <= ~d;
        end
    end      

endmodule

module logic_invert
        (
            input  data_in
           
           ,output data_out
        );
     assign #0.3 data_out = ~data_in;    


endmodule


module logic_and
        (
            input  data_in_1
           ,input  data_in_2
           
           ,output data_out
        );
    
    assign #0.7 data_out = data_in_1 & data_in_2;    

endmodule


module logic_or_2
        (
            input  data_in_1
           ,input  data_in_2
           
           ,output data_out
        );
    
      wire [3:0] tmp; 

    assign  tmp[0] = data_in_1 | data_in_2;    
    assign  #0.2 tmp[1] = tmp[0];    
    assign  #0.2 tmp[2] = tmp[1];    
    assign  #0.2 tmp[3] = tmp[2];
    assign  #0.2 data_out = tmp[3];

endmodule


module logic_or_3
        (
            input  data_in_1
           ,input  data_in_2
           ,input  data_in_3
           
           ,output data_out
        );
    
      wire [3:0] tmp; 

    assign  tmp[0] = data_in_1 | data_in_2 | data_in_3;    
    assign  #0.2 tmp[1] = tmp[0];    
    assign  #0.2 tmp[2] = tmp[1];    
    assign  #0.2 tmp[3] = tmp[2];
    assign  #0.2 tmp[3] = tmp[2];
    assign  #0.2 tmp[3] = tmp[2];
    assign  #0.2 data_out = tmp[3];

endmodule

module logic_xor
        (
            input  data_in_1
           ,input  data_in_2
           
           ,output data_out
        );
    
    assign #1.2 data_out = data_in_1 ^ data_in_2;    

endmodule

module logic_nand
        (
            input  data_in_1
           ,input  data_in_2
           
           ,output data_out
        );
    
    assign #0.4 data_out = ~(data_in_1 & data_in_2);    

endmodule


module logic_nor
        (
            input  data_in_1
           ,input  data_in_2
           
           ,output data_out
        );
    
    assign #0.5 data_out = ~(data_in_1 | data_in_2);    

endmodule
