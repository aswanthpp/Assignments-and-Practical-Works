/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: George F. Riley<riley@ece.gatech.edu>
 */

#include <iostream>

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/netanim-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-layout-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{
  Config::SetDefault ("ns3::OnOffApplication::PacketSize", UintegerValue (512));
  Config::SetDefault ("ns3::OnOffApplication::DataRate", StringValue ("500kb/s"));

  uint32_t    nLeftLeaf = 5;
  uint32_t    nRightLeaf = 5;
  uint32_t    nLeaf = 0; // If non-zero, number of both left and right
 
  NodeContainer nodes;
  nodes.Create (102);

  

  // Create the point-to-point link helpers
  PointToPointHelper pointToPointRouter;
  pointToPointRouter.SetDeviceAttribute  ("DataRate", StringValue ("10Mbps"));
  pointToPointRouter.SetChannelAttribute ("Delay", StringValue ("2ms"));
  PointToPointHelper pointToPointLeaf;
  pointToPointLeaf.SetDeviceAttribute    ("DataRate", StringValue ("100Mbps"));
  pointToPointLeaf.SetChannelAttribute   ("Delay", StringValue ("1ms"));

  
NetDeviceContainer devices[101];
devices[0] = pointToPointRouter.Install (nodes.Get(0),nodes.Get(1));
for(int i=2;i<=51;i++){
devices[i] = pointToPointLeaf.Install (nodes.Get(0),nodes.Get(i));
}
for(int i=52;i<=101;i++){
devices[i] = pointToPointLeaf.Install (nodes.Get(1),nodes.Get(i));
}
  // Install Stack
  InternetStackHelper stack;
  stack.Install(nodes);

 Ipv4AddressHelper ip1,ip2,ip3;
 ip1.SetBase ("10.1.1.0", "255.255.255.0");
 ip2.SetBase ("10.1.2.0", "255.255.255.0");
 ip3.SetBase ("10.1.3.0", "255.255.255.0"); 
 // Assign IP Addresses

        Ipv4InterfaceContainer i1 = ip1.Assign (devices[0]);


        NetDeviceContainer device1,device2;
        for(int i=2;i<=51;i++){
                device1.Add(nodes.Get(i));
        }
        for(int i=52;i<=101;i++){
                device2.Add(nodes.Get(i));
        }
        
        Ipv4InterfaceContainer i2 = ip2.Assign (device1);
        Ipv4InterfaceContainer i3 = ip3.Assign (device2);
 
        Ipv4GlobalRoutingHelper::PopulateRoutingTables();


        BulkSendHelper source ("ns3::TcpSocketFactory",
                         InetSocketAddress (i3.GetAddress(node2), 9));
  source.SetAttribute ("MaxBytes", UintegerValue (maxBytes));
  ApplicationContainer sourceApps = source.Install (node1);

  sourceApps.Start (Seconds (0.0));
  sourceApps.Stop (Seconds (10.0));

PacketSinkHelper sink ("ns3::TcpSocketFactory",
                         InetSocketAddress (Ipv4Address::GetAny (), port));
  ApplicationContainer sinkApps = sink.Install (nodes.Get (node2));
  sinkApps.Start (Seconds (0.0));
  sinkApps.Stop (Seconds (10.0));
  




  
  Simulator::Run ();
 //std::cout << "Animation Trace file created:" << animFile.c_str ()<< std::endl;
  Simulator::Destroy ();
  return 0;
}
