`timescale 1 ns / 100 ps

module memory_controller
	#(
		parameter WORD_SIZE 	= 32,
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 1,
		parameter ADDRESS_SIZE	= 12,
		parameter MEMORY_SIZE 	= 4096,
		parameter BUFFER_SIZE	= 64
	)
	(
		clk,
		rstn,
		address_reader,
		address_memory1,
		address_memory2,
		address_memory3,
		address_memory4,
		read,
		path_on,
		read_complete,
		allow_address,
		data_path_reader,
		data_path_memory
	);

	input clk;
	input rstn;
	input [ADDRESS_SIZE-1:0] address_reader;	

	output reg [ADDRESS_SIZE-3:0] address_memory1;
	output reg [ADDRESS_SIZE-3:0] address_memory2;
	output reg [ADDRESS_SIZE-3:0] address_memory3;
	output reg [ADDRESS_SIZE-3:0] address_memory4;
	output reg [3:0] read;
	output reg [3:0] path_on;
	output reg read_complete;
	output reg allow_address;
	output reg [DATA_WIDTH-1:0] data_path_reader;

	input [DATA_WIDTH-1:0] data_path_memory;

	reg [WORD_SIZE-1:0] data_buffer[0:BUFFER_SIZE - 1];
	reg [ADDRESS_SIZE-1:0] address_buffer[0:BUFFER_SIZE - 1];
/*
no use # syntax and initial syntax
you can't create more address buffer or data buffer
but you can create submodule or register when you need.
*/
///////////////////your code here///////////////////


  /*      integer i,k,x, last, llast;
        always @ (posedge rstn)	begin
		address_memory1 <= 0;
		address_memory2 <= 0;
		address_memory3 <= 0;
		address_memory4 <= 0;
		read <= 0;
		path_on <= 0;
		read_complete <= 0;
		allow_address <= 0;
		data_path_reader <= 0;
		x <= 0;
		k <= 0;
		last <= 0;
		llast <= 0;
		for(i=0; i<BUFFER_SIZE; i = i+1) begin
			data_buffer[i] <= 0;
			address_buffer[i] <= 0;
		end
	end

	always @ (posedge clk) begin
		if(k ==0) allow_address <= 1;
		if(k !== 32'bx) k <= k+1;
		if(k == 3) k <= 0;
		if(allow_address == 1) allow_address <=0;
		if(read_complete ==1) read_complete <= 0;
		if(x == 1) begin
			read_complete <= 1;
			x <=0;
		end
		else if(x ==2 || x== 3) x <= x-1;
		llast <= last;
		if(k == 0 || k == 2) path_on <=0;
		case(address_reader[11:10])
		2'b00 : begin
			if(k == 1 || k==3) path_on <= 4'b0001;
			read <= 4'b0001;
			address_memory1[9:0] <= address_reader[9:0];
			last <= 1;
			end
		2'b01 : begin
			if(k == 1 || k==3) path_on <= 4'b0010;
			read <= 4'b0010;
			address_memory2[9:0] <= address_reader[9:0];
			last <= 2;
			end
		2'b10 : begin
			if(k == 1 || k==3) path_on <= 4'b0100;
			read <= 4'b0100;
			address_memory3[9:0] <= address_reader[9:0];
			last <= 3;
			end
		2'b11 : begin
			if(k == 1 || k==3) path_on <= 4'b1000;
			read <= 4'b1000;
			address_memory4[9:0] <= address_reader[9:0];
			last <= 4;
			end
		endcase
	end

	always @ (data_path_memory) begin
		if(data_path_memory !== data_path_reader && data_path_memory !== 32'bx && data_path_memory !== 32'bz) begin
			data_path_reader <= data_path_memory;
			read <= 0;
			if(llast == last) x <= 1;
			else x <= 3;
		end
	end*/


        integer i,k;
	reg start;
        always @ (posedge rstn)	begin
		address_memory1 <= 0;
		address_memory2 <= 0;
		address_memory3 <= 0;
		address_memory4 <= 0;
		read <= 0;
		path_on <= 0;
		read_complete <= 0;
		allow_address <= 0;
		data_path_reader <= 0;
		k <= 0;
		start <= 0;
		for(i=0; i<BUFFER_SIZE; i = i+1) begin
			data_buffer[i] <= 0;
			address_buffer[i] <= 0;
		end
	end

	always @ (posedge clk) begin
		if(k ==0) begin 
		  allow_address <= 1;
		  if(start !== 0) read_complete <= 1;
		  else start <= 1;
		end 
		if(k !== 32'bx) k <= k+1;
		if(k == 3) k <= 0;
		if(allow_address == 1) allow_address <=0;
		if(read_complete ==1) read_complete <= 0;
		if(k == 0 || k == 2) path_on <=0;
		case(address_reader[11:10])
		2'b00 : begin
			if(k == 1 || k==3) path_on <= 4'b0001;
			read <= 4'b0001;
			address_memory1[9:0] <= address_reader[9:0];
			end
		2'b01 : begin
			if(k == 1 || k==3) path_on <= 4'b0010;
			read <= 4'b0010;
			address_memory2[9:0] <= address_reader[9:0];
			end
		2'b10 : begin
			if(k == 1 || k==3) path_on <= 4'b0100;
			read <= 4'b0100;
			address_memory3[9:0] <= address_reader[9:0];
			end
		2'b11 : begin
			if(k == 1 || k==3) path_on <= 4'b1000;
			read <= 4'b1000;
			address_memory4[9:0] <= address_reader[9:0];
			end
		endcase
	end

	always @ (data_path_memory) begin
		if(data_path_memory !== 32'bx && data_path_memory !== 32'bz) begin
			data_path_reader <= data_path_memory;
			read <= 0;
		end
	end
			


///////////////////your code end////////////////////
endmodule

//////your can create your own submodule here///////








////////////////your submodule end//////////////////