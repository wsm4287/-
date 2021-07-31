`timescale 1 ns / 100 ps

/*
never change the name of input,output and module
if you change name of inout and module, you will get penalty

please write your comment in English
*/

module fin_prob_6
	(
		clk,
		rstn,
		X,
		Z
	);
	input clk;
	input rstn;
	input [2:0] X;
	output reg [3:0] Z;
///////////////your code here////////////////

reg[1:0] state;
reg[1:0] nextstate;

always @(negedge rstn) begin  // when rstn becomes 0 state set S0 and Z set 000
  state <= 2'b00;
  Z <= 4'b0000;
end

always @(posedge clk) begin  // when clk becomes positive clk state becomes next state
  state <= nextstate;
end

always @(X or state) begin // when state changes or X changes

  Z <= 4'b0000; // initial Z

  case(state)  
  2'b00 : begin // when state S0
    if(X[0:0] == 1) nextstate <= 2'b10; 
    else nextstate <= 2'b01;
  end

  2'b01 : begin // when state S1
    Z[0:0] <= 1;
    if(X[1:1] == 1) begin
      if(X[2:2] == 1) nextstate <= 2'b11;
      else nextstate <= 2'b01;
    end
    else nextstate <= 2'b01;
  end

  2'b10 : begin // when state S2
    if(X[1:1] == 1) Z[1:1] <= 1;
    else begin
      Z[2:2] <= 1;
      nextstate <= 2'b11;
    end
  end

  2'b11 : begin // when state S3
    Z[3:3] <= 1;
    if(X[2:2] == 1) nextstate <= 2'b00;
    else nextstate <= 2'b01;
  end
  endcase

end


///////////////your code end////////////////
endmodule

