#********************************************************************
# FPGA Player Pinout for Zynq 7000 - Pynq Z2 dev board
#********************************************************************

#********************************************************************
# Swithces
#********************************************************************
set_property -dict {PACKAGE_PIN M20 IOSTANDARD LVCMOS33} [get_ports sw_0]
set_property -dict {PACKAGE_PIN M19 IOSTANDARD LVCMOS33} [get_ports sw_1]

#********************************************************************
# LEDs
#********************************************************************
set_property -dict {PACKAGE_PIN R14 IOSTANDARD LVCMOS33} [get_ports {leds_4bits_tri_io[0]}]
set_property -dict {PACKAGE_PIN P14 IOSTANDARD LVCMOS33} [get_ports {leds_4bits_tri_io[1]}]
set_property -dict {PACKAGE_PIN N16 IOSTANDARD LVCMOS33} [get_ports {leds_4bits_tri_io[2]}]
set_property -dict {PACKAGE_PIN M14 IOSTANDARD LVCMOS33} [get_ports {leds_4bits_tri_io[3]}]

set_property -dict {PACKAGE_PIN L15 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[0]}]
set_property -dict {PACKAGE_PIN G17 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[1]}]
set_property -dict {PACKAGE_PIN N15 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[2]}]
set_property -dict {PACKAGE_PIN G14 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[3]}]
set_property -dict {PACKAGE_PIN L14 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[4]}]
set_property -dict {PACKAGE_PIN M15 IOSTANDARD LVCMOS33} [get_ports {rgb_led_tri_io[5]}]




#*********************************************************************
# Buttons
#*********************************************************************
set_property -dict {PACKAGE_PIN D19 IOSTANDARD LVCMOS33} [get_ports btn_0]
set_property -dict {PACKAGE_PIN D20 IOSTANDARD LVCMOS33} [get_ports btn_1]
set_property -dict {PACKAGE_PIN L20 IOSTANDARD LVCMOS33} [get_ports btn_2]
set_property -dict {PACKAGE_PIN L19 IOSTANDARD LVCMOS33} [get_ports btn_3]


#********************************************************************
# Audio Codec
#********************************************************************
set_property -dict {PACKAGE_PIN M17 IOSTANDARD LVCMOS33} [get_ports addr0]
set_property -dict {PACKAGE_PIN M18 IOSTANDARD LVCMOS33} [get_ports addr1]
set_property -dict {PACKAGE_PIN U5 IOSTANDARD LVCMOS33} [get_ports mclk]
set_property -dict {PACKAGE_PIN T9 IOSTANDARD LVCMOS33} [get_ports audio_i2c_sda_io]
set_property -dict {PACKAGE_PIN U9 IOSTANDARD LVCMOS33} [get_ports audio_i2c_scl_io]
set_property -dict {PACKAGE_PIN G18 IOSTANDARD LVCMOS33} [get_ports sdata]
set_property -dict {PACKAGE_PIN T17 IOSTANDARD LVCMOS33} [get_ports lrclk]
set_property -dict {PACKAGE_PIN R18 IOSTANDARD LVCMOS33} [get_ports bclk]


#********************************************************************
# LCD Pinout
#********************************************************************
set_property -dict {PACKAGE_PIN W18 IOSTANDARD LVCMOS33} [get_ports DPI_V_SYNC]
set_property -dict {PACKAGE_PIN W19 IOSTANDARD LVCMOS33} [get_ports DPI_H_SYNC]
set_property -dict {PACKAGE_PIN Y16 IOSTANDARD LVCMOS33} [get_ports DPI_RGB_CLK]
set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports RGB_D_EN]

set_property -dict {PACKAGE_PIN A20 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[0]}]
set_property -dict {PACKAGE_PIN Y9 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[1]}]
set_property -dict {PACKAGE_PIN U8 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[2]}]
set_property -dict {PACKAGE_PIN W6 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[3]}]
set_property -dict {PACKAGE_PIN Y7 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[4]}]
set_property -dict {PACKAGE_PIN F20 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_R[5]}]

set_property -dict {PACKAGE_PIN B20 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[0]}]
set_property -dict {PACKAGE_PIN W8 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[1]}]
set_property -dict {PACKAGE_PIN V6 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[2]}]
set_property -dict {PACKAGE_PIN Y6 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[3]}]
set_property -dict {PACKAGE_PIN B19 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[4]}]
set_property -dict {PACKAGE_PIN U7 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_G[5]}]

set_property -dict {PACKAGE_PIN Y18 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[0]}]
set_property -dict {PACKAGE_PIN Y19 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[1]}]
set_property -dict {PACKAGE_PIN U18 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[2]}]
set_property -dict {PACKAGE_PIN U19 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[3]}]
set_property -dict {PACKAGE_PIN F19 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[4]}]
set_property -dict {PACKAGE_PIN V10 IOSTANDARD LVCMOS33} [get_ports {RGB_OUT_B[5]}]

set_property -dict {PACKAGE_PIN W9 IOSTANDARD LVCMOS33} [get_ports TFT_MOSI]
set_property -dict {PACKAGE_PIN V7 IOSTANDARD LVCMOS33} [get_ports TFT_CLK]
set_property -dict {PACKAGE_PIN C20 IOSTANDARD LVCMOS33} [get_ports TFT_CS]
set_property -dict {PACKAGE_PIN Y8 IOSTANDARD LVCMOS33} [get_ports TFT_BK_LIGHT]
