from ns import ns

ns.LogComponentEnable("UdpEchoClientApplication", ns.LOG_LEVEL_INFO)
ns.LogComponentEnable("UdpEchoServerApplication", ns.LOG_LEVEL_INFO)

p2pNodes = ns.NodeContainer()
p2pNodes.Create(2)

csmaNodes = ns.NodeContainer()
csmaNodes.Add(p2pNodes.Get(1))
csmaNodes.Create(2)

pointToPoint = ns.PointToPointHelper()
pointToPoint.SetDeviceAttribute("DataRate", ns.StringValue("5Mbps"))
pointToPoint.SetChannelAttribute("Delay", ns.StringValue("2ms"))

p2pDevices = pointToPoint.Install(p2pNodes)

csma = ns.CsmaHelper()
csma.SetChannelAttribute("DataRate", ns.StringValue("100Mbps"))
csma.SetChannelAttribute("Delay", ns.TimeValue(ns.NanoSeconds(6560)))

csmaDevices = csma.Install(csmaNodes)

stack = ns.InternetStackHelper()
stack.Install(p2pNodes.Get(0))
stack.Install(csmaNodes)

address = ns.Ipv4AddressHelper()
address.SetBase(ns.Ipv4Address("10.1.1.0"), ns.Ipv4Mask("255.255.255.0"))
p2pInterfaces = address.Assign(p2pDevices)

address.SetBase(ns.Ipv4Address("10.1.2.0"), ns.Ipv4Mask("255.255.255.0"))
csmaInterfaces = address.Assign(csmaDevices)

echoServer = ns.UdpEchoServerHelper(9)

serverApps = echoServer.Install(csmaNodes.Get(nCsma.value))
serverApps.Start(ns.Seconds(1.0))
serverApps.Stop(ns.Seconds(10.0))

echoClient = ns.UdpEchoClientHelper(csmaInterfaces.GetAddress(nCsma.value).ConvertTo(), 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(1))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(1.0)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(1024))

clientApps = echoClient.Install(p2pNodes.Get(0))
clientApps.Start(ns.Seconds(2.0))
clientApps.Stop(ns.Seconds(10.0))

ns.Ipv4GlobalRoutingHelper.PopulateRoutingTables()

pointToPoint.EnablePcapAll("second")
csma.EnablePcap("second", csmaDevices.Get(1), True)

ns.Simulator.Run()
ns.Simulator.Destroy()                  