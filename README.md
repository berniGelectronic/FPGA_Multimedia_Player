# FPGA Based Multimedia Player 

```
#####################################################################
*                    >>> MsC Final Project <<<
* @name:    FPGA Based Multimedia Player
* @uni:     University of York
* @Msc:     DSE Programme 2019/20
* @Authors: Bernard Guncic & Oliver Forbes-Shaw
* @Hardware: PYNQ-Z2:-https://www.tul.com.tw/productspynq-z2.html
*             HyperPixel 4.0 inch touchscreen:- https://shop.pimoroni.com/products/hyperpixel-4?variant=12569485443155
* @Software: Vivado 2017.4.1 and its SDK
*
#####################################################################
```
## Installation
VIVADO:
1. Run create_project.bat file inside /scripts folder
2. Vivado project will be generated 
3. Generate bitstream
4. Export Hardware (*include bitstream)

SDK:
1. Launch Xilinx SDK from Vivado 
2. Import project files and BSP from /sw/sdk folder 


## IP 
I2S Slave IP used in this project is developed by Harald-rosenfeldt

https://www.harald-rosenfeldt.de/2018/01/06/zynq-use-audio-codec-with-variable-sampling-rate/
