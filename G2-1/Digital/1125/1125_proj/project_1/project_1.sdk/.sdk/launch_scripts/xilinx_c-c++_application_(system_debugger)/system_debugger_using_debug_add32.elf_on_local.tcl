connect -url tcp:127.0.0.1:3121
source C:/Users/user/Desktop/1125/1125_proj/project_1/project_1.sdk/ZC702_hw_platform/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zed 210248AC8A7E"} -index 0
loadhw -hw C:/Users/user/Desktop/1125/1125_proj/project_1/project_1.sdk/ZC702_hw_platform/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zed 210248AC8A7E"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248AC8A7E"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248AC8A7E"} -index 0
dow C:/Users/user/Desktop/1125/1125_proj/project_1/project_1.sdk/add32/Debug/add32.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zed 210248AC8A7E"} -index 0
con
