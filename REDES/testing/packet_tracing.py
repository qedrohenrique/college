from ns import ns
import os

flowmonHelper = ns.FlowMonitorHelper()

ns.LogComponentEnable("UdpEchoClientApplication", ns.LOG_LEVEL_INFO)
ns.LogComponentEnable("UdpEchoServerApplication", ns.LOG_LEVEL_INFO)

nodes = ns.NodeContainer()
nodes.Create(3)

pointToPoint = ns.PointToPointHelper()
pointToPoint.SetDeviceAttribute("DataRate", ns.StringValue("1Mbps"))
pointToPoint.SetChannelAttribute("Delay", ns.StringValue("2ms"))

devices1 = ns.NetDeviceContainer()
devices1.Add(pointToPoint.Install(nodes.Get(0), nodes.Get(1)))

devices2 = ns.NetDeviceContainer()
devices2.Add(pointToPoint.Install(nodes.Get(2), nodes.Get(1)))

stack = ns.InternetStackHelper()
stack.Install(nodes)

address = ns.Ipv4AddressHelper()
address.SetBase(ns.Ipv4Address("10.1.1.0"), ns.Ipv4Mask("255.255.255.0"))

interfaces1 = address.Assign(devices1)

echoServer = ns.UdpEchoServerHelper(9)

serverApps = echoServer.Install(nodes.Get(1))
serverApps.Start(ns.Seconds(1.0))
serverApps.Stop(ns.Seconds(10.0))

address = interfaces1.GetAddress(1).ConvertTo()
echoClient = ns.UdpEchoClientHelper(address, 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(5))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(1.0)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(4096))

clientApps = echoClient.Install(nodes.Get(0))
clientApps.Start(ns.Seconds(2.0))
clientApps.Stop(ns.Seconds(10.0))

address = ns.Ipv4AddressHelper()
address.SetBase(ns.Ipv4Address("20.1.1.0"), ns.Ipv4Mask("255.255.255.0"))
interfaces2 = address.Assign(devices2)

address = interfaces2.GetAddress(1).ConvertTo()
echoClient = ns.UdpEchoClientHelper(address, 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(5))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(1.0)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(4096))

clientApps = echoClient.Install(nodes.Get(2))
clientApps.Start(ns.Seconds(2.0))
clientApps.Stop(ns.Seconds(10.0))

flowmonHelper.InstallAll()

ns.Simulator.Stop(ns.Seconds(12.0))
ns.Simulator.Run()

flowmonHelper.SerializeToXmlFile(("test.xml"), True, True)

ns.Simulator.Destroy()
