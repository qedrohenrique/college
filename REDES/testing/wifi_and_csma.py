from ns import ns

ns.LogComponentEnable("UdpEchoClientApplication", ns.LOG_LEVEL_INFO)
ns.LogComponentEnable("UdpEchoServerApplication", ns.LOG_LEVEL_INFO)

#
#   Options
#

nCsma = 10
nWifi = 20

simulationDuration = 11.0

serverStart = 1.0
serverEnd = 10.0

clientStart = 2.0
clientEnd = 10.0

#
#   Nodes creation
#

serverNode = ns.NodeContainer()
serverNode.Create(1)

p2pNodes = ns.NodeContainer()
p2pNodes.Add(serverNode.Get(0))
p2pNodes.Create(1)

csmaNodes = ns.NodeContainer()
csmaNodes.Add(p2pNodes.Get(1))
csmaNodes.Create(nCsma)

apWifiNodes = ns.NodeContainer()
apWifiNodes.Add(serverNode.Get(0))
staWifiNodes = ns.NodeContainer()
staWifiNodes.Create(nWifi)

#
#  Wifi Configuration
#

wifiMac = ns.WifiMacHelper()
wifiHelper = ns.WifiHelper()
wifiHelper.SetStandard(ns.WIFI_STANDARD_80211n)

wifiChannel = ns.YansWifiChannelHelper()
wifiChannel.SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel")
wifiChannel.AddPropagationLoss(
    "ns3::FriisPropagationLossModel", "Frequency", ns.DoubleValue(5e9))

wifiPhy = ns.YansWifiPhyHelper()
wifiPhy.SetChannel(wifiChannel.Create())
wifiPhy.SetErrorRateModel("ns3::YansErrorRateModel")
wifiHelper.SetRemoteStationManager("ns3::ConstantRateWifiManager",
                                   "DataMode",
                                   ns.StringValue("HtMcs7"),
                                   "ControlMode",
                                   ns.StringValue("HtMcs0"))

ssid = ns.Ssid("network")

wifiMac.SetType("ns3::ApWifiMac", "Ssid", ns.SsidValue(ssid))
apDevices = wifiHelper.Install(wifiPhy, wifiMac, apWifiNodes)

wifiMac.SetType("ns3::StaWifiMac", "Ssid", ns.SsidValue(ssid))
staDevices = wifiHelper.Install(wifiPhy, wifiMac, staWifiNodes)

#
#   Mobility
#

mobility = ns.MobilityHelper()
mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                              "MinX", ns.DoubleValue(0.0),
                              "MinY", ns.DoubleValue(0.0),
                              "DeltaX", ns.DoubleValue(0.0),
                              "DeltaY", ns.DoubleValue(0.0),
                              "GridWidth", ns.UintegerValue(3),
                              "LayoutType", ns.StringValue("RowFirst"))
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel")
mobility.Install(apWifiNodes)
mobility.Install(staWifiNodes)

#
#   Stack
#

stack = ns.InternetStackHelper()
stack.Install(csmaNodes)
stack.Install(apWifiNodes)
stack.Install(staWifiNodes)

#
#   Network
#

pointToPoint = ns.PointToPointHelper()
pointToPoint.SetDeviceAttribute("DataRate", ns.StringValue("1Mbps"))
pointToPoint.SetChannelAttribute("Delay", ns.StringValue("2ms"))

csma = ns.CsmaHelper()
csma.SetChannelAttribute("DataRate", ns.StringValue("1Mbps"))
csma.SetChannelAttribute("Delay", ns.TimeValue(ns.NanoSeconds(6560)))

p2pDevices = pointToPoint.Install(p2pNodes)
csmaDevices = csma.Install(csmaNodes)

#
#   Ip configuration
#

address = ns.Ipv4AddressHelper()
address.SetBase(ns.Ipv4Address("10.1.1.0"), ns.Ipv4Mask("255.255.255.0"))
p2pInterfaces = address.Assign(p2pDevices)

address.SetBase(ns.Ipv4Address("10.1.2.0"), ns.Ipv4Mask("255.255.255.0"))
csmaInterfaces = address.Assign(csmaDevices)

address.SetBase(ns.Ipv4Address("20.1.1.0"), ns.Ipv4Mask("255.255.255.0"))
apInterface = address.Assign(apDevices)
staInterface = address.Assign(staDevices)

#
#   Applications
#

echoServer = ns.UdpEchoServerHelper(9)

serverApps = echoServer.Install(p2pNodes.Get(0))  # Server node
serverApps.Start(ns.Seconds(serverStart))
serverApps.Stop(ns.Seconds(serverEnd))

echoClient = ns.UdpEchoClientHelper(p2pInterfaces.GetAddress(0).ConvertTo(), 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(1000))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(0.2)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(4096))

clientApps = echoClient.Install(csmaNodes)
clientApps.Start(ns.Seconds(clientStart))
clientApps.Stop(ns.Seconds(clientEnd))

clientApps = echoClient.Install(staWifiNodes)
clientApps.Start(ns.Seconds(clientStart))
clientApps.Stop(ns.Seconds(clientEnd))

ns.Ipv4GlobalRoutingHelper.PopulateRoutingTables()

pointToPoint.EnablePcapAll("second")
csma.EnablePcap("second", csmaDevices.Get(1), True)

flowmonHelper = ns.FlowMonitorHelper()
flowmonHelper.InstallAll()

ns.Simulator.Stop(ns.Seconds(simulationDuration))
ns.Simulator.Run()
flowmonHelper.SerializeToXmlFile(("test.xml"), True, True)
ns.Simulator.Destroy()
