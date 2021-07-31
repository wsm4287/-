`timescale 1 ns / 100 ps

/*
data_width =32
memory_size = 1024*32bit


memory1 : 2*clk period,posedge 00
memory2 : 2*clk period,negedge 01
memory3 : 4*clk period,posedge 10
memory4 : 2*clk period,negedge,slow read 11
*/

module memory_1
	#(
		parameter WORD_SIZE 	= 32,
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 2,
		parameter ADDRESS_SIZE	= 10,
		parameter MEMORY_SIZE 	= 1024
	)
	(
		path_on,
		read,
		address,
		data_path
	);

	input path_on;
	input read;
	input [ADDRESS_SIZE-1:0] address;
	output [DATA_WIDTH-1:0] data_path;

	
	reg memory_clk;
	reg [WORD_SIZE-1:0] data[0:MEMORY_SIZE-1];
	reg [DATA_WIDTH-1:0] buffer;
	reg [DATA_WIDTH-1:0] tri_buffer;

	assign data_path = tri_buffer;

	always @ (*) begin
		#CLOCK_PERIOD memory_clk <= ~memory_clk;
	end
	
	always @ (path_on) begin
		if(path_on == 1'b1) begin
			#0.2 tri_buffer <= buffer;
		end
		else begin
			#0.2 tri_buffer <= 'bZ;
		end	
	end

	//give data to data_path
	always @ (posedge memory_clk) begin
		#0.1
		if(read == 1'b1) begin
			buffer <= data[address];
		end
	end

	initial begin
	//initial
	memory_clk <= 1;
	$readmemb("memory1.bin",data);
	//data read
	buffer <= 0;
	end

endmodule

module memory_2
	#(
		parameter WORD_SIZE 	= 32,
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 2,
		parameter ADDRESS_SIZE	= 10,
		parameter MEMORY_SIZE 	= 1024
	)
	(
		path_on,
		read,
		address,
		data_path
	);

	input path_on;
	input read;
	input [ADDRESS_SIZE-1:0] address;
	output [DATA_WIDTH-1:0] data_path;

	
	reg memory_clk;
	reg [WORD_SIZE-1:0] data[0:MEMORY_SIZE-1];
	reg [DATA_WIDTH-1:0] buffer;
	reg [DATA_WIDTH-1:0] tri_buffer;

	assign data_path = tri_buffer;

	always @ (*) begin
		#CLOCK_PERIOD memory_clk <= ~memory_clk;
	end
	
	always @ (path_on) begin
		if(path_on == 1'b1) begin
			#0.2 tri_buffer <= buffer;
		end
		else begin
			#0.2 tri_buffer <= 'bZ;
		end	
	end
	
	//give data to data_path
	always @ (negedge memory_clk) begin
		#0.1
		if(read == 1'b1) begin
			buffer <= data[address];
		end
	end

	initial begin
	//initial
	memory_clk <= 1;
	$readmemb("memory2.bin",data);
	//data read
	buffer <= 0;
	end


endmodule

module memory_3
	#(
		parameter WORD_SIZE 	= 32,
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 4,
		parameter ADDRESS_SIZE	= 10,
		parameter MEMORY_SIZE 	= 1024
	)
	(
		path_on,
		read,
		address,
		data_path
	);

	input path_on;
	input read;
	input [ADDRESS_SIZE-1:0] address;
	output [DATA_WIDTH-1:0] data_path;

	
	reg memory_clk;
	reg [WORD_SIZE-1:0] data[0:MEMORY_SIZE-1];
	reg [DATA_WIDTH-1:0] buffer;
	reg [DATA_WIDTH-1:0] tri_buffer;

	assign data_path = tri_buffer;

	always @ (*) begin
		#CLOCK_PERIOD memory_clk <= ~memory_clk;
	end
	
	always @ (path_on) begin
		if(path_on == 1'b1) begin
			#0.2 tri_buffer <= buffer;
		end
		else begin
			#0.2 tri_buffer <= 'bZ;
		end	
	end
	
	//give data to data_path
	always @ (posedge memory_clk) begin
		#0.1
		if(read == 1'b1) begin
			buffer <= data[address];
		end
	end

	initial begin
	//initial
	memory_clk <= 0;
	$readmemb("memory3.bin",data);
	//data read
	buffer <= 0;
	end


endmodule

module memory_4
	#(
		parameter WORD_SIZE 	= 32,
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 2,
		parameter ADDRESS_SIZE	= 10,
		parameter MEMORY_SIZE 	= 1024
	)
	(
		path_on,
		read,
		address,
		data_path
	);

	input path_on;
	input read;
	input [ADDRESS_SIZE-1:0] address;
	output [DATA_WIDTH-1:0] data_path;

	
	reg memory_clk;
	reg [WORD_SIZE-1:0] data[0:MEMORY_SIZE-1];
	reg [DATA_WIDTH-1:0] buffer,buffer1;
	reg [DATA_WIDTH-1:0] tri_buffer;

	assign data_path = tri_buffer;

	always @ (*) begin
		#CLOCK_PERIOD memory_clk <= ~memory_clk;
	end
	
	always @ (path_on) begin
		if(path_on == 1'b1) begin
			#0.2 tri_buffer <= buffer;
		end
		else begin
			#0.2 tri_buffer <= 'bZ;
		end	
	end
	
	//give data to data_path
	always @ (negedge memory_clk) begin
		#0.1
		if(read == 1'b1) begin
			#CLOCK_PERIOD buffer1 <= data[address];
			#CLOCK_PERIOD buffer <= buffer1;
		end
	end

	initial begin
	//initial
	memory_clk <= 1'b1;
	$readmemb("memory4.bin",data);
	//data read
	buffer <= 0;
	buffer1 <= 0;
	end


endmodule
