@echo off
REM ****************************************************************************
REM Vivado (TM) v2019.2 (64-bit)
REM
REM Filename    : elaborate.bat
REM Simulator   : Xilinx Vivado Simulator
REM Description : Script for elaborating the compiled design
REM
REM Generated by Vivado on Thu Nov 28 18:50:42 +0800 2019
REM SW Build 2708876 on Wed Nov  6 21:40:23 MST 2019
REM
REM Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
REM
REM usage: elaborate.bat
REM
REM ****************************************************************************
echo "xelab -wto 1a3a07fe84c44b5cb04858215a35fd9e --incr --debug typical --relax --mt 2 -L xil_defaultlib -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_6 -L processing_system7_vip_v1_0_8 -L generic_baseblocks_v2_1_0 -L fifo_generator_v13_2_5 -L axi_data_fifo_v2_1_19 -L axi_register_slice_v2_1_20 -L axi_protocol_converter_v2_1_20 -L lib_cdc_v1_0_2 -L proc_sys_reset_v5_0_13 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -L xpm --snapshot design_1_wrapper_behav xil_defaultlib.design_1_wrapper xil_defaultlib.glbl -log elaborate.log"
call xelab  -wto 1a3a07fe84c44b5cb04858215a35fd9e --incr --debug typical --relax --mt 2 -L xil_defaultlib -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_6 -L processing_system7_vip_v1_0_8 -L generic_baseblocks_v2_1_0 -L fifo_generator_v13_2_5 -L axi_data_fifo_v2_1_19 -L axi_register_slice_v2_1_20 -L axi_protocol_converter_v2_1_20 -L lib_cdc_v1_0_2 -L proc_sys_reset_v5_0_13 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -L xpm --snapshot design_1_wrapper_behav xil_defaultlib.design_1_wrapper xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
