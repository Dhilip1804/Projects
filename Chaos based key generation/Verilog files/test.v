`timescale 1ns / 1ns

module lorentz_system(
    input [31:0] Lx, Ly, Lz,
    output [31:0] X, Y, Z
    );

    wire [31:0] t1, t2, t4, t5, t6, t8, t9, t10, t12, t13, t14;
    parameter a = 32'h41200000;     // 10.0 in hex
    parameter b = 32'h402aab36;     // 2.6667 in hex
    parameter c = 32'h41e00000;     // 28.0 in hex
    parameter p = 32'h3c23d70a;     // 0.01 in hex
    
    sub s1(.in1(Ly), .in2(Lx), .out(t1));  //Lx <= Lx + 10 * (Ly - Lx);
    mul m1(.in1(a), .in2(t1), .out(t2));
    mul m2(.in1(t2), .in2(p), .out(t12));
    add a1(.in1(Lx), .in2(t12), .out(X));
        
    sub s2(.in1(c), .in2(Lz), .out(t4));   //Ly <= Ly + (Lx * (c - Lz) - Ly);
    mul m3(.in1(t4), .in2(Lx), .out(t5));
    sub s3(.in1(t5), .in2(Ly), .out(t6));
    mul m4(.in1(t6), .in2(p), .out(t13));
    add a2(.in1(t13), .in2(Ly), .out(Y));
        
    mul m5(.in1(Lx), .in2(Ly), .out(t8)); //Lz <= Lz + (Lx * Ly - (b * Lz));
    mul m6(.in1(b), .in2(Lz), .out(t9));
    sub s4(.in1(t8), .in2(t9), .out(t10));
    mul m7(.in1(t10), .in2(p), .out(t14));
    add a3(.in1(Lz), .in2(t14), .out(Z));

endmodule