module decod_0(clk,num,seg_0);
input clk;
input[9:0] num;
output reg[7:0] seg_0;
always@(posedge clk)
begin
 case((num%10))
 0 : seg_0<=8'b11111100;
 1 : seg_0<=8'b01100000;
 2 : seg_0<=8'b11011010;
 3 : seg_0<=8'b11110010;
 4 : seg_0<=8'b01100110;
 5 : seg_0<=8'b10110110;
 6 : seg_0<=8'b10111110;
 7 : seg_0<=8'b11100000;
 8 : seg_0<=8'b11111110;
 9 : seg_0<=8'b11100110;
 default: seg_0<=8'b11111100;
 endcase
end
endmodule
module decod_1(clk,num,seg_1);
input clk;
input[9:0] num;
output reg[7:0] seg_1;
always@(posedge clk)
begin
 case((num/10))
 0 : seg_1<=8'b11111100;
 1 : seg_1<=8'b01100000;
 2 : seg_1<=8'b11011010;
 3 : seg_1<=8'b11110010;
 4 : seg_1<=8'b01100110;
 5 : seg_1<=8'b10110110;
 6 : seg_1<=8'b10111110;
 7 : seg_1<=8'b11100000;
 8 : seg_1<=8'b11111110;
 9 : seg_1<=8'b11100110;
 default: seg_1<=8'b11111100;
 endcase
end
endmodule