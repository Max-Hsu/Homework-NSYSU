#!/bin/sh
`cat udp_hop_1 | head -8 | tail -5 | sed "s/.*-//"  > udp_hop_1_processed`
`cat udp_hop_3 | head -8 | tail -5 | sed "s/.*-//"  > udp_hop_3_processed`
`cat udp_hop_5 | head -8 | tail -5 | sed "s/.*-//"  > udp_hop_5_processed`

set terminal png
set style data lines
set xlabel "Time (seconds)"
set ylabel "Bandwidth (Gbits/sec)"
plot [00:10]    "udp_hop_1_processed" using 1:5 title "udp hop 1 processed" ,\
                "udp_hop_3_processed" using 1:5 title "udp hop 3 processed" ,\
                "udp_hop_5_processed" using 1:5 title "udp hop 5 processed" ,\
