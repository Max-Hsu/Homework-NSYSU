#!/bin/sh
`cat tcp_hop_1 | head -8 | tail -5 | sed "s/.*-//"  > tcp_hop_1_processed`
`cat tcp_hop_3 | head -8 | tail -5 | sed "s/.*-//"  > tcp_hop_3_processed`
`cat tcp_hop_5 | head -8 | tail -5 | sed "s/.*-//"  > tcp_hop_5_processed`

set terminal png
set style data lines
set xlabel "Time (seconds)"
set ylabel "Bandwidth (Gbits/sec)"
plot [00:10]    "tcp_hop_1_processed" using 1:5 title "tcp hop 1 processed" ,\
                "tcp_hop_3_processed" using 1:5 title "tcp hop 3 processed" ,\
                "tcp_hop_5_processed" using 1:5 title "tcp hop 5 processed" ,\
