@ECHO OFF
set VIVADO_VER=2017.4
IF EXIST C:\Xilinx\Vivado\%VIVADO_VER%\bin\vivado.bat (
@C:\Xilinx\Vivado\%VIVADO_VER%\bin\vivado.bat -mode tcl -source project.tcl
close_project
ELSE (
echo ERROR: Unable to find Vivado %VIVADO_VER% installation
)
