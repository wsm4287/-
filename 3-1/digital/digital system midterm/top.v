
`timescale 1 ns / 100 ps

`include "test_bench_mid.v"
`include "mid_system.v"
`include "logic_gate.v"

module top 
        (
            
        );
        
            reg                             clk;
            reg                             rstn1;
                  
    integer run_time;
    real    clk_period;
    wire    resulta,resultb,resultc;
    test_module_a modulea(resulta);
    test_module_b moduleb(clk,rstn1,resultb);
    test_module_c modulec(resultc);
    initial begin
	rstn1 <= 1'b0;
        run_time   = 2030;
        clk_period = 20;
        clk        <= 1'b0;
	$display("--------------------------------module_A_test_START-----------------------------------");
	#1000
	$display("--------------------------------module_A_test_complete--------------------------------");
	$display("--------------------------------module_B_test_START-----------------------------------");
        rstn1       <= 1'b0;
        #clk_period;
        #clk_period;
        rstn1      <= 1'b1;
            
        #(run_time-2*clk_period);
	rstn1 <= 1'b0;
	$display("--------------------------------module_B_test_complete--------------------------------");
	$display("--------------------------------module_C_test_START-----------------------------------");
	#2000;
	$display("--------------------------------module_C_test_complete--------------------------------");
	if(resulta==1'b1)begin $display("outputs of module_a are correct");end else begin $display("outputs of module_a are uncorrect"); end
	if(resultb==1'b1)begin $display("module_b is correct");end else begin $display("module_b is uncorrect"); end
	if(resultc==1'b1)begin $display("outputs of module_c are correct");end else begin $display("outputs of module_c are uncorrect"); end
	$display("**********************************************************************************************************");
	$display("**Correct of module_A and module_C is not mean your answer is perfect. It means just your output is right.");
	$display("**********************************************************************************************************");
        $finish();
    end
    always @(*) begin
        clk <=#clk_period ~clk;
    end
        


endmodule
