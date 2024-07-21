`timescale 1ns / 1ps

module chua_system(
    input [31:0] Hx, Hy, Hz,
    output [31:0] X, Y, Z
    );
    
    wire [31:0] t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17;
    parameter a = 32'h41200000;     //  10 in Hex
    parameter b = 32'h417ae148;     //  15.68 in Hex
    parameter m0 = 32'hbfa00000;    //  -1.25 in Hex
    parameter m1 = 32'hbf400000;    //  -0.75 in Hex
    parameter p = 32'h3c23d70a;     // 0.01 in hex
    parameter p25 = 32'hbe800000;    //  -0.25 in Hex
    parameter p1 = 32'h3f800000;    //  1.0 in Hex
   
    mul m3(.in1(m0), .in2(Hx), .out(t1));
    sub s1(.in1(Hx), .in2(p1), .out(t2));
    add a1(.in1(Hx), .in2(p1), .out(t3));
  
    assign t16 = t2 & 32'hbf800000;
    assign t17 = t3 & 32'hbf800000;
    sub s2(.in1(t17), .in2(t16), .out(t4));
    mul m4(.in1(t4), .in2(p25), .out(t5));
    add a2(.in1(t5), .in2(t1), .out(t6));
    sub s3(.in1(Hy), .in2(Hx), .out(t7));
    sub s4(.in1(t7), .in2(t6), .out(t8));
    mul m5(.in1(t8), .in2(a), .out(t9));
    mul m6(.in1(t9), .in2(p), .out(t10));
    add a3(.in1(t10), .in2(Hx), .out(X));
    
    sub s5(.in1(Hx), .in2(Hy), .out(t11));
    sub s6(.in1(t11), .in2(Hz), .out(t12));
    mul m7(.in1(t12), .in2(p), .out(t13));
    add a4(.in1(t13), .in2(Hy), .out(Y));
    
    mul m8(.in1(b), .in2(Hy), .out(t14));
    mul m9(.in1(t14), .in2(p), .out(t15));
    sub s7(.in1(Hz), .in2(t15), .out(Z));  
   
endmodule