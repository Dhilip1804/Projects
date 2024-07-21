`timescale 1ns/ 1ns

module rossler_system(
    input [31:0] Rx, Ry, Rz,
    output [31:0] X, Y, Z
    );
 
    
    wire [31:0] t1, t3, t4, t6, t7, t8, t10, t11, t12;
    parameter a = 32'h3e4ccccd;     // 0.2 in hex
    parameter b = 32'h3e4ccccd;     // 0.2 in hex
    parameter c = 32'h41600000;     // 14 in hex
    parameter p = 32'h3c23d70a;     // 0.01 in hex

    add a4(.in1(Ry), .in2(Rz), .out(t1));
    mul m9(.in1(t1), .in2(p), .out(t10));
    sub s5(.in1(Rx), .in2(t10), .out(X));
    
    mul m7(.in1(a), .in2(Ry), .out(t3));
    add a6(.in1(Rx), .in2(t3), .out(t4));
    mul m10(.in1(t4), .in2(p), .out(t11));
    add a7(.in1(t11), .in2(Rx), .out(Y));
        
    sub s6(.in1(Rx), .in2(c), .out(t6));
    mul m8(.in1(Rz), .in2(t6), .out(t7));
    add a8(.in1(t7), .in2(b), .out(t8));
    mul m11(.in1(t8), .in2(p), .out(t12));
    add a9(.in1(Rz), .in2(t12), .out(Z));
              
endmodule