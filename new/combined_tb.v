`timescale 1ns / 1ns

module combined_tb;
    reg clk, rst;
    reg [31:0] x, y, z; // Change to 128-bit inputs
    wire [383:0]key1,key2,key3,key4;
    wire flag;
    combined_system uut (
        .x(x), .y(y), .z(z),
        .rst(rst), .clk(clk),
        .k1(key1),.k2(key2),.k3(key3),.k4(key4),
        .flag(flag)
    );

    initial begin
        // Initialize clock and reset
        clk = 0;
        rst = 1;
        x = 32'h3f800000;
        y = 32'h3f800000;
        z = 32'h3f800000;
  
        #5; 
        rst = 0;
        #10; 
        repeat (1000) begin
            #1 clk = ~clk;
        end
        $finish;
    end
endmodule



