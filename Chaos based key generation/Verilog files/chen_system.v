`timescale 1ns / 1ns

module chen_system(
    input [31:0] Cx, Cy, Cz,
    output [31:0] X, Y, Z
    );

    wire [31:0] t1, t2, t3, t5, t6, t7, t8, t9, t11, t12, t13, t14, t15, t16;
    parameter a = 32'h420c0000;     // 35.0 in hex
    parameter b = 32'h40400000;     // 2.6667 in hex
    parameter c = 32'h41e00000;     // 28.0 in hex
    parameter m = 32'hc0e00000;     // -7 in hex
    parameter p = 32'h3c23d70a;     // 0.01 in hex
    
    sub s1(.in1(Cy), .in2(Cx), .out(t1));  
    mul m1(.in1(a), .in2(t1), .out(t2));
    mul m2(.in1(t2), .in2(p), .out(t3));
    add a1(.in1(Cx), .in2(t3), .out(X));
    
    mul m3(.in1(Cx), .in2(Cy), .out(t6)); 
    mul m4(.in1(b), .in2(Cz), .out(t7));
    sub s2(.in1(t6), .in2(t7), .out(t8));
    mul m5(.in1(t8), .in2(p), .out(t9));
    add a2(.in1(Cz), .in2(t9), .out(Z));
        
    mul m6(.in1(m), .in2(Cx), .out(t11));
    mul m7(.in1(Cz), .in2(Cx), .out(t12));
    mul m8(.in1(c), .in2(Cy), .out(t13));
    add a3(.in1(t12), .in2(t13), .out(t14));
    sub s3(.in1(t11), .in2(t14), .out(t15));
    mul m9(.in1(t15), .in2(p), .out(t16));
    add a4(.in1(t16), .in2(Cx), .out(Y));

endmodule
