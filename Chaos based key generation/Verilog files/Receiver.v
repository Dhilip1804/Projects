`timescale 1ns / 1ps

module Receiver(

input clk, //100100MHz FPGA Basys 3 Board Clock
input reset, //reset button
input RxD, //input signal wire
output [7:0] RxData, //data that we receive at the receiving end, using 8 right most leds on the basys 3 board
output [7:0] RxCount
);
    
//Internal Variables
reg shift; //triggering the shifting of data.
reg state, nextstate; //initial state abd next variable state
reg [3:0] bit_counter; //total length of the bits is 10, 1 byte of data
reg [1:0] sample_counter; //frequency = 4 times the BR
reg [13:0] baudrate_counter; //for setting up a BR of 9600
reg [9:0] rxshift_reg; //data byte (10 bits) [8:1] --> data byte
reg clear_bitcounter,inc_bitcounter,inc_samplecounter,clear_samplecounter; //to clear and increment the bit counter and sample counter
reg [11:0] count;
// Constants
parameter clk_freq = 100_000_000; 
parameter baud_rate = 9600; 
parameter div_sample = 4;
parameter div_counter = clk_freq/(baud_rate*div_sample);  //this is the frequency we have to divide the system clock frequency to get a frequency (div_sample) time higher than the baudrate
parameter mid_sample = (div_sample/2);  //this is the middle point of a bit where you want to sample the data
parameter div_bit = 10; //1 start, 1 stop, 8 buts of data


assign RxData = rxshift_reg [8:1]; //assigning the RxData from the shift register
assign RxCount = count/10;
//UART //Receiver Logic
always @ (posedge clk)
    begin 
        if (reset)begin //if reset button is pressed, all counters are rset
            state <=0; //idle
            bit_counter <=0;
            baudrate_counter <=0; 
            sample_counter <=0;
            count <= 0; 
        end else begin 
            baudrate_counter <= baudrate_counter +1; 
            if (baudrate_counter >= div_counter-1) begin //if the counter reach the BR with sampling
                baudrate_counter <=0; //reset counter
                state <= nextstate; //it should be ready to receive the data/switch to receiving state
                if (shift) begin 
                    count <= count + 1; 
                    if (count == 480) count <= 0;
                    rxshift_reg <= {RxD,rxshift_reg[9:1]}; //if shift is asserted , then load the receiving data
                end
                if (clear_samplecounter) begin 
                    sample_counter <=0; //if clear asserted, then reset the sample counter
                    
                end
                if (inc_samplecounter) sample_counter <= sample_counter +1; //if inc_samplecounter is asserted, increment by 1
                if (clear_bitcounter) bit_counter <=0; //if clear_bitcounter, it should rset itself
                if (inc_bitcounter)bit_counter <= bit_counter +1; //bitcounter goes up by 1.
            end
        end
    end
   
//State Machine

always @ (posedge clk) //trigger by clock
begin 
    shift <= 0; //set shift to 0 to avoid any shifting, this is an idle state
    clear_samplecounter <=0; 
    inc_samplecounter <=0; 
    clear_bitcounter <=0; 
    inc_bitcounter <=0; 
    nextstate <=0; //idle state
    case (state)
        0: begin //Idle State
            if (RxD) //if input RxD line is asserted
              begin
              nextstate <=0; //stay in the idle state, RxD needs to be low to start the transmission
              end
            else begin 
                nextstate <=1; //receiving state
                clear_bitcounter <=1; //trigger ti clear the bitcounter
                clear_samplecounter <=1; //triggerto clear the sample counter.
            end
        end
        1: begin // Receiving State
            nextstate <= 1; // DEFAULT 
            if (sample_counter== mid_sample - 1) shift <= 1; //if the sample counter is 1, trigger shit
                if (sample_counter== div_sample - 1) begin //if the sample counter us 3 as the sample rate used is 4
                    if (bit_counter == div_bit - 1) begin //chec k if the bit counter is9 or not (0-9)
                    nextstate <= 0; //idle state
                end 
                inc_bitcounter <=1; //trigger the increment bit counter if bit count is not 9,
                clear_samplecounter <=1; //trigger the sample counter to reset the sample counter
            end else inc_samplecounter <=1; //if the sample counter is not 4, or not equal to 3 (0-3)
        end
       default: nextstate <=0; //idle state
     endcase
end         
endmodule