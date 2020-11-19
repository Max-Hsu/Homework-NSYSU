#!/usr/bin/python

"""
linuxrouter.py: Example network with Linux IP router

This example converts a Node into a router using IP forwarding
already built into Linux.

The example topology creates a router and three IP subnets:

    - 192.168.1.0/24 (r0-eth1, IP: 192.168.1.1)
    - 172.16.0.0/12 (r0-eth2, IP: 172.16.0.1)
    - 10.0.0.0/8 (r0-eth3, IP: 10.0.0.1)

Each subnet consists of a single host connected to
a single switch:

    r0-eth1 - s1-eth1 - h1-eth0 (IP: 192.168.1.100)
    r0-eth2 - s2-eth1 - h2-eth0 (IP: 172.16.0.100)
    r0-eth3 - s3-eth1 - h3-eth0 (IP: 10.0.0.100)

The example relies on default routing entries that are
automatically created for each router interface, as well
as 'defaultRoute' parameters for the host interfaces.

Additional routes may be added to the router or hosts by
executing 'ip route' or 'route' commands on the router or hosts.
"""

from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import Node
from mininet.log import setLogLevel, info
from mininet.cli import CLI
def ip(subnet,host,prefix=None):
    addr = '10.0.'+str(subnet)+'.' + str(host)
    if prefix != None: addr = addr + '/' + str(prefix)
    return addr
class LinuxRouter( Node ):
    "A Node with IP forwarding enabled."

    def config( self, **params ):
        super( LinuxRouter, self).config( **params )
        # Enable forwarding on the router
        self.cmd( 'sysctl net.ipv4.ip_forward=1' )

    def terminate( self ):
        self.cmd( 'sysctl net.ipv4.ip_forward=0' )
        super( LinuxRouter, self ).terminate()


class NetworkTopo( Topo ):
    "A LinuxRouter connecting three IP subnets"
    def build( self, **_opts ):
        rlist = []
        N_of_router = 1
        h1 = self.addHost('h1',ip=ip(0,10,24),defaultRoute = 'via '+ip(0,2))
        h2 = self.addHost('h2',ip=ip(N_of_router,10,24),defaultRoute = 'via '+ip(N_of_router,1))
        
        for i in range(1,N_of_router+1):
            ri = self.addHost('r'+str(i),cls=LinuxRouter)
            rlist.append(ri)
        self.addLink(h1,rlist[0],intfName1 = 'h1-eth0', intfName2 = 'r1-eth0')
        for i in range(1,N_of_router):
            self.addLink(rlist[i-1],rlist[i],intfName1 = 'r'+str(i)+'-eth1', intfName2 = 'r'+str(i+1)+'-eth0')
        self.addLink(rlist[N_of_router-1],h2,intfName1 = 'r'+str(N_of_router)+'-eth1', intfName2 = 'h2-eth0')
        '''
        defaultIP = '192.168.1.1/24'  # IP address for r0-eth1
        router = self.addNode( 'r0', cls=LinuxRouter, ip=defaultIP )

        s1, s2, s3 = [ self.addSwitch( s ) for s in 's1', 's2', 's3' ]

        self.addLink( s1, router, intfName2='r0-eth1',
                      params2={ 'ip' : defaultIP } )  # for clarity
        self.addLink( s2, router, intfName2='r0-eth2',
                      params2={ 'ip' : '172.16.0.1/12' } )
        self.addLink( s3, router, intfName2='r0-eth3',
                      params2={ 'ip' : '10.0.0.1/8' } )

        h1 = self.addHost( 'h1', ip='192.168.1.100/24',
                           defaultRoute='via 192.168.1.1' )
        h2 = self.addHost( 'h2', ip='172.16.0.100/12',
                           defaultRoute='via 172.16.0.1' )
        h3 = self.addHost( 'h3', ip='10.0.0.100/8',
                           defaultRoute='via 10.0.0.1' )

        for h, s in [ (h1, s1), (h2, s2), (h3, s3) ]:
            self.addLink( h, s )
        '''

def run():
    "Test linux router"
    topo = NetworkTopo()
    net = Mininet( topo=topo )  # controller is used by s1-s3
    net.start()
    N_of_routers = 1
    for i in range(1, N_of_routers+1):
        r = net['r'+str(i)]
        left_intf  = 'r'+str(i)+'-eth0'
        right_intf = 'r'+str(i)+'-eth1'
        r.cmd('ifconfig ' + left_intf + ' ' + ip(i-1, 2, 24))
        r.cmd('ifconfig ' + right_intf + ' ' +ip(i,   1, 24))
    for i in range(1,N_of_routers):
        r = net['r'+str(i)]
        right_intf = 'r' + str(i) + '-eth1'
        r.cmd('ip route add to ' + ip(N_of_routers,0,24) + ' via ' + ip(i,2) + ' dev ' + right_intf)
        print('ip route add to ' + ip(N_of_routers,0,24) + ' via ' + ip(i,2) + ' dev ' + right_intf)
    for i in range(2,N_of_routers+1):
        r = net['r'+str(i)]
        left_intf = 'r' + str(i) + '-eth0'
        r.cmd('ip route add to ' + ip(0,0,24) + ' via ' + ip(i-1,1) + ' dev ' + left_intf)
        print('ip route add to ' + ip(0,0,24) + ' via ' + ip(i-1,1) + ' dev ' + left_intf)
    CLI( net )
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'info' )
    run()
