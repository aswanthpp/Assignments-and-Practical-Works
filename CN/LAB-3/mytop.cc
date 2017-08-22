
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

using namespace ns3;
using namespace std;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int
main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);
  
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (3);


  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer devices1,devices2,devices3;
  devices1 = pointToPoint.Install (nodes.Get(0),nodes.Get(1));
 devices2 = pointToPoint.Install (nodes.Get(1),nodes.Get(2));
 devices3 = pointToPoint.Install (nodes.Get(2),nodes.Get(0));

  InternetStackHelper stack;
  stack.Install (nodes);

      
  Ipv4AddressHelper address1,address2,address3;
        address1.SetBase ("10.1.1.0", "255.255.255.0");
        address2.SetBase ("10.1.2.0", "255.255.255.0");
        address3.SetBase ("10.1.3.0", "255.255.255.0");

        Ipv4InterfaceContainer interfaces1 = address1.Assign (devices1);
        Ipv4InterfaceContainer interfaces2 = address2.Assign (devices2);
        Ipv4InterfaceContainer interfaces3 = address3.Assign (devices3);

        UdpEchoServerHelper echoServer1 (9);
        UdpEchoServerHelper echoServer2 (10);
        UdpEchoServerHelper echoServer3 (11);

 ApplicationContainer serverApps1 = echoServer1.Install (nodes.Get (0));
  serverApps1.Start (Seconds (1.0));
  serverApps1.Stop (Seconds (10.0));
        
ApplicationContainer serverApps2 = echoServer2.Install (nodes.Get (1));
  serverApps2.Start (Seconds (1.0));
  serverApps2.Stop (Seconds (10.0));

  ApplicationContainer serverApps3 = echoServer3.Install (nodes.Get (2));
  serverApps3.Start (Seconds (1.0));
  serverApps3.Stop (Seconds (10.0));




  UdpEchoClientHelper echoClient1 (interfaces1.GetAddress (1), 10);
  echoClient1.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient1.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient1.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApps1 = echoClient1.Install (nodes.Get (0));
  clientApps1.Start (Seconds (2.0));
  clientApps1.Stop (Seconds (10.0));


UdpEchoClientHelper echoClient2 (interfaces2.GetAddress (1), 11);
  echoClient2.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient2.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient2.SetAttribute ("PacketSize", UintegerValue (1024));


  ApplicationContainer clientApps2 = echoClient2.Install (nodes.Get (1));
  clientApps2.Start (Seconds (2.0));
  clientApps2.Stop (Seconds (10.0));


UdpEchoClientHelper echoClient3 (interfaces3.GetAddress (1), 9);
  echoClient3.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient3.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient3.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApps3 = echoClient3.Install (nodes.Get (2));
  clientApps3.Start (Seconds (6.0));
  clientApps3.Stop (Seconds (10.0));


  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
