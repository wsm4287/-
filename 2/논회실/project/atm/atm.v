module atm(clk,button_sw,seg_com,seg_data,led_data, k_s,k_d, dot_d, dot_scan);
input clk;
input [5:0] button_sw;
output reg[7:0] seg_com;
output reg[7:0] seg_data;
output reg[13:0] dot_d;
output reg[9:0] dot_scan;
reg[13:0] dot_d0, dot_d1, dot_d2, dot_d3, dot_d4, dot_d5,
dot_d6, dot_d7, dot_d8, dot_d9;
integer button_data;

integer count;
integer n;
integer d=0;
integer ok=0;
output reg[7:0] led_data;
input [3:0] k_d;
output reg [2:0] k_s;
integer key_data;
integer a1,a2,a3,a4,a5,a6,a7,a8;
integer answer;
wire k_stop;
assign k_stop = (k_d[3])||(k_d[2])||(k_d[1])||(k_d[0]);
integer cnt;
integer c;
integer temp_data;
integer dot;
reg[5:0] hour, min, sec, day ;
wire[7:0] seg_s0, seg_s1,seg_m0,seg_m1,seg_h0,seg_h1,seg_d0,seg_d1,a1_0,a1_1, a2_0,a2_1, a3_0,a3_1, a4_0,a4_1, a5_0,a5_1, a6_0,a6_1, a7_0,a7_1,a8_0,a8_1;
reg s_clk, m_clk, h_clk, d_clk;
integer cnts;
reg m;
integer target=0;

integer b;

wire[7:0] answer_0,answer_1;
integer qwer,profit;
integer x,y;

integer a01[0:10], a02[0:10], a03[0:10], a04[0:10], a05[0:10], a06[0:10], a07[0:10], a08[0:10];
integer a01_1=0,a02_1=0,a03_1=0,a04_1=0,a05_1=0,a06_1=0,a07_1=0,a08_1=0;


integer xx;
wire[7:0] xx_0, xx_1;

integer i=0,co;


initial
begin
	qwer=0;
	profit=0;
	b=0;
	count =0;
	a1 =0;
	a2 =0;
	a3 =0;
	a4 =0;
	a5 =0;
	a6 =0;
	a7 =0;
	a8 =0;
	seg_data=8'b00000000;
	seg_com=8'b00000000;
	cnt = 0;
	answer = 0;
	temp_data =8;
	day =1;
	hour=0;
	min=0;
	sec=0;
	cnt=0;
	cnts=0;
	h_clk=1'b0;
	s_clk=1'b0;
	m_clk=1'b0;
	d_clk=1'b0;
	cnts=0;
	button_data = 8;
	c=0;
	m=1'b0;
	x=0;
	n=0;
	dot=0;
end
////////////////////////decoder
decod_0 sec0(clk,sec,seg_s0);
decod_1 sec1(clk,sec,seg_s1);
decod_0 min0(clk,min,seg_m0);
decod_1 min1(clk,min,seg_m1);
decod_0 hour0(clk,hour,seg_h0);
decod_1 hour1(clk,hour,seg_h1);
decod_0 day0(clk,day,seg_d0);
decod_1 day1(clk,day,seg_d1);

decod_0 x1(clk,answer,answer_0);


decod_1 y0(clk,answer,answer_1);

decod_0 a10(clk,a1,a1_0);
decod_1 a11(clk,a1,a1_1);
decod_0 a20(clk,a2,a2_0);
decod_1 a21(clk,a2,a2_1);
decod_0 a30(clk,a3,a3_0);
decod_1 a31(clk,a3,a3_1);
decod_0 a40(clk,a4,a4_0);
decod_1 a41(clk,a4,a4_1);
decod_0 a50(clk,a5,a5_0);
decod_1 a51(clk,a5,a5_1);
decod_0 a60(clk,a6,a6_0);
decod_1 a61(clk,a6,a6_1);
decod_0 a70(clk,a7,a7_0);
decod_1 a71(clk,a7,a7_1);
decod_0 a80(clk,a8,a8_0);
decod_1 a81(clk,a8,a8_1);

decod_0 ee1(clk,xx,xx_0);
decod_1 ff1(clk,xx,xx_1);




////////////////////////////clock
always@(posedge clk)
begin
 if(cnts == 499)
 begin
 cnts <= 0;
 s_clk <= ~(s_clk);
end
else
begin
 cnts <= cnts + 1;
end
end
always@(posedge s_clk|| m)
begin
if(m>=1)
	begin
	sec <=0;
	end
else
	begin
if (sec >= 59)
begin
m_clk <= 1'b1;
sec <= 0;
end
else
begin
sec <= sec + 1;
m_clk <= 1'b0;
end
end

end
always@(posedge m_clk||  m)
begin
if(m>=1)
	begin
	min <=0;
	end
else
begin
if (min >= 59)
begin
h_clk <= 1'b1;
min <= 0;
end
else
begin
 min <= min + 1;
h_clk <= 1'b0;
end
end

end
always@(posedge h_clk|| m)
begin

if(m>=1)
	begin
	hour <=0;
	end
else
begin
if (hour >= 23)
begin
d_clk <= 1'b1;
hour <= 0;
end
else
begin
hour <= hour +1;
d_clk <= 1'b0;
end
end

end
always@(posedge d_clk|| m)
begin
if(m>=1)
		begin
		day <=1;
		end
else
		begin
		if (day >= 31)
			begin
			day <= 1;
		if(profit == 0)
			profit <=1;
		else
			profit <=0;

			end
		else
			begin
			day <= day +1;
			end
		if(profit == 0)
			profit <=1;
		else
			profit <=0;
		end
