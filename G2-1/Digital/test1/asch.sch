<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="I1" />
        <signal name="I2" />
        <signal name="O1" />
        <port polarity="Input" name="I1" />
        <port polarity="Input" name="I2" />
        <port polarity="Output" name="O1" />
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
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="I2" name="I0" />
            <blockpin signalname="I1" name="I1" />
            <blockpin signalname="O1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1216" y="1136" name="XLXI_1" orien="R0" />
        <branch name="I1">
            <wire x2="1216" y1="1008" y2="1008" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="1184" y="1008" name="I1" orien="R180" />
        <branch name="I2">
            <wire x2="1216" y1="1072" y2="1072" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="1184" y="1072" name="I2" orien="R180" />
        <branch name="O1">
            <wire x2="1504" y1="1040" y2="1040" x1="1472" />
        </branch>
        <iomarker fontsize="28" x="1504" y="1040" name="O1" orien="R0" />
    </sheet>
</drawing>