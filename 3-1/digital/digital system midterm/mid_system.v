
`timescale 1 ns / 100 ps

module module_a
    (
         input  [2:0] data_in
        
        ,output      data_out
    );
    //data_in[0]->a, data_in[1]->b, data_in[2]->c
    wire a_and_b;
    wire nota;
    wire nota_and_c;

    /* your code here */
    wire b_and_c;
     
    logic_and    logic_and_0    (.data_in_1(data_in[0]), .data_in_2(data_in[1]), .data_out(a_and_b   ));
    logic_invert logic_invert_0 (.data_in  (data_in[0]), .data_out (nota      ));
    logic_and    logic_and_1    (.data_in_1(nota      ), .data_in_2(data_in[2]), .data_out(nota_and_c));
    //truth table? ????? ab? a'c?? bc? ???? hazard? ????? ?? ? ? ????.
    logic_and    logic_and_2    (.data_in_1(data_in[1]), .data_in_2(data_in[2]), .data_out(b_and_c   ));
    logic_or_3   logic_or_0     (.data_in_1(a_and_b   ), .data_in_2(nota_and_c), .data_in_3(b_and_c  ), .data_out(data_out));
    //??? wire ??? ???? b_and_c? ??????, ??? ?? or?? ?? ? bc? ??? or??? ??? ?????. 
    /*your code end*/
   
endmodule



module module_b
    #(
    ) 
        (
            input        clk
           ,input        rstn
           ,input  [1:0] data_in
           ,output       data_out

        );
    /*(1,0) means data_in[1] = 1, data_in[0] = 0*/
    /* your code here */

    

    /*your code end*/

endmodule

module module_c
    #(
    ) 
        (
            input  [2:0 ] data_in
           ,output [1:0 ] data_out

        );
            wire   [13:0] line;
   
    /* your code here */
   
    logic_and    and_0   (.data_in_1(data_in[0 ]),.data_in_2(data_in[1 ]),.data_out(data_out    [0 ]));
    logic_xor    xor_0   (.data_in_1(data_in[1 ]),.data_in_2(data_in[2 ]),.data_out(line        [0 ]));
    logic_invert logic_invert_0 (.data_in  (data_in[0]), .data_out (line[1]      ));
    logic_and    and_1   (.data_in_1(line[0 ]),.data_in_2(line[1 ]),.data_out(line    [2 ]));
    logic_and    and_2   (.data_in_1(data_in[2 ]),.data_in_2(data_out   [0 ]),.data_out(line        [3 ]));
    logic_or     or_1    (.data_in_1(line[2 ]),.data_in_2(line[3 ]),.data_out(data_out        [1 ]));
 //truth table? ???? data_out[0]? ??? ab??  data_out[1]? abc+a'b'c+a'bc'? ??.
 //? ?? delay? ??? ??? a'(b xor c) + abc?? ??? delay? 4.2ns??? clock?? ???? 5.3ns??.
 //??? maximum frequency? 1/5.3 * 10^9??.   
/*your code end*/

endmodule
