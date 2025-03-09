from ns import ns
flowmonHelper = ns.FlowMonitorHelper()

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

apWifiNodes = ns.NodeContainer()
apWifiNodes.Create(1)
staWifiNodes = ns.NodeContainer()
staWifiNodes.Create(3)

ssid = ns.Ssid("network");

wifiMac.SetType("ns3::ApWifiMac", "Ssid", ns.SsidValue(ssid));
apDevices = wifiHelper.Install(wifiPhy, wifiMac, apWifiNodes);

wifiMac.SetType("ns3::StaWifiMac", "Ssid", ns.SsidValue(ssid));
staDevices = wifiHelper.Install(wifiPhy, wifiMac, staWifiNodes);

mobility = ns.MobilityHelper()
mobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                    "MinX", ns.DoubleValue(0.0),
                                    "MinY", ns.DoubleValue(0.0),
                                    "DeltaX", ns.DoubleValue(0.0),
                                    "DeltaY", ns.DoubleValue(0.0),
                                    "GridWidth", ns.UintegerValue(3),
                                    "LayoutType", ns.StringValue("RowFirst"))
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
mobility.Install(apWifiNodes);
mobility.Install(staWifiNodes);

stack = ns.InternetStackHelper()
stack.Install(apWifiNodes)
stack.Install(staWifiNodes)

address = ns.Ipv4AddressHelper()
address.SetBase("10.0.0.0", "255.255.255.0")
apInterface = address.Assign(apDevices)
staInterface = address.Assign(staDevices)

echoServer = ns.UdpEchoServerHelper(9)

serverApps = echoServer.Install(apWifiNodes.Get(0))
serverApps.Start(ns.Seconds(1.0))
serverApps.Stop(ns.Seconds(3.1))

address = apInterface.GetAddress(0).ConvertTo()
echoClient = ns.UdpEchoClientHelper(address, 9)
echoClient.SetAttribute("MaxPackets", ns.UintegerValue(1))
echoClient.SetAttribute("Interval", ns.TimeValue(ns.Seconds(1.0)))
echoClient.SetAttribute("PacketSize", ns.UintegerValue(1024))

clientApps = echoClient.Install(staWifiNodes)
clientApps.Start(ns.Seconds(1.2))
clientApps.Stop(ns.Seconds(3.0))

ns.Ipv4GlobalRoutingHelper.PopulateRoutingTables();
flowmonHelper.InstallAll()

ns.Simulator.Stop(ns.Seconds(3.2))
ns.Simulator.Run()
flowmonHelper.SerializeToXmlFile(("test.xml"), True, True)

ns.Simulator.Destroy()

