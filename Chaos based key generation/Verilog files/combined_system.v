`timescale 1ns / 1ns
module combined_system(
    input [31:0] x, y, z,
    input rst, clk,
    output [383:0]k1,k2,k3,k4,
    output wire flag
);
    reg f;
    reg [31:0] Lx, Ly, Lz, Rx, Ry, Rz, Cx, Cy, Cz, Hx, Hy, Hz;
    wire [31:0] lx, ly, lz, rx, ry, rz, cx, cy, cz, hx, hy, hz;
    reg [31:0] counter = 0;
    reg [383:0]key1,key2,key3,key4;
    // Module instantiations
    lorentz_system T(Lx, Ly, Lz, lx, ly, lz);
    chen_system E(Cx, Cy, Cz, cx, cy, cz);
    chua_system Q(Hx, Hy, Hz, hx, hy, hz);
    rossler_system D(Rx, Ry, Rz, rx, ry, rz);
    integer i, j;
    assign k1 = key1, k2 = key2, k3 = key3, k4 = key4;
    assign flag = f;
    always @(posedge rst or posedge clk) begin
        if(rst) begin
            // Reset counter and outputs
            counter=0;
            Lx <= x; Rx <= x; Cx <= x; Hx <= x;
            Ly <= y; Ry <= y; Cy <= y; Hy <= y;
            Lz <= z; Rz <= z; Cz <= z; Hz <= z;
            f = 0;
        end
        else if(~flag) begin
           if(counter==10)
           begin 
           key1[383:352] <= lx;
           key1[351:320] <= ly;
           key1[319:288] <= lz;
           key1[287:256] <= rx;
           key1[255:224] <= ry;
           key1[223:192] <= rz;
           key1[191:160] <= cx;
           key1[159:128] <= cy;
           key1[127:96] <= cz;
           key1[95:64] <= hx;     
           key1[63:32] <= hy;
           key1[31:0] <= hz;      
//           key1 <={lx, ly, lz,rx, ry, rz,cx, cy, cz,hx, hy, hz}; 
           end
           if(counter==20)
           begin
           key2[383:352] <= lx;
           key2[351:320] <= ly;
           key2[319:288] <= lz;
           key2[287:256] <= rx;
           key2[255:224] <= ry;
           key2[223:192] <= rz;
           key2[191:160] <= cx;
           key2[159:128] <= cy;
           key2[127:96] <= cz;
           key2[95:64] <= hx;     
           key2[63:32] <= hy;
           key2[31:0] <= hz;
//           key2 <={lx, ly, lz,rx, ry, rz,cx, cy, cz,hx, hy, hz}; 
           end
           if(counter==30)
           begin
           key3[383:352] <= lx;
           key3[351:320] <= ly;
           key3[319:288] <= lz;
           key3[287:256] <= rx;
           key3[255:224] <= ry;
           key3[223:192] <= rz;
           key3[191:160] <= cx;
           key3[159:128] <= cy;
           key3[127:96] <= cz;
           key3[95:64] <= hx;     
           key3[63:32] <= hy;
           key3[31:0] <= hz;
//           key3 <={lx, ly, lz,rx, ry, rz,cx, cy, cz,hx, hy, hz}; 
           end
           if(counter==40)
           begin
           key4[383:352] <= lx;
           key4[351:320] <= ly;
           key4[319:288] <= lz;
           key4[287:256] <= rx;
           key4[255:224] <= ry;
           key4[223:192] <= rz;
           key4[191:160] <= cx;
           key4[159:128] <= cy;
           key4[127:96] <= cz;
           key4[95:64] <= hx;     
           key4[63:32] <= hy;
           key4[31:0] <= hz;
//           key4 <={lx, ly, lz,rx, ry, rz,cx, cy, cz,hx, hy, hz}; 
           f = 1;
           end
            Lx <= lx; Ly <= ly; Lz <= lz;
            Rx <= rx; Ry <= ry; Rz <= rz;
            Cx <= cx; Cy <= cy; Cz <= cz;
            Hx <= hx; Hy <= hy; Hz <= hz;
            
            counter<=counter+1;
         
        end
    end
endmodule