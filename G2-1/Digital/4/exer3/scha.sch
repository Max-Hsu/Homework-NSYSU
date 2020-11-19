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
        <signal name="F1" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="F2" />
        <signal name="F3" />
        <port polarity="Input" name="w" />
        <port polarity="Input" name="x" />
        <port polarity="Input" name="y" />
        <port polarity="Input" name="z" />
        <port polarity="Output" name="F1" />
        <port polarity="Output" name="F2" />
        <port polarity="Output" name="F3" />
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <blockdef name="xor4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="60" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="208" y1="-160" y2="-160" x1="256" />
            <arc ex="64" ey="-208" sx="64" sy="-112" r="56" cx="32" cy="-160" />
            <line x2="64" y1="-208" y2="-208" x1="128" />
            <line x2="64" y1="-112" y2="-112" x1="128" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <arc ex="128" ey="-208" sx="208" sy="-160" r="88" cx="132" cy="-120" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="208" ey="-160" sx="128" sy="-112" r="88" cx="132" cy="-200" />
        </blockdef>
        <block symbolname="xor2" name="XLXI_1">
            <blockpin signalname="x" name="I0" />
            <blockpin signalname="w" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="z" name="I0" />
            <blockpin signalname="y" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_3">
            <blockpin signalname="XLXN_6" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="F1" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_4">
            <blockpin signalname="z" name="I0" />
            <blockpin signalname="y" name="I1" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_5">
            <blockpin signalname="XLXN_15" name="I0" />
            <blockpin signalname="x" name="I1" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_6">
            <blockpin signalname="XLXN_16" name="I0" />
            <blockpin signalname="w" name="I1" />
            <blockpin signalname="F2" name="O" />
        </block>
        <block symbolname="xor4" name="XLXI_7">
            <blockpin signalname="z" name="I0" />
            <blockpin signalname="y" name="I1" />
            <blockpin signalname="x" name="I2" />
            <blockpin signalname="w" name="I3" />
            <blockpin signalname="F3" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1056" y="1264" name="XLXI_1" orien="R0" />
        <instance x="1056" y="1520" name="XLXI_2" orien="R0" />
        <instance x="1536" y="1376" name="XLXI_3" orien="R0" />
        <branch name="w">
            <wire x2="1056" y1="1136" y2="1136" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="1024" y="1136" name="w" orien="R180" />
        <branch name="x">
            <wire x2="1056" y1="1200" y2="1200" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="1024" y="1200" name="x" orien="R180" />
        <branch name="y">
            <wire x2="1056" y1="1392" y2="1392" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="1024" y="1392" name="y" orien="R180" />
        <branch name="z">
            <wire x2="1056" y1="1456" y2="1456" x1="1024" />
        </branch>
        <iomarker fontsize="28" x="1024" y="1456" name="z" orien="R180" />
        <branch name="XLXN_5">
            <wire x2="1424" y1="1168" y2="1168" x1="1312" />
            <wire x2="1424" y1="1168" y2="1248" x1="1424" />
            <wire x2="1536" y1="1248" y2="1248" x1="1424" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1424" y1="1424" y2="1424" x1="1312" />
            <wire x2="1424" y1="1312" y2="1424" x1="1424" />
            <wire x2="1536" y1="1312" y2="1312" x1="1424" />
        </branch>
        <branch name="F1">
            <wire x2="1824" y1="1280" y2="1280" x1="1792" />
        </branch>
        <iomarker fontsize="28" x="1824" y="1280" name="F1" orien="R0" />
        <instance x="992" y="1952" name="XLXI_4" orien="R0" />
        <instance x="1408" y="1952" name="XLXI_5" orien="R0" />
        <instance x="1856" y="1952" name="XLXI_6" orien="R0" />
        <branch name="y">
            <wire x2="992" y1="1824" y2="1824" x1="960" />
        </branch>
        <iomarker fontsize="28" x="960" y="1824" name="y" orien="R180" />
        <branch name="z">
            <wire x2="992" y1="1888" y2="1888" x1="960" />
        </branch>
        <iomarker fontsize="28" x="960" y="1888" name="z" orien="R180" />
        <branch name="x">
            <wire x2="1408" y1="1824" y2="1824" x1="1376" />
        </branch>
        <iomarker fontsize="28" x="1376" y="1824" name="x" orien="R180" />
        <branch name="w">
            <wire x2="1856" y1="1824" y2="1824" x1="1824" />
        </branch>
        <iomarker fontsize="28" x="1824" y="1824" name="w" orien="R180" />
        <branch name="XLXN_15">
            <wire x2="1296" y1="1856" y2="1856" x1="1248" />
            <wire x2="1296" y1="1856" y2="1888" x1="1296" />
            <wire x2="1408" y1="1888" y2="1888" x1="1296" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="1728" y1="1856" y2="1856" x1="1664" />
            <wire x2="1728" y1="1856" y2="1888" x1="1728" />
            <wire x2="1856" y1="1888" y2="1888" x1="1728" />
        </branch>
        <branch name="F2">
            <wire x2="2144" y1="1856" y2="1856" x1="2112" />
        </branch>
        <iomarker fontsize="28" x="2144" y="1856" name="F2" orien="R0" />
        <instance x="1280" y="2480" name="XLXI_7" orien="R0" />
        <branch name="w">
            <wire x2="1280" y1="2224" y2="2224" x1="1248" />
        </branch>
        <iomarker fontsize="28" x="1248" y="2224" name="w" orien="R180" />
        <branch name="x">
            <wire x2="1280" y1="2288" y2="2288" x1="1248" />
        </branch>
        <iomarker fontsize="28" x="1248" y="2288" name="x" orien="R180" />
        <branch name="y">
            <wire x2="1280" y1="2352" y2="2352" x1="1248" />
        </branch>
        <iomarker fontsize="28" x="1248" y="2352" name="y" orien="R180" />
        <branch name="z">
            <wire x2="1280" y1="2416" y2="2416" x1="1248" />
        </branch>
        <iomarker fontsize="28" x="1248" y="2416" name="z" orien="R180" />
        <branch name="F3">
            <wire x2="1568" y1="2320" y2="2320" x1="1536" />
        </branch>
        <iomarker fontsize="28" x="1568" y="2320" name="F3" orien="R0" />
    </sheet>
</drawing>