`timescale 1 ns / 100 ps

`include "lab2_reader.v"
`include "lab2_memory_controller.v"
`include "lab2_memory.v"

module top
	#(
		parameter DATA_WIDTH 	= 32,
		parameter CLOCK_PERIOD 	= 1,
		parameter ADDRESS_SIZE	= 12,
		parameter MEMORY_SIZE 	= 4096
	)	
        (
            
        );
        
        reg	clk;
        reg    	rstn;
	reg  [1:0] counter;        
	wire [DATA_WIDTH-1:0] data_path_reader;
	wire [DATA_WIDTH-1:0] data_path_memory;          
	wire [ADDRESS_SIZE-1:0] address;
	wire read_complete;
	wire allow_address;
	wire [1:0] finish;
	wire [ADDRESS_SIZE-3:0] address1;
	wire [ADDRESS_SIZE-3:0] address2;
	wire [ADDRESS_SIZE-3:0] address3;
	wire [ADDRESS_SIZE-3:0] address4;
	wire [3:0] read;
	wire [3:0] path_on;

	memory_reader reader
	(
		.clk(clk),
		.rstn(rstn),
		.read_complete(read_complete),
		.allow_address(allow_address),
		.data_path(data_path_reader),
		.finish(finish),
		.address(address)
	);

memory_controller User_controller
	(
		.clk(clk),
		.rstn(rstn),
		.address_reader(address),
		.address_memory1(address1),
		.address_memory2(address2),
		.address_memory3(address3),
		.address_memory4(address4),
		.read(read),
		.path_on(path_on),
		.read_complete(read_complete),
		.allow_address(allow_address),
		.data_path_reader(data_path_reader),
		.data_path_memory(data_path_memory)
	);

	memory_1 memory1
	(
		.path_on(path_on[0]),
		.read(read[0]),
		.address(address1),
		.data_path(data_path_memory)
	);

	memory_2 memory2
	(
		.path_on(path_on[1]),
		.read(read[1]),
		.address(address2),
		.data_path(data_path_memory)
	);

	memory_3 memory3
	(
		.path_on(path_on[2]),
		.read(read[2]),
		.address(address3),
		.data_path(data_path_memory)
	);

	memory_4 memory4
	(
		.path_on(path_on[3]),
		.read(read[3]),
		.address(address4),
		.data_path(data_path_memory)
	);

	always@(*) begin
		#CLOCK_PERIOD clk <= ~clk;
	end

	always@(posedge clk) begin
		counter <= counter + 1;
	end

	//rstn signal is sync with memory clk.
	always@(posedge clk)begin
		if(rstn == 1'b0 && counter == 2'b10)begin
			#0.5 rstn <= 1'b1;
		end
	end

        //test controller
	always@ (finish)begin
		if(finish == 2'b01)begin
			rstn <= 1'b0;
		end
		else if(finish == 2'b10) begin
			rstn <= 1'b0;
		end
	end
	
	initial begin
		clk<= 1'b1;
		rstn <=1'b0;
		#0.1 counter <= 2'b0;


	#10000000
	$display("It's too long operation time");
	$finish();
	end



endmodule