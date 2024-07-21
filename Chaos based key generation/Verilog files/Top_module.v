`timescale 1ns / 1ps

module Top_Module(
input i1, i2, i3, i4, i5,
input RxD,
input clk,
input reset,
input rst,
input btn,
output TxD,
output wire f1, f2, f3, f4
); 

reg fire;
reg transmit_out;
reg TxRx;
wire [7:0] RxCount, TxCount, TxData, RxData;
reg [31:0] x, y, z;
wire [383:0] k1, k2, k3, k4;
reg [383:0] key1, key2, key3, key4;
reg [0:7] received_data [47:0]; // Define a register to store 48 bytes of data
reg [0:7] xyz_data [3:0];
reg [7:0] index;
reg [7:0] counter;
reg [7:0] Txid;
integer i, j;
reg flag1, flag2, flag3;

assign f1 = flag1, f2 = flag2, f3 = flag3;

always @(posedge clk) begin 
    key1 <= k1; 
    key2 <= k2; 
    key3 <= k3; 
    key4 <= k4;
    if (reset) begin 
        transmit_out <= 0;
        index <= 0;   
        Txid <= 0;
    end if (btn) begin 
        counter <= 0;
        fire <= 1;
        flag1 <= 0;
        flag2 <= 0;
        flag3 <= 0;
    end if (RxCount == index + 1) begin 
        xyz_data[index] <= RxData;
        index <= index + 1; 
        counter <= counter + 1;     
    end if (counter == 4 && ~flag1) begin
        for (i = 0, j = 0; i<31; i = i + 8, j = j + 1)
            x[i +: 8] <= xyz_data[j];   
        flag1 = 1;
    end if (counter == 8 && ~flag2) begin
        for (i = 0, j = 0; i<31; i = i + 8, j = j + 1)
            y[i +: 8] <= xyz_data[j];   
        flag2 = 1;  
    end if (counter == 12 && ~flag3) begin
        for (i = 0, j = 0; i<31; i = i + 8, j = j + 1)
            z[i +: 8] <= xyz_data[j];   
        flag3 = 1; 
    end if (i1) begin
        for (i = 0, j = 0; i<383; i = i + 8, j = j + 1)
             received_data[j] <= key1[i +: 8];   
        transmit_out = 1;   
    end if (i2) begin
        for (i = 0, j = 0; i<383; i = i + 8, j = j + 1)
             received_data[j] <= key2[i +: 8];   
        transmit_out = 1;   
    end if (i3) begin
        for (i = 0, j = 0; i<383; i = i + 8, j = j + 1)
             received_data[j] <= key3[i +: 8];   
        transmit_out = 1;   
    end if (i4) begin
        for (i = 0, j = 0; i<383; i = i + 8, j = j + 1)
             received_data[j] <= key4[i +: 8];   
        transmit_out = 1;      
    end if (i5) begin
        for (i = 0, j = 0; i<31; i = i + 8, j = j + 1)
             received_data[j] <= x[i +: 8];
        for (i = 0; i<31; i = i + 8, j = j + 1)
             received_data[j] <= y[i +: 8];
        for (i = 0; i<31; i = i + 8, j = j + 1)
             received_data[j] <= z[i +: 8];
        for (i = 0; i<287; i = i + 8, j = j + 1)
             received_data[j] <= 8'b0; 
        transmit_out = 1;      
    end
    if (rst) fire <= 0;
    if (Txid == TxCount) Txid <= Txid + 1;
    if (Txid == 49) transmit_out <= 0;  
   // if (Txid == 5) transmit_out <= 0;  
end

combined_system c1(x, y, z, fire, clk, k1, k2, k3, k4, f4);
//Transmitter T1 (clk, reset, transmit_out, xyz_data[Txid - 1], TxCount, TxD);

Transmitter T1 (clk, reset, transmit_out, received_data[Txid - 1], TxCount, TxD);
Receiver R1 (clk, reset, RxD, RxData, RxCount);

endmodule
