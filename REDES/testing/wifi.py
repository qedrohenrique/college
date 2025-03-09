from ns import ns

# Habilitar logs (opcional)
ns.LogComponentEnable("UdpEchoClientApplication", ns.LOG_LEVEL_INFO)
ns.LogComponentEnable("UdpEchoServerApplication", ns.LOG_LEVEL_INFO)

wifiMac = ns.WifiMacHelper()
wifiHelper = ns.WifiHelper()
wifiHelper.SetStandard(ns.WIFI_STANDARD_80211n)

wifiChannel = ns.YansWifiChannelHelper()
wifiChannel.SetPropagationDelay("ns3::ConstantSpeedPropagationDelayModel")
wifiChannel.AddPropagationLoss("ns3::FriisPropagationLossModel", "Frequency", ns.DoubleValue(5e9))

wifiPhy = ns.YansWifiPhyHelper()
wifiPhy.SetChannel(wifiChannel.Create())
wifiPhy.SetErrorRateModel("ns3::YansErrorRateModel")
wifiHelper.SetRemoteStationManager("ns3::ConstantRateWifiManager",
                                       "DataMode",
                                       ns.StringValue("HtMcs7"),
                                       "ControlMode",
                                       ns.StringValue("HtMcs0"))

networkNodes = ns.NodeContainer()
networkNodes.Create(2)
apWifiNode = networkNodes.Get(0)
staWifiNode = networkNodes.Get(1)

ssid = ns.Ssid("network");
wifiMac.SetType("ns3::ApWifiMac", "Ssid", ns.SsidValue(ssid));

apDevice = ns.NetDeviceContainer()
apDevice = wifiHelper.Install(wifiPhy, wifiMac, apWifiNode);

wifiMac.SetType("ns3::StaWifiMac", "Ssid", ns.SsidValue(ssid));

staDevices = ns.NetDeviceContainer()
staDevices = wifiHelper.Install(wifiPhy, wifiMac, staWifiNode);

mobility = ns.MobilityHelper()
mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                    "MinX", ns.DoubleValue(0.0),
                                    "MinY", ns.DoubleValue(0.0),
                                    "DeltaX", ns.DoubleValue(5.0),
                                    "DeltaY", ns.DoubleValue(10.0),
                                    "GridWidth", ns.UintegerValue(3),
                                    "LayoutType", ns.StringValue("RowFirst"))
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
mobility.Install(apWifiNode);
mobility.Install(staWifiNode);

stack = ns.InternetStackHelper()
stack.Install(networkNodes)

address = ns.Ipv4AddressHelper()
address.SetBase("10.0.0.0", "255.255.255.0")
apInterface = ns.Ipv4InterfaceContainer()
apInterface = address.Assign(apDevice)
staInterface = ns.Ipv4InterfaceContainer()
staInterface = address.Assign(staDevices)

echoServer = ns.UdpEchoServerHelper(9)

serverApps = echoServer.Install(staWifiNode)
serverApps.Start(ns.Seconds(1.0))
serverApps.Stop(ns.Seconds(10.0))

address = staInterface.GetAddress(0).ConvertTo()
echoClient = ns.UdpEchoClientHelper(address, 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(1))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(1.0)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(1024))

clientApps = echoClient.Install(apWifiNode)
clientApps.Start(ns.Seconds(2.0))
clientApps.Stop(ns.Seconds(10.0))

ns.Simulator.Run()
ns.Simulator.Destroy()