end
////////////////////////////key_data_input
always@(posedge clk)
begin
 ////////////////////// profit
 if(profit==1 && qwer==0) 
 begin
 a1<=a1+a1/10;
 a01[a01_1] <=a1+a1/10;
 a01_1 <= a01_1 +1;
 a2<=a2+a2/10;
 a02[a02_1] <=a2+a2/10;
 a02_1 <= a02_1 +1;
 a3<=a3+a3/10;
 a03[a03_1] <=a3+a3/10;
 a03_1 <= a03_1 +1;
 a4<=a4+a4/10;
 a04[a04_1] <=a4+a4/10;
 a04_1 <= a04_1 +1;
 a5<=a4+a5/10;
 a05[a05_1] <=a5+a5/10;
 a05_1 <= a5_1 +1;
 a6<=a6+a6/10;
 a06[a06_1] <=a6+a6/10;
 a06_1 <= a06_1 +1;
 a7<=a7+a7/10;
 a07[a07_1] <=a7+a7/10;
 a07_1 <= a07_1 +1;
 a8<=a8+a8/10;
 a08[a08_1] <=a8+a8/10;
 a08_1 <= a08_1 +1;
 qwer<=1;
 end
 
 if(profit==0 && qwer==1)
 begin
 a1<=a1+a1/10;
 a01[a01_1] <=a1+a1/10;
 a01_1 <= a01_1 +1;
 a2<=a2+a2/10;
 a02[a02_1] <=a2+a2/10;
 a02_1 <= a02_1 +1;
 a3<=a3+a3/10;
 a03[a03_1] <=a3+a3/10;
 a03_1 <= a03_1 +1;
 a4<=a4+a4/10;
 a04[a04_1] <=a4+a4/10;
 a04_1 <= a04_1 +1;
 a5<=a4+a5/10;
 a05[a05_1] <=a5+a5/10;
 a05_1 <= a5_1 +1;
 a6<=a6+a6/10;
 a06[a06_1] <=a6+a6/10;
 a06_1 <= a06_1 +1;
 a7<=a7+a7/10;
 a07[a07_1] <=a7+a7/10;
 a07_1 <= a07_1 +1;
 a8<=a8+a8/10;
 a08[a08_1] <=a8+a8/10;
 a08_1 <= a08_1 +1;
 qwer<=0;
 end



 ////////////////////////// key_data
 if(k_stop==1'b1);
 else
 begin
 case(k_s)
 3'b000 : k_s <= 3'b001;
 3'b001 : k_s <= 3'b010;
 3'b010 : k_s <= 3'b100;
 3'b100 : k_s <= 3'b001;
 endcase
 end
 case(k_s)
 3'b001:
 case(k_d)
 4'b0001: 
 begin
 if(n==0)
 begin
 if(d==0)
 key_data<=1;
 if(d==1)
 begin
 target<=1;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+1;
 n<=3;
 end
 if(n==4)
 begin
 answer<=answer*10+1;
 n<=5;
 end
 end
 4'b0010: 
 begin
 if(n==0)
 begin
 if(d==0)
 key_data<=4;
  if(d==1)
 begin
 target<=4;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+4;
 n<=3;
 end
 if(n==4)
 begin
 answer<=answer*10+4;
 n<=5;
 end
 end
 4'b0100: 
  begin
 if(n==0)
 begin
 if(d==0) key_data<=7;
 if(d==1)
 begin
 target<=7;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+7;
 n<=3;
 end
 if(n==4)
 begin
 answer<=answer*10+7;
 n<=5;
 end
 end

 default : 
 begin
  if(n==0)
 begin
 if(b==1||d==2)
 n<=2;
 end
 if(n==1)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=2;
 else
 n<=0;
 end
 if(n==3)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=4;
 else
 n<=0;
 end
 end
 endcase
 3'b010:
 case(k_d)
 4'b0001: 
  begin
 if(n==0)
 begin
 if(d==0) key_data<=2;
   if(d==1)
 begin
 target<=2;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+2;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+2;
 n<=5;
 end
 end
 4'b0010: 
  begin
 n<=1;
 if(n==0)
 begin
 if(d==0) key_data<=5;
   if(d==1)
 begin
 target<=5;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+5;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+5;
 n<=5;
 end
 end
 4'b0100: 
  begin
 if(n==0)
 begin
 if(d==0) key_data<=8;
   if(d==1)
 begin
 target<=8;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+8;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+8;
 n<=5;
 end
 end
 4'b1000: 
  begin
 if(n==0)
 begin
 if(d==0) key_data<=0;
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+0;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+0;
 n<=5;
 end
 end
 default :
 begin
  if(n==0)
 begin
 if(b==1||d==2)
 n<=2;
 end
 if(n==1)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=2;
 else
 n<=0;
 end
 if(n==3)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=4;
 else
 n<=0;
 end
 end
 endcase
 3'b100:
 case(k_d)
 4'b0001: 
 begin
 if(n==0)
 begin
 if(d==0) key_data<=3;
   if(d==1)
  begin
 target<=3;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+3;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+3;
 n<=5;
 end
 end
 4'b0010: 
 begin
 if(n==0)
 begin
 if(d==0) key_data<=6;
 if(d==1)
  begin
 target<=6;
 d<=2;
 end
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+6;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+6;
 n<=5;
 end
 end
 4'b0100: 
 begin
 if(n==0)
 begin
 if(d==0) key_data<=9;
 n<=1;
 end
 if(n==2)
 begin
 answer<=answer*10+9;
 n<=3;
 end
  if(n==4)
 begin
 answer<=answer*10+9;
 n<=5;
 end
 end
 4'b1000: 
  begin
  key_data <=10;
 end
 default : 
 begin
 if(n==0)
 begin
 if(b==1||d==2)
 n<=2;
 end
 if(n==1)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=2;
 else
 n<=0;
 end
 if(n==3)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=4;
 else
 n<=0;
 end
 end
 endcase
default : 
begin
 if(n==0)
 begin
 if(b==1||d==2)
 n<=2;
 end
if(n==1)
begin
key_data <=key_data;
 if(b==1||d==2)
 n<=2;
 else
 n<=0;
end
if(n==3)
 begin
 key_data <= key_data;
 if(b==1||d==2)
 n<=4;
 else
 n<=0;
 end
end
endcase

////////////////////key_data 
if(n==1)
begin
 case(key_data)
 0 : led_data<=8'b00000000;
 1 : 
	begin
	led_data<=8'b00000001;
	end
 2 : 
	begin
	led_data<=8'b00000010;
	end
 3 : 
	begin
	led_data<=8'b00000100;
	end
 4 : 
	begin
	led_data<=8'b00001000;
	end
 5 :
	begin
	led_data<=8'b00010000;
	end
 6 :	
	begin
	led_data<=8'b00100000;
	end
 7 : 	
	begin
	led_data<=8'b01000000;
	end
 8 : 	
	begin
	led_data<=8'b10000000;
	end
 10 : led_data <= 8'b00000000;
 default : led_data<=led_data;
 endcase
 end

/////////////////////button_sw
case(button_sw)
6'b000001 : button_data <= 0;
6'b000010 : button_data <= 1;
6'b000100 : button_data <= 2;
6'b001000 : button_data <= 3;
6'b010000 : button_data <= 4;
6'b100000 : button_data <= 5;
default : button_data <= 8;
endcase
temp_data <= button_data;
//////////////////////function
case (temp_data)
0 : 
	begin
	n<=6;
	if(c==2)
		begin
		c<=0;
		end
	else
		begin
		c<=c+1;
		end
	case (c)
		0 :
			begin
			case (led_data)
			8'b00000001:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a1_0;
			end
			8'b00000010:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a2_0;
			end
			8'b00000100:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a3_0;
			end
			8'b00001000:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a4_0;
			end
			8'b00010000:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a5_0;
			end
			8'b00100000:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a6_0;
			end
			8'b01000000:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a7_0;
			end
			8'b10000000:
			begin
			seg_com <= 8'b01111111;
			seg_data <= a8_0;
			end
			endcase
			end
		1 :
			begin
			case (led_data)
			8'b00000001:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a1_1;
			end
			8'b00000010:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a2_1;
			end
			8'b00000100:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a3_1;
			end
			8'b00001000:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a4_1;
			end
			8'b00010000:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a5_1;
			end
			8'b00100000:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a6_1;
			end
			8'b01000000:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a7_1;
			end
			8'b10000000:
			begin
			seg_com <= 8'b10111111;
			seg_data <= a8_1;
			end
			endcase
			end

	endcase
	if(count==2499)
		begin
		count<=0;
		n<=0;	
	   led_data<=8'b00000000;
		temp_data <=8;
		end
	else
		begin
		count<=count+1;
		temp_data <=0;
		end
	end
	
1 :
	begin
	b<=1;

	if(c==2)
		begin
		c<=0;
		end
	else
		begin
		c<=c+1;
		end
	case (c)
		0 :
			begin
			seg_com <= 8'b01111111;
			seg_data <= answer_0;
			end
		1 :
			begin
			seg_com <= 8'b10111111;
			seg_data <= answer_1;
			end
		endcase
	

			
		
		if(button_data==4)
		begin
		case(led_data)
			8'b00000001 : 
				begin
				a1 <= a1 +answer;
				a01[a01_1] <= a1+answer;
				a01_1 <= a01_1+1;
				end
			8'b00000010 : 
				begin
				a2 <= a2 +answer;
				a02[a02_1] <= a2+answer;
				a02_1<= a02_1+1;
				end
			8'b00000100 : 
				begin
				a3 <= a3 +answer;
				a03[a03_1] <= a3+answer;
				a03_1<= a03_1+1;
				end
			8'b00001000 :
				begin
				a4 <= a4 +answer;
				a04[a04_1] <= a4+answer;
				a04_1<= a04_1+1;
				end
			8'b00010000 : 
				begin
				a5 <= a5 +answer;
				a05[a05_1] <= a5+answer;
				a05_1<= a05_1+1;
				end
			8'b00100000 : 
				begin
				a6 <= a6 +answer;
				a06[a06_1] <= a6+answer;
				a06_1<= a06_1+1;
				end
			8'b01000000 : 
				begin
				a7 <= a7 +answer;
				a07[a07_1] <= a7+answer;
				a07_1<= a07_1+1;
				end
			8'b10000000 : 
				begin
				a8 <= a8 +answer;
				a08[a08_1] <= a8+answer;
				a08_1<= a08_1+1;
				end
			endcase
		answer<=0;
		x<=0;
		y<=0;
		end
	else
		begin
		temp_data <=1;
		end
		

	end
2 : 
	begin
	b<=1;

	if(c==2)
		begin
		c<=0;
		end
	else
		begin
		c<=c+1;
		end
	case (c)
		0 :
			begin
			seg_com <= 8'b01111111;
			seg_data <= answer_0;
			end
		1 :
			begin
			seg_com <= 8'b10111111;
			seg_data <= answer_1;
			end
		endcase
		

		if(button_data==4)
		begin
		case(led_data)
			8'b00000001 : 
				begin 
				if(a1>=answer) 
				begin 
				a1 <= a1 -answer; 
				a01[a01_1] <= a1-answer;
				a01_1<= a01_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;  
				end 
			8'b00000010 : 
				begin 
				if(a2>=answer) 
				begin 
				a2 <= a2 -answer; 
				a02[a02_1] <= a2-answer;
				a02_1<= a02_1+1;
				end 
				else 
				ok<=1;   
				end
			8'b00000100 : 
				begin 
				if(a3>=answer) 
				begin 
				a3 <= a3 -answer; 
				a03[a03_1] <= a3-answer;
				a03_1<= a03_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;   
				end
			8'b00001000 : 
				begin 
				if(a4>=answer) 
				begin 
				a4 <= a4 -answer; 
				a04[a04_1] <= a4-answer;
				a04_1<= a04_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;   
				end
			8'b00010000 : 
				begin 
				if(a5>=answer) 
				begin 
				a5 <= a5 -answer; 
				a05[a05_1] <= a5-answer;
				a05_1<= a05_1+1;
				ok<=0; 
				end 
				else
				ok<=1;   
				end
			8'b00100000 : 
				begin 
				if(a6>=answer) 
				begin 
				a6 <= a6 -answer; 
				a06[a06_1] <= a6-answer;
				a06_1<= a06_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;   
				end
			8'b01000000 : 
				begin 
				if(a7>=answer) 
				begin 
				a7 <= a7 -answer; 
				a07[a07_1] <= a7-answer;
				a07_1<= a07_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;   
				end
			8'b10000000 : 
				begin 
				if(a8>=answer) 
				begin 
				a8 <= a8 -answer;
a08[a08_1] <= a8-answer;
				a08_1<= a08_1+1;
				ok<=0; 
				end 
				else 
				ok<=1;   
				end
			endcase
		answer<=0;
		x<=0;
		y<=0;
		end
	else
		begin
		temp_data <=2;
		end
		
		end
3 :
	begin
	if(target==0)
		d<=1;
	else
		d<=2;


	if(c==2)
		begin
		c<=0;
		end
	else
		begin
		c<=c+1;
		end
	case (c)
		0 :
			begin
			seg_com <= 8'b01111111;
			seg_data <= answer_0;
			end
		1 :
			begin
			seg_com <= 8'b10111111;
			seg_data <= answer_1;
			end
		endcase
		
		

		if(button_data==4)
		begin
		case(led_data)
			8'b00000001 : 
				begin 
					if(a1>=answer) 
						begin 
								a1 <= a1 -answer; 
								a01[a01_1] <= a1-answer;
								a01_1<= a01_1+1;
								ok<=0; 
								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b00000010 : 
							begin 
					if(a2>=answer) 
						begin 
								a2 <= a2 -answer; 
								a02[a02_1] <= a2-answer;
								a02_1 <= a02_1+1;
								ok<=0; 
								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b00000100 : 
							begin 
					if(a3>=answer) 
						begin 
								a3 <= a3 -answer; 
								a03[a03_1] <= a3-answer;
								a03_1 <= a03_1+1;
								ok<=0; 

								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b00001000 : 
							begin 
					if(a4>=answer) 
						begin 
								a4 <= a4 -answer; 
								a04[a04_1] <= a4-answer;
								a04_1 <= a04_1+1;
								ok<=0; 

								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b00010000 : 
							begin 
					if(a5>=answer) 
						begin 
								a5 <= a5 -answer; 
								a05[a05_1] <= a5-answer;
								a05_1 <= a05_1+1;
								ok<=0; 

								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b00100000 : 
							begin 
					if(a6>=answer) 
						begin 
								a6 <= a6 -answer; 
								a06[a06_1] <= a6-answer;
								a06_1 <= a06_1+1;
								ok<=0; 
									case (target)

											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b01000000 : 
							begin 
					if(a7>=answer) 
						begin 
								a7<= a7 -answer; 
								a07[a07_1] <= a7-answer;
								a07_1 <= a07_1+1;
								ok<=0; 

								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			8'b10000000 : 
							begin 
					if(a8>=answer) 
						begin 
								a8 <= a8 -answer; 
								a08[a08_1] <= a8-answer;
								a08_1 <= a08_1+1;
								ok<=0; 
								case(target)
											1 : 
begin
a1 <= a1+answer;
a01[a01_1] <= a1+answer;
a01_1<= a01_1+1;
end

											2 : begin
a2 <= a2+answer;
a02[a02_1] <= a2+answer;
a02_1<= a02_1+1;
end
											3 : begin
a3 <= a3+answer;
a03[a03_1] <= a3+answer;
a03_1<= a03_1+1;
end
											4 : begin
a4 <= a4+answer;
a04[a04_1] <= a4+answer;
a04_1<= a04_1+1;
end
											5 : begin
a5 <= a5+answer;
a05[a05_1] <= a5+answer;
a05_1<= a05_1+1;
end
											6 : begin
a6 <= a6+answer;
a06[a06_1] <= a6+answer;
a06_1<= a06_1+1;
end
											7 : begin
a7 <= a7+answer;
a07[a07_1] <= a7+answer;
a07_1<= a07_1+1;
end
											8 : begin
a8 <= a8+answer;
a08[a08_1] <= a8+answer;
a08_1<= a08_1+1;
end
								endcase
							end 
						else 
						ok<=1;  
						end 
			endcase
		answer<=0;
		x<=0;
		y<=0;
		end
	else
		begin
		temp_data <=3;
		end
		
		end

		
4 :
	begin
	if(b!=0||d!=0)
	begin
		if(c==2)
		begin
		c<=0;
		end
	else
		begin
		c<=c+1;
		end
	case (c)
		0 :
			begin
			seg_com <= 8'b01111111;
			case(led_data)
			8'b00000001 : seg_data <= a1_0;
			8'b00000010 : seg_data <= a2_0;
			8'b00000100 : seg_data <= a3_0;
			8'b00001000 : seg_data <= a4_0;
			8'b00010000 : seg_data <= a5_0;
			8'b00100000 : seg_data <= a6_0;
			8'b01000000 : seg_data <= a7_0;
			8'b10000000 : seg_data <= a8_0;
			endcase
			end
		1 :
			begin
			seg_com <= 8'b10111111;
			case(led_data)
			8'b00000001 : seg_data <= a1_1;
			8'b00000010 : seg_data <= a2_1;
			8'b00000100 : seg_data <= a3_1;
			8'b00001000 : seg_data <= a4_1;
			8'b00010000 : seg_data <= a5_1;
			8'b00100000 : seg_data <= a6_1;
			8'b01000000 : seg_data <= a7_1;
			8'b10000000 : seg_data <= a8_1;
			endcase
			end
		endcase
		
		if(count==2499)
		begin
		count<=0;
		n<=0;	
	   led_data<=8'b00000000;
		temp_data<=8;
		b<=0;
		ok<=0;
		d<=0;
		target<=0;
		end
		
		else
		begin
		count<=count+1;
		temp_data <=4;
		end
		
		
		
	end
		else
			begin
				if(c==2)
				begin
				c<=0;
				end
				else
				begin
				c<=c+1;
				end
					case (c)
						0 :
							begin
							seg_com <= 8'b01111111;
							seg_data <= xx_0;
							end
						1 	:
							begin
							seg_com <= 8'b10111111;
							seg_data <= xx_1;
							end
						endcase
			case (led_data)
			8'b00000001 :
				begin
				xx<= a01[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b00000010 :
				begin
				xx<= a02[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b00000100 :
				begin
				xx<= a03[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b00001000 :
				begin
				xx<= a04[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b00010000 :
					begin
				xx<= a05[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b00100000 :
				begin
				xx<= a06[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b01000000 :
				begin
				xx<= a07[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
			8'b10000000 :
				begin
				xx<= a08[i];
				if(co==499)
					begin
					i<= i+1;
					co <= 0;
					end
				else
				co <= co+1;
				if(i==10)
					begin
					led_data<=8'b00000000;
					temp_data<=8;
					i<=0;
					end
				else
					begin
					temp_data<=4;
					end
				end
				endcase
			
			
			end
		
		
	if(dot==9)
		begin
		dot<=0;
		end
		else
		begin
		dot<=dot+1;
		end

	
	if(ok==0)
		case(dot)
		0 :
		begin
		dot_scan<=10'b0000000001;
		dot_d<=14'b11111111111111;
		end
		1 :
		begin
		dot_scan<=10'b0000000010;
		dot_d<=14'b10000000000001;
		end
		2 :
		begin
		dot_scan<=10'b0000000100;
		dot_d<=14'b10000000000001;
		end
		3 :
		begin
		dot_scan<=10'b0000001000;
		dot_d<=14'b10000000000001;
		end
		4 :
		begin
		dot_scan<=10'b0000010000;
		dot_d<=14'b10000000000001;
		end
		5 :
		begin
		dot_scan<=10'b0000100000;
		dot_d<=14'b10000000000001;
		end
		6 :
		begin
		dot_scan<=10'b0001000000;
		dot_d<=14'b10000000000001;
		end
		7 :
		 begin
		dot_scan<=10'b0010000000;
		dot_d<=14'b10000000000001;
		end
		8 :
		begin
		dot_scan<=10'b0100000000;
		dot_d<=14'b10000000000001;
		end
		9 :
		begin
		dot_scan<=10'b1000000000;
		dot_d<=14'b11111111111111;
		end
		endcase
		
	if(ok==1)
		case(dot)
		0 :
		begin
		dot_scan<=10'b0000000001;
		dot_d<=14'b10000000000001;
		end
		1 :
		begin
		dot_scan<=10'b0000000010;
		dot_d<=14'b01000000000010;
		end
		2 :
		begin
		dot_scan<=10'b0000000100;
		dot_d<=14'b00100000000100;
		end
		3 :
		begin
		dot_scan<=10'b0000001000;
		dot_d<=14'b00011000011000;
		end
		4 :
		begin
		dot_scan<=10'b0000010000;
		dot_d<=14'b00000101000000;
		end
		5 :
		begin
		dot_scan<=10'b0000100000;
		dot_d<=14'b0000001000000;
		end
		6 :
		begin
		dot_scan<=10'b0001000000;
		dot_d<=14'b00000101000000;
		end
		7 :
		 begin
		dot_scan<=10'b0010000000;
		dot_d<=14'b00011000011000;
		end
		8 :
		begin
		dot_scan<=10'b0100000000;
		dot_d<=14'b00100000000100;
		end
		9 :
		begin
		dot_scan<=10'b1000000000;
		dot_d<=14'b10000000000001;
		end
		endcase
		
end

	

5 :
	begin
	a1<=0;
	a2<=0;
	a3<=0;
	a4<=0;
	a5<=0;
	a6<=0;
	a7<=0;
	a8<=0;
	m <= m+1;
	a01_1<=0;
	a02_1<=0;
	a03_1<=0;
	a04_1<=0;
	a05_1<=0;
	a06_1<=0;
	a07_1<=0;
	a08_1<=0;
	
	if(i==11)
		i<=0;
	else
		begin
		a01[i]<=0;
		a02[i]<=0;
		a03[i]<=0;
		a04[i]<=0;
		a05[i]<=0;
		a06[i]<=0;
		a07[i]<=0;
		a08[i]<=0;
		i<=i+1;
		end
		
	seg_com <= 8'b11111111;
	if(count==499)
		begin
		count<=0;
		key_data<=10;
		if(m>=1) m<=0;
		led_data<=8'b00000000;
		end
	else
		begin
		count<=count+1;
		temp_data <=5;
	
		end
	end
	
	

	
	
	
	
	
	
	
default : ////////////////clock_seg


begin
 if(cnt==9)
 begin
 cnt<=0;
 end
 else
 begin
 cnt<=cnt+1;
 end
 case (cnt)
 0 :
begin
seg_com <= 8'b01111111;
seg_data <= seg_s0;
end
1 :
begin
seg_com <= 8'b10111111;
seg_data <= seg_s1;
end
2 :
begin
 seg_com <= 8'b11011111;
seg_data <= seg_m0;
end
3 :
begin
seg_com <= 8'b11101111;
seg_data <= seg_m1;
end
4 :
begin
seg_com <= 8'b11110111;
seg_data <= seg_h0;
end
5 :
begin
seg_com <= 8'b11111011;
seg_data <= seg_h1;
 end
 6 :
 begin
 seg_com <= 8'b11111101;
 seg_data <= seg_d0;
 end
 7 :
 begin
 seg_com <= 8'b11111110;
 seg_data <= seg_d1;
 end
endcase
		if(dot==9)
		begin
		dot<=0;
		end
		else
		begin
		dot<=dot+1;
		end
		
		case(dot)
		0 :
		begin
		dot_scan<=10'b0000000001;
		dot_d<=14'b00000000000000;
		end
		1 :
		begin
		dot_scan<=10'b0000000010;
		dot_d<=14'b00000000000000;
		end
		2 :
		begin
		dot_scan<=10'b0000000100;
		dot_d<=14'b00000000000000;
		end
		3 :
		begin
		dot_scan<=10'b0000001000;
		dot_d<=14'b00000000000000;
		end
		4 :
		begin
		dot_scan<=10'b0000010000;
		dot_d<=14'b00000000000000;
		end
		5 :
		begin
		dot_scan<=10'b0000100000;
		dot_d<=14'b00000000000000;
		end
		6 :
		begin
		dot_scan<=10'b0001000000;
		dot_d<=14'b00000000000000;
		end
		7 :
		 begin
		dot_scan<=10'b0010000000;
		dot_d<=14'b00000000000000;
		end
		8 :
		begin
		dot_scan<=10'b0100000000;
		dot_d<=14'b00000000000000;
		end
		9 :
		begin
		dot_scan<=10'b1000000000;
		dot_d<=14'b00000000000000;
		end
		endcase




end
endcase
end
endmodule
