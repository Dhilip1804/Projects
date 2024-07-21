 ##Clock signal
set_property PACKAGE_PIN E3 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]

##Uart
set_property PACKAGE_PIN C4 [get_ports RxD]
set_property IOSTANDARD LVCMOS33 [get_ports RxD]
set_property PACKAGE_PIN D4 [get_ports TxD]
set_property IOSTANDARD LVCMOS33 [get_ports TxD]

##buttons
set_property PACKAGE_PIN N17 [get_ports reset]
set_property IOSTANDARD LVCMOS33 [get_ports reset]
set_property PACKAGE_PIN M18 [get_ports btn]
set_property IOSTANDARD LVCMOS33 [get_ports btn]


##FLAGS
set_property PACKAGE_PIN v11 [get_ports {f1}]
set_property IOSTANDARD LVCMOS33 [get_ports {f1}]
set_property PACKAGE_PIN V12 [get_ports {f2}]
set_property IOSTANDARD LVCMOS33 [get_ports {f2}]
set_property PACKAGE_PIN V14 [get_ports {f3}]
set_property IOSTANDARD LVCMOS33 [get_ports {f3}]
set_property PACKAGE_PIN V15 [get_ports {f4}]
set_property IOSTANDARD LVCMOS33 [get_ports {f4}]
#set_property PACKAGE_PIN T16 [get_ports {f5}]
#set_property IOSTANDARD LVCMOS33 [get_ports {f5}]


## COUNTER_LEDS
set_property PACKAGE_PIN H17 [get_ports {Counter[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[0]}]
set_property PACKAGE_PIN K15 [get_ports {Counter[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[1]}]
set_property PACKAGE_PIN J13 [get_ports {Counter[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[2]}]
set_property PACKAGE_PIN N14 [get_ports {Counter[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[3]}]
set_property PACKAGE_PIN R18 [get_ports {Counter[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[4]}]
set_property PACKAGE_PIN V17 [get_ports {Counter[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[5]}]
set_property PACKAGE_PIN U17 [get_ports {Counter[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[6]}]
set_property PACKAGE_PIN U16 [get_ports {Counter[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {Counter[7]}]


#  ## Switches
set_property PACKAGE_PIN J15 [get_ports {i1}]
set_property IOSTANDARD LVCMOS33 [get_ports {i1}]
set_property PACKAGE_PIN L16 [get_ports {i2}]
set_property IOSTANDARD LVCMOS33 [get_ports {i2}]
set_property PACKAGE_PIN M13 [get_ports {i3}]
set_property IOSTANDARD LVCMOS33 [get_ports {i3}]
set_property PACKAGE_PIN R15 [get_ports {i4}]
set_property IOSTANDARD LVCMOS33 [get_ports {i4}]
set_property PACKAGE_PIN R17 [get_ports {i5}]
set_property IOSTANDARD LVCMOS33 [get_ports {i5}]
#set_property PACKAGE_PIN T18 [get_ports {i6}]
#set_property IOSTANDARD LVCMOS33 [get_ports {i6}] 

set_property PACKAGE_PIN V10 [get_ports {rst}]
set_property IOSTANDARD LVCMOS33 [get_ports {rst}]  