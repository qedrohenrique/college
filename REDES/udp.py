from ns import ns
import argparse

# Argument parser
parser = argparse.ArgumentParser(
    description="Configure the number of station nodes.")
parser.add_argument("--num_station_nodes", type=int,
                    required=True, help="Number of station nodes (mandatory)")
parser.add_argument("--enable_mobility", type=bool, required=True,
                    help="Enable mobility for station nodes (mandatory: True or False)")
args = parser.parse_args()

num_station_nodes = args.num_station_nodes
enable_mobility = args.enable_mobility

#
#   Options - Change as you wish
#

grid_width = 5
sim_duration = 10.0
server_start = 1.0
server_end = 9.0
client_start = 2.0
client_end = 8.0

#
#   Nodes
#

serverNodes = ns.NodeContainer()
serverNodes.Create(1)
apWifiNodes = ns.NodeContainer()
apWifiNodes.Create(1)
staWifiNodes = ns.NodeContainer()
staWifiNodes.Create(num_station_nodes)

#
#   Wifi Config
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

ssid = ns.Ssid("Equipe3")

wifiMac.SetType("ns3::ApWifiMac", "Ssid", ns.SsidValue(ssid))
apDevices = wifiHelper.Install(wifiPhy, wifiMac, apWifiNodes)

wifiMac.SetType("ns3::StaWifiMac", "Ssid", ns.SsidValue(ssid))
staDevices = wifiHelper.Install(wifiPhy, wifiMac, staWifiNodes)

#
#   Mobility
#

mobility = ns.MobilityHelper()
mobility.SetPositionAllocator(
    "ns3::GridPositionAllocator",
    "MinX",
    ns.DoubleValue(0.0),
    "MinY",
    ns.DoubleValue(0.0),
    "DeltaX",
    ns.DoubleValue(5.0),
    "DeltaY",
    ns.DoubleValue(10.0),
    "GridWidth",
    ns.UintegerValue(3),
    "LayoutType",
    ns.StringValue("RowFirst"),
)
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel")
mobility.Install(apWifiNodes)

if (enable_mobility):
    mobility.SetMobilityModel(
        "ns3::RandomWalk2dMobilityModel",
        "Bounds",
        ns.RectangleValue(ns.Rectangle(-100, 100, -100, 100)),
    )
mobility.Install(staWifiNodes)


#
#   Point to Point (AP to Server)
#

pointToPoint = ns.PointToPointHelper()
pointToPoint.SetDeviceAttribute("DataRate", ns.StringValue("5Mbps"))
pointToPoint.SetChannelAttribute("Delay", ns.StringValue("2ms"))

p2pDevicesAp = pointToPoint.Install(serverNodes.Get(0), apWifiNodes.Get(0))

#
#   Internet Stack
#

stack = ns.InternetStackHelper()
stack.Install(apWifiNodes)
stack.Install(staWifiNodes)
stack.Install(serverNodes)

#
#   Address
#

address = ns.Ipv4AddressHelper()
address.SetBase("10.0.0.0", "255.255.255.0")
apInterface = address.Assign(apDevices)
staInterface = address.Assign(staDevices)

address.SetBase("10.0.3.0", "255.255.255.0")
p2pInterfacesAp = address.Assign(p2pDevicesAp)

#
#   Applications
#


packetSinkServer = ns.PacketSinkHelper(
    "ns3::UdpSocketFactory",
    ns.InetSocketAddress(ns.InetSocketAddress(
        ns.Ipv4Address.GetAny(), 9)).ConvertTo(),
)

serverApps = packetSinkServer.Install(serverNodes.Get(0))
serverApps.Start(ns.Seconds(server_start))
serverApps.Stop(ns.Seconds(server_end))

address = p2pInterfacesAp.GetAddress(0)
socketAddr = ns.InetSocketAddress(address, 9)
onoff = ns.OnOffHelper("ns3::UdpSocketFactory", socketAddr.ConvertTo())
onoff.SetAttribute("MaxBytes", ns.UintegerValue(4096))
clientAppsWireless = onoff.Install(staWifiNodes)
clientAppsWireless.Start(ns.Seconds(client_start))
clientAppsWireless.Stop(ns.Seconds(client_end))

#
#  Simulation and other stuff
#

ns.Ipv4GlobalRoutingHelper.PopulateRoutingTables()

flowmonHelper = ns.FlowMonitorHelper()
flowmonHelper.InstallAll()

ns.Simulator.Stop(ns.Seconds(sim_duration))
ns.Simulator.Run()
has_mobility_suffix = "_mobility" if enable_mobility else ""
flowmonHelper.SerializeToXmlFile(
    (f'ns3-unifesp/output/udp_{num_station_nodes}{has_mobility_suffix}.xml'), True, True)
ns.Simulator.Destroy()

print(serverApps.Get(0).GetTotalRx())
