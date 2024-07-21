 ##Clock signal
set_property PACKAGE_PIN W5 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]


#  ## Switches
set_property PACKAGE_PIN V17 [get_ports {i1}]
set_property IOSTANDARD LVCMOS33 [get_ports {i1}]
set_property PACKAGE_PIN V16 [get_ports {i2}]
set_property IOSTANDARD LVCMOS33 [get_ports {i2}]
set_property PACKAGE_PIN W16 [get_ports {i3}]
set_property IOSTANDARD LVCMOS33 [get_ports {i3}]
set_property PACKAGE_PIN W17 [get_ports {i4}]
set_property IOSTANDARD LVCMOS33 [get_ports {i4}]
set_property PACKAGE_PIN W15 [get_ports {i5}]
set_property IOSTANDARD LVCMOS33 [get_ports {i5}]
#set_property PACKAGE_PIN V15 [get_ports {i6}]
#set_property IOSTANDARD LVCMOS33 [get_ports {i6}]
#set_property PACKAGE_PIN W14 [get_ports {i7}]
#set_property IOSTANDARD LVCMOS33 [get_ports {i7}]
set_property PACKAGE_PIN R2 [get_ports {rst}]
set_property IOSTANDARD LVCMOS33 [get_ports {rst}]

#set_property PACKAGE_PIN R2 [get_ports {data_only}]
#set_property IOSTANDARD LVCMOS33 [get_ports {data_only}]
# LEDs
#set_property PACKAGE_PIN U16 [get_ports {Counter[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[0]}]
#set_property PACKAGE_PIN E19 [get_ports {Counter[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[1]}]
#set_property PACKAGE_PIN U19 [get_ports {Counter[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[2]}]
#set_property PACKAGE_PIN V19 [get_ports {Counter[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[3]}]
#set_property PACKAGE_PIN W18 [get_ports {Counter[4]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[4]}]
#set_property PACKAGE_PIN U15 [get_ports {Counter[5]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[5]}]
#set_property PACKAGE_PIN U14 [get_ports {Counter[6]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[6]}]
#set_property PACKAGE_PIN V14 [get_ports {Counter[7]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {Counter[7]}]


set_property PACKAGE_PIN V13 [get_ports {f1}]
set_property IOSTANDARD LVCMOS33 [get_ports {f1}]
set_property PACKAGE_PIN V3 [get_ports {f2}]
set_property IOSTANDARD LVCMOS33 [get_ports {f2}]
set_property PACKAGE_PIN W3 [get_ports {f3}]
set_property IOSTANDARD LVCMOS33 [get_ports {f3}]
set_property PACKAGE_PIN U3 [get_ports {f4}]
set_property IOSTANDARD LVCMOS33 [get_ports {f4}]
#set_property PACKAGE_PIN P3 [get_ports {f1}]
#set_property IOSTANDARD LVCMOS33 [get_ports {f1}]
#set_property PACKAGE_PIN N3 [get_ports {f2}]
#set_property IOSTANDARD LVCMOS33 [get_ports {f2}]
#set_property PACKAGE_PIN P1 [get_ports {f3}]
#set_property IOSTANDARD LVCMOS33 [get_ports {f3}]
#set_property PACKAGE_PIN L1 [get_ports {f4}]
#set_property IOSTANDARD LVCMOS33 [get_ports {f4}]

##Buttons
set_property PACKAGE_PIN U18 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property PACKAGE_PIN T18 [get_ports btn]
set_property IOSTANDARD LVCMOS33 [get_ports btn]
#set_property PACKAGE_PIN W19 [get_ports RxData_only]
#set_property IOSTANDARD LVCMOS33 [get_ports RxData_only]
##Pmod Header JA
##Sch name = JA1
#set_property PACKAGE_PIN J1 [get_ports TxD_debug] 
#set_property IOSTANDARD LVCMOS33 [get_ports TxD_debug]
###Sch name = JA2
#set_property PACKAGE_PIN L2 [get_ports transmit_debug]
#set_property IOSTANDARD LVCMOS33 [get_ports transmit_debug]
###Sch name = JA3
#set_property PACKAGE_PIN J2 [get_ports btn_debug]
#set_property IOSTANDARD LVCMOS33 [get_ports btn_debug]
###Sch name = JA4
#set_property PACKAGE_PIN G2 [get_ports clk_debug]
#set_property IOSTANDARD LVCMOS33 [get_ports clk_debug]

##USB-RS232 Interface
set_property PACKAGE_PIN B18 [get_ports RxD]
set_property IOSTANDARD LVCMOS33 [get_ports RxD]
set_property PACKAGE_PIN A18 [get_ports TxD]
set_property IOSTANDARD LVCMOS33 [get_ports TxD]



set_property BITSTREAM.STARTUP.STARTUPCLK JTAGCLK [current_design]

set_property CFGBVS VCCO [current_design]
#where value1 is either VCCO or GND

set_property CONFIG_VOLTAGE 3.3 [current_design]
#where value2 is the voltage provided to configuration bank 0
