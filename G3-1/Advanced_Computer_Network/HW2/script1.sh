#!/bin/sh
set terminal png
set style data lines
set xlabel "Time (seconds)"
set ylabel "packets/s"
plot [00:60] "tcpstat.log" using 1:2 title "ARP" , "tcpstat.log" using 1:3 title "TCP" , "tcpstat.log" using 1:4 title "UDP"