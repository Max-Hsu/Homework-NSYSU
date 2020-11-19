<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="w" />
        <signal name="XLXN_2" />
        <signal name="XLXN_3" />
        <signal name="y" />
        <signal name="XLXN_6" />
        <signal name="x" />
        <signal name="z" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="f1" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_20" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_34" />
        <signal name="XLXN_42" />
        <signal name="XLXN_53" />
        <signal name="f2" />
        <signal name="XLXN_60" />
        <signal name="XLXN_65" />
        <signal name="XLXN_66" />
        <signal name="XLXN_67" />
        <signal name="f3" />
        <signal name="XLXN_56" />
        <signal name="XLXN_57" />
        <signal name="XLXN_87" />
        <port polarity="Input" name="w" />
        <port polarity="Input" name="y" />
        <port polarity="Input" name="x" />
        <port polarity="Input" name="z" />
        <port polarity="Output" name="f1" />
        <port polarity="Output" name="f2" />
        <port polarity="Output" name="f3" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="w" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_2">
            <blockpin signalname="x" name="I0" />
            <blockpin signalname="XLXN_3" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="f1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_4">
            <blockpin signalname="XLXN_11" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_5">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="y" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_6">
            <blockpin signalname="x" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="w" name="I" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="z" name="I" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_14">
            <blockpin signalname="x" name="I" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_15">
            <blockpin signalname="w" name="I" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_18">
            <blockpin signalname="XLXN_16" name="I0" />
            <blockpin signalname="w" name="I1" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_19">
            <blockpin signalname="x" name="I0" />
            <blockpin signalname="XLXN_17" name="I1" />
            <blockpin signalname="XLXN_25" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_20">
            <blockpin signalname="XLXN_25" name="I0" />
            <blockpin signalname="XLXN_24" name="I1" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_21">
            <blockpin signalname="z" name="I0" />
            <blockpin signalname="XLXN_42" name="I1" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_25">
            <blockpin signalname="y" name="I" />
            <blockpin signalname="XLXN_42" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_28">
            <blockpin signalname="XLXN_27" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="XLXN_53" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_26">
            <blockpin signalname="XLXN_53" name="I" />
            <blockpin signalname="f2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_38">
            <blockpin signalname="z" name="I" />
            <blockpin signalname="XLXN_60" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_40">
            <blockpin signalname="XLXN_67" name="I0" />
            <blockpin signalname="XLXN_66" name="I1" />
            <blockpin signalname="f3" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_41">
            <blockpin signalname="XLXN_60" name="I0" />
            <blockpin signalname="y" name="I1" />
            <blockpin signalname="XLXN_67" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_42">
            <blockpin signalname="XLXN_65" name="I0" />
            <blockpin signalname="XLXN_87" name="I1" />
            <blockpin signalname="XLXN_66" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_44">
            <blockpin signalname="x" name="I0" />
            <blockpin signalname="XLXN_56" name="I1" />
            <blockpin signalname="XLXN_87" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_36">
            <blockpin signalname="w" name="I" />
            <blockpin signalname="XLXN_56" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_48">
            <blockpin signalname="XLXN_57" name="I0" />
            <blockpin signalname="w" name="I1" />
            <blockpin signalname="XLXN_65" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_37">
            <blockpin signalname="x" name="I" />
            <blockpin signalname="XLXN_57" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="672" y="1088" name="XLXI_1" orien="R0" />
        <instance x="672" y="1264" name="XLXI_2" orien="R0" />
        <instance x="1328" y="1264" name="XLXI_3" orien="R0" />
        <instance x="1008" y="1184" name="XLXI_4" orien="R0" />
        <instance x="672" y="1440" name="XLXI_5" orien="R0" />
        <instance x="352" y="1056" name="XLXI_6" orien="R0" />
        <instance x="352" y="1168" name="XLXI_7" orien="R0" />
        <instance x="352" y="1408" name="XLXI_8" orien="R0" />
        <branch name="w">
            <wire x2="672" y1="960" y2="960" x1="352" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="672" y1="1024" y2="1024" x1="576" />
        </branch>
        <branch name="XLXN_3">
            <wire x2="672" y1="1136" y2="1136" x1="576" />
        </branch>
        <branch name="x">
            <wire x2="672" y1="1200" y2="1200" x1="352" />
        </branch>
        <branch name="y">
            <wire x2="672" y1="1312" y2="1312" x1="352" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="672" y1="1376" y2="1376" x1="576" />
        </branch>
        <iomarker fontsize="28" x="352" y="960" name="w" orien="R180" />
        <branch name="x">
            <wire x2="352" y1="1024" y2="1024" x1="320" />
        </branch>
        <iomarker fontsize="28" x="320" y="1024" name="x" orien="R180" />
        <branch name="w">
            <wire x2="352" y1="1136" y2="1136" x1="320" />
        </branch>
        <iomarker fontsize="28" x="320" y="1136" name="w" orien="R180" />
        <iomarker fontsize="28" x="352" y="1200" name="x" orien="R180" />
        <iomarker fontsize="28" x="352" y="1312" name="y" orien="R180" />
        <branch name="z">
            <wire x2="352" y1="1376" y2="1376" x1="320" />
        </branch>
        <iomarker fontsize="28" x="320" y="1376" name="z" orien="R180" />
        <branch name="XLXN_10">
            <wire x2="960" y1="992" y2="992" x1="928" />
            <wire x2="960" y1="992" y2="1056" x1="960" />
            <wire x2="1008" y1="1056" y2="1056" x1="960" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="960" y1="1168" y2="1168" x1="928" />
            <wire x2="960" y1="1120" y2="1168" x1="960" />
            <wire x2="1008" y1="1120" y2="1120" x1="960" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="1296" y1="1088" y2="1088" x1="1264" />
            <wire x2="1296" y1="1088" y2="1136" x1="1296" />
            <wire x2="1328" y1="1136" y2="1136" x1="1296" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="1120" y1="1344" y2="1344" x1="928" />
            <wire x2="1120" y1="1200" y2="1344" x1="1120" />
            <wire x2="1328" y1="1200" y2="1200" x1="1120" />
        </branch>
        <branch name="f1">
            <wire x2="1616" y1="1168" y2="1168" x1="1584" />
        </branch>
        <iomarker fontsize="28" x="1616" y="1168" name="f1" orien="R0" />
        <instance x="368" y="1680" name="XLXI_14" orien="R0" />
        <instance x="368" y="1792" name="XLXI_15" orien="R0" />
        <branch name="w">
            <wire x2="688" y1="1584" y2="1584" x1="368" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="688" y1="1648" y2="1648" x1="592" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="688" y1="1760" y2="1760" x1="592" />
        </branch>
        <branch name="x">
            <wire x2="688" y1="1824" y2="1824" x1="368" />
        </branch>
        <branch name="x">
            <wire x2="368" y1="1648" y2="1648" x1="336" />
        </branch>
        <branch name="w">
            <wire x2="368" y1="1760" y2="1760" x1="336" />
        </branch>
        <branch name="XLXN_24">
            <wire x2="960" y1="1616" y2="1616" x1="944" />
            <wire x2="976" y1="1616" y2="1616" x1="960" />
            <wire x2="976" y1="1616" y2="1680" x1="976" />
            <wire x2="1024" y1="1680" y2="1680" x1="976" />
        </branch>
        <branch name="XLXN_25">
            <wire x2="976" y1="1792" y2="1792" x1="944" />
            <wire x2="976" y1="1744" y2="1792" x1="976" />
            <wire x2="1024" y1="1744" y2="1744" x1="976" />
        </branch>
        <branch name="XLXN_26">
            <wire x2="1312" y1="1712" y2="1712" x1="1280" />
            <wire x2="1312" y1="1712" y2="1760" x1="1312" />
            <wire x2="1344" y1="1760" y2="1760" x1="1312" />
        </branch>
        <branch name="XLXN_27">
            <wire x2="1136" y1="1968" y2="1968" x1="944" />
            <wire x2="1136" y1="1824" y2="1968" x1="1136" />
            <wire x2="1344" y1="1824" y2="1824" x1="1136" />
        </branch>
        <iomarker fontsize="28" x="368" y="1584" name="w" orien="R180" />
        <iomarker fontsize="28" x="336" y="1648" name="x" orien="R180" />
        <iomarker fontsize="28" x="336" y="1760" name="w" orien="R180" />
        <iomarker fontsize="28" x="368" y="1824" name="x" orien="R180" />
        <instance x="688" y="1712" name="XLXI_18" orien="R0" />
        <instance x="688" y="1888" name="XLXI_19" orien="R0" />
        <instance x="1024" y="1808" name="XLXI_20" orien="R0" />
        <instance x="688" y="2064" name="XLXI_21" orien="R0" />
        <branch name="XLXN_42">
            <wire x2="688" y1="1936" y2="1936" x1="656" />
        </branch>
        <instance x="432" y="1968" name="XLXI_25" orien="R0" />
        <branch name="z">
            <wire x2="688" y1="2000" y2="2000" x1="432" />
        </branch>
        <branch name="y">
            <wire x2="432" y1="1936" y2="1936" x1="400" />
        </branch>
        <iomarker fontsize="28" x="400" y="1936" name="y" orien="R180" />
        <iomarker fontsize="28" x="432" y="2000" name="z" orien="R180" />
        <instance x="1344" y="1888" name="XLXI_28" orien="R0" />
        <branch name="XLXN_53">
            <wire x2="1632" y1="1792" y2="1792" x1="1600" />
        </branch>
        <instance x="1632" y="1824" name="XLXI_26" orien="R0" />
        <branch name="f2">
            <wire x2="1888" y1="1792" y2="1792" x1="1856" />
        </branch>
        <iomarker fontsize="28" x="1888" y="1792" name="f2" orien="R0" />
        <instance x="2144" y="1504" name="XLXI_38" orien="R0" />
        <branch name="y">
            <wire x2="2464" y1="1408" y2="1408" x1="2144" />
        </branch>
        <branch name="XLXN_60">
            <wire x2="2464" y1="1472" y2="1472" x1="2368" />
        </branch>
        <branch name="z">
            <wire x2="2144" y1="1472" y2="1472" x1="2112" />
        </branch>
        <branch name="XLXN_65">
            <wire x2="2752" y1="1264" y2="1264" x1="2720" />
            <wire x2="2784" y1="1216" y2="1216" x1="2752" />
            <wire x2="2800" y1="1216" y2="1216" x1="2784" />
            <wire x2="2752" y1="1216" y2="1264" x1="2752" />
        </branch>
        <branch name="XLXN_66">
            <wire x2="3088" y1="1184" y2="1184" x1="3056" />
            <wire x2="3088" y1="1184" y2="1232" x1="3088" />
            <wire x2="3120" y1="1232" y2="1232" x1="3088" />
        </branch>
        <branch name="XLXN_67">
            <wire x2="2912" y1="1440" y2="1440" x1="2720" />
            <wire x2="2912" y1="1296" y2="1440" x1="2912" />
            <wire x2="3120" y1="1296" y2="1296" x1="2912" />
        </branch>
        <branch name="f3">
            <wire x2="3392" y1="1264" y2="1264" x1="3376" />
            <wire x2="3408" y1="1264" y2="1264" x1="3392" />
        </branch>
        <iomarker fontsize="28" x="2144" y="1408" name="y" orien="R180" />
        <iomarker fontsize="28" x="2112" y="1472" name="z" orien="R180" />
        <iomarker fontsize="28" x="3408" y="1264" name="f3" orien="R0" />
        <instance x="3120" y="1360" name="XLXI_40" orien="R0" />
        <instance x="2464" y="1536" name="XLXI_41" orien="R0" />
        <instance x="2800" y="1280" name="XLXI_42" orien="R0" />
        <branch name="x">
            <wire x2="2416" y1="1120" y2="1120" x1="2160" />
        </branch>
        <iomarker fontsize="28" x="2160" y="1120" name="x" orien="R180" />
        <branch name="XLXN_56">
            <wire x2="2416" y1="1056" y2="1056" x1="2384" />
        </branch>
        <branch name="w">
            <wire x2="2160" y1="1056" y2="1056" x1="2128" />
        </branch>
        <instance x="2160" y="1088" name="XLXI_36" orien="R0" />
        <iomarker fontsize="28" x="2128" y="1056" name="w" orien="R180" />
        <iomarker fontsize="28" x="2144" y="1232" name="w" orien="R180" />
        <branch name="w">
            <wire x2="2160" y1="1232" y2="1232" x1="2144" />
            <wire x2="2464" y1="1232" y2="1232" x1="2160" />
        </branch>
        <instance x="2464" y="1360" name="XLXI_48" orien="R0" />
        <branch name="XLXN_57">
            <wire x2="2464" y1="1296" y2="1296" x1="2368" />
        </branch>
        <branch name="x">
            <wire x2="2144" y1="1296" y2="1296" x1="2112" />
        </branch>
        <instance x="2144" y="1328" name="XLXI_37" orien="R0" />
        <iomarker fontsize="28" x="2112" y="1296" name="x" orien="R180" />
        <instance x="2416" y="1184" name="XLXI_44" orien="R0" />
        <branch name="XLXN_87">
            <wire x2="2736" y1="1088" y2="1088" x1="2672" />
            <wire x2="2736" y1="1088" y2="1152" x1="2736" />
            <wire x2="2800" y1="1152" y2="1152" x1="2736" />
        </branch>
    </sheet>
</drawing>