`timescale 1ns / 1ns

module test_tb;
    reg [31:0] x, y, z;
    wire [31:0] X, Y, Z;
    lorentz_system uut (x, y, z, X, Y, Z);
    
    initial begin
        x = 32'h3f800000;
        y = 32'h40200000;
        z = 32'h3fc00000; #10;
        repeat (1000) begin
            x = X;
            y = Y;
            z = Z; #10;    
        end
        #10000;
        $finish;
    end
endmodule

