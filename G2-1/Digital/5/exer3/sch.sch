<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="w" />
        <signal name="x" />
        <signal name="y" />
        <signal name="z" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="y3" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="y2" />
        <signal name="XLXN_21" />
        <signal name="XLXN_22" />
        <signal name="y1" />
        <signal name="y0" />
        <port polarity="Input" name="w" />
        <port polarity="Input" name="x" />
        <port polarity="Input" name="y" />
        <port polarity="Input" name="z" />
        <port polarity="Output" name="y3" />
        <port polarity="Output" name="y2" />
        <port polarity="Output" name="y1" />
        <port polarity="Output" name="y0" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
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
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="w" name="I" />
            <blockpin signalname="XLXN_21" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="x" name="I" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_3">
            <blockpin signalname="y" name="I" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_4">
            <blockpin signalname="z" name="I" />
            <blockpin signalname="y0" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_5">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_21" name="I2" />
            <blockpin signalname="y3" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_6">
            <blockpin signalname="y" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_21" name="I2" />
            <blockpin signalname="XLXN_18" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_7">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="x" name="I1" />
            <blockpin signalname="XLXN_21" name="I2" />
            <blockpin signalname="XLXN_19" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_8">
            <blockpin signalname="XLXN_19" name="I0" />
            <blockpin signalname="XLXN_18" name="I1" />
            <blockpin signalname="y2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="y" name="I0" />
            <blockpin signalname="XLXN_21" name="I1" />
            <blockpin signalname="y1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="848" y="928" name="XLXI_2" orien="R0" />
        <instance x="848" y="1040" name="XLXI_3" orien="R0" />
        <instance x="848" y="832" name="XLXI_1" orien="R0" />
        <branch name="w">
            <wire x2="832" y1="800" y2="800" x1="544" />
            <wire x2="848" y1="800" y2="800" x1="832" />
        </branch>
        <branch name="x">
            <wire x2="752" y1="896" y2="896" x1="544" />
            <wire x2="832" y1="896" y2="896" x1="752" />
            <wire x2="848" y1="896" y2="896" x1="832" />
            <wire x2="752" y1="896" y2="1504" x1="752" />
            <wire x2="1648" y1="1504" y2="1504" x1="752" />
        </branch>
        <branch name="y">
            <wire x2="656" y1="1008" y2="1008" x1="544" />
            <wire x2="720" y1="1008" y2="1008" x1="656" />
            <wire x2="832" y1="1008" y2="1008" x1="720" />
            <wire x2="848" y1="1008" y2="1008" x1="832" />
            <wire x2="720" y1="1008" y2="1344" x1="720" />
            <wire x2="1648" y1="1344" y2="1344" x1="720" />
            <wire x2="656" y1="1008" y2="1840" x1="656" />
            <wire x2="1648" y1="1840" y2="1840" x1="656" />
        </branch>
        <iomarker fontsize="28" x="544" y="800" name="w" orien="R180" />
        <iomarker fontsize="28" x="544" y="896" name="x" orien="R180" />
        <iomarker fontsize="28" x="544" y="1008" name="y" orien="R180" />
        <iomarker fontsize="28" x="544" y="1104" name="z" orien="R180" />
        <instance x="1632" y="928" name="XLXI_5" orien="R0" />
        <branch name="y3">
            <wire x2="1920" y1="800" y2="800" x1="1888" />
        </branch>
        <iomarker fontsize="28" x="1920" y="800" name="y3" orien="R0" />
        <instance x="1648" y="1408" name="XLXI_6" orien="R0" />
        <instance x="1648" y="1632" name="XLXI_7" orien="R0" />
        <branch name="XLXN_12">
            <wire x2="1280" y1="896" y2="896" x1="1072" />
            <wire x2="1360" y1="896" y2="896" x1="1280" />
            <wire x2="1280" y1="896" y2="1280" x1="1280" />
            <wire x2="1648" y1="1280" y2="1280" x1="1280" />
            <wire x2="1360" y1="800" y2="896" x1="1360" />
            <wire x2="1632" y1="800" y2="800" x1="1360" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="1152" y1="1008" y2="1008" x1="1072" />
            <wire x2="1632" y1="1008" y2="1008" x1="1152" />
            <wire x2="1152" y1="1008" y2="1568" x1="1152" />
            <wire x2="1648" y1="1568" y2="1568" x1="1152" />
            <wire x2="1632" y1="864" y2="1008" x1="1632" />
        </branch>
        <instance x="1984" y="1488" name="XLXI_8" orien="R0" />
        <branch name="XLXN_18">
            <wire x2="1936" y1="1280" y2="1280" x1="1904" />
            <wire x2="1936" y1="1280" y2="1360" x1="1936" />
            <wire x2="1984" y1="1360" y2="1360" x1="1936" />
        </branch>
        <branch name="XLXN_19">
            <wire x2="1936" y1="1504" y2="1504" x1="1904" />
            <wire x2="1936" y1="1424" y2="1504" x1="1936" />
            <wire x2="1984" y1="1424" y2="1424" x1="1936" />
        </branch>
        <branch name="y2">
            <wire x2="2272" y1="1392" y2="1392" x1="2240" />
        </branch>
        <iomarker fontsize="28" x="2272" y="1392" name="y2" orien="R0" />
        <instance x="1648" y="1904" name="XLXI_9" orien="R0" />
        <branch name="y1">
            <wire x2="1936" y1="1808" y2="1808" x1="1904" />
        </branch>
        <iomarker fontsize="28" x="1936" y="1808" name="y1" orien="R0" />
        <branch name="z">
            <wire x2="560" y1="1104" y2="1104" x1="544" />
            <wire x2="832" y1="1104" y2="1104" x1="560" />
            <wire x2="848" y1="1104" y2="1104" x1="832" />
        </branch>
        <branch name="XLXN_21">
            <wire x2="1104" y1="800" y2="800" x1="1072" />
            <wire x2="1136" y1="800" y2="800" x1="1104" />
            <wire x2="1216" y1="800" y2="800" x1="1136" />
            <wire x2="1344" y1="800" y2="800" x1="1216" />
            <wire x2="1216" y1="800" y2="1216" x1="1216" />
            <wire x2="1648" y1="1216" y2="1216" x1="1216" />
            <wire x2="1216" y1="1216" y2="1440" x1="1216" />
            <wire x2="1648" y1="1440" y2="1440" x1="1216" />
            <wire x2="1104" y1="800" y2="1088" x1="1104" />
            <wire x2="1104" y1="1088" y2="1104" x1="1104" />
            <wire x2="1104" y1="1104" y2="1776" x1="1104" />
            <wire x2="1648" y1="1776" y2="1776" x1="1104" />
            <wire x2="1344" y1="736" y2="800" x1="1344" />
            <wire x2="1632" y1="736" y2="736" x1="1344" />
        </branch>
        <instance x="848" y="1136" name="XLXI_4" orien="R0" />
        <branch name="y0">
            <wire x2="1088" y1="1104" y2="1104" x1="1072" />
            <wire x2="1088" y1="1104" y2="1200" x1="1088" />
            <wire x2="1088" y1="1200" y2="1200" x1="1072" />
            <wire x2="1072" y1="1200" y2="1216" x1="1072" />
        </branch>
        <iomarker fontsize="28" x="1072" y="1216" name="y0" orien="R90" />
    </sheet>
</drawing>