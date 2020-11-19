** Generated for: hspiceD
** Generated on: Apr 10 18:26:37 2020
** Design library name: HW4
** Design cell name: XOR-test-0
** Design view name: schematic
.GLOBAL vdd!

.PARAM vdd_=3.3
.PROBE TRAN
+    I1(xi0.m9)
+    I1(xi0.m6)
+    I1(xi0.m14)
+    I1(xi0.m3)
+    I1(xi0.m13)
+    I1(xi0.m0)
+    I1(xi0.m12)
+    V(out)
+    V(c)
+    V(b)
+    V(a)
.TRAN 1e-9 100e-9 START=0.0

.TEMP 25.0
.OPTION
+    ARTIST=2
+    INGOLD=2
+    PARHIER=LOCAL
+    PSF=2
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" tt

** Library name: HW4
** Cell name: XOR
** View name: schematic
.subckt XOR a b c gnd out vdd
m27 c__ c vdd vdd p_33_mm w=130.56e-6 l=340e-9 ad=2.6112e-12 as=2.6112e-12 pd=5.36e-6 ps=5.36e-6 m=1
m26 b__ b vdd vdd p_33_mm w=130.56e-6 l=340e-9 ad=2.6112e-12 as=2.6112e-12 pd=5.36e-6 ps=5.36e-6 m=1
m25 a__ a vdd vdd p_33_mm w=130.56e-6 l=340e-9 ad=2.6112e-12 as=2.6112e-12 pd=5.36e-6 ps=5.36e-6 m=1
m11 net7 c__ vdd vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m10 net8 b__ net7 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m9 out a__ net8 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m8 net10 c vdd vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m7 net9 b net10 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m6 out a__ net9 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m5 net11 c vdd vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m4 net12 b__ net11 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m1 net13 b net14 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m0 out a net13 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m3 out a net12 vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m2 net14 c__ vdd vdd p_33_mm w=130.56e-6 l=1.36e-6 ad=5.2224e-12 as=5.2224e-12 pd=9.44e-6 ps=9.44e-6 m=1
m29 b__ b gnd gnd n_33_mm w=130.56e-6 l=340e-9 ad=1.3056e-12 as=1.3056e-12 pd=3.32e-6 ps=3.32e-6 m=1
m28 c__ c gnd gnd n_33_mm w=130.56e-6 l=340e-9 ad=1.3056e-12 as=1.3056e-12 pd=3.32e-6 ps=3.32e-6 m=1
m24 a__ a gnd gnd n_33_mm w=130.56e-6 l=340e-9 ad=1.3056e-12 as=1.3056e-12 pd=3.32e-6 ps=3.32e-6 m=1
m23 net014 c__ gnd gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m22 net014 b__ gnd gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m21 net014 a__ gnd gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m20 net017 c net014 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m19 net017 b net014 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m18 net017 a__ net014 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m17 net020 c net017 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m16 net020 b__ net017 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m15 net020 a net017 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m14 out c__ net020 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m13 out b net020 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
m12 out a net020 gnd n_33_mm w=48.96e-6 l=1.36e-6 ad=1.9584e-12 as=1.9584e-12 pd=4.34e-6 ps=4.34e-6 m=1
.ends XOR
** End of subcircuit definition.

** Library name: HW4
** Cell name: XOR-test-0
** View name: schematic
xi0 a b c 0 out vdd! XOR
c0 out 0 100e-15
v0 vdd! 0 DC=vdd_
v3 a 0 PULSE 0 3.3 10e-9 100e-12 100e-12 20e-9 40e-9
v2 b 0 PULSE 0 3.3 10e-9 100e-12 100e-12 10e-9 20e-9
v1 c 0 PULSE 0 3.3 10e-9 100e-12 100e-12 5e-9 10e-9

.alter SS_0_-10
.TEMP 0
.PARAM vdd_=2.97
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" SS
.alter SS_75_-10
.TEMP 75
.PARAM vdd_=2.97
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" SS
.alter SS_0_+10
.TEMP 0
.PARAM vdd_=3.63
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" SS
.alter SS_75_+10
.TEMP 75
.PARAM vdd_=3.63
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" SS
.alter FF_0_-10
.TEMP 0
.PARAM vdd_=2.97
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" FF
.alter FF_75_-10
.TEMP 75
.PARAM vdd_=2.97
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" FF
.alter FF_0_+10
.TEMP 0
.PARAM vdd_=3.63
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" FF
.alter FF_75_+10
.TEMP 75
.PARAM vdd_=3.63
.LIB "/home/vlsi109/vlsi109a01/UM180FDKMFC0000OA_A02/Models/Hspice/mm180_reg33_v114.lib" ff
.END
