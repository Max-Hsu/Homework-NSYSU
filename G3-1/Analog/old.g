** Generated for: hspiceD
** Generated on: Nov 11 17:12:20 2020
** Design library name: Analog20
** Design cell name: sch
** Design view name: schematic
.GLOBAL vdd!


.PROBE TRAN
+    I1(m11)
+    I2(m9)
.TRAN 1e-9 100e-9 START=0.0

.TEMP 25.0
.OPTION
+    ARTIST=2
+    INGOLD=2
+    PARHIER=LOCAL
+    PSF=2
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" tt
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_bjt_v121.lib" tt_bip

** Library name: Analog20
** Cell name: sch
** View name: schematic
m11 net32 net21 0 0 n_33_mm w=1314e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m10 net21 net21 0 0 n_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m9 net3 net13 0 0 n_33_mm w=240-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m8 net13 net8 0 0 n_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m7 net8 net8 0 0 n_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m6 net3 net16 net34 0 n_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m5 net16 net16 net36 0 n_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
mr2 net24 0 net23 vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
mr4 net13 0 net25 vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
mr3 net25 0 net24 vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
mr1 net23 0 vdd! vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m4 net21 net3 vdd! vdd! p_33_mm w=480e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m3 net8 net3 vdd! vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m2 net3 net3 vdd! vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
m1 net16 net3 vdd! vdd! p_33_mm w=240e-9 l=340e-9 ad=241.6e-15 as=241.6e-15 pd=1.92e-6 ps=1.92e-6 m=1
v0 vdd! 0 DC=1.8
q2 0 0 net032 pnp_v50x50_mm m=1
q1 0 0 net36 pnp_v50x50_mm m=1
r1 net34 net032 1
r0 vdd! net32 1e3
.END
