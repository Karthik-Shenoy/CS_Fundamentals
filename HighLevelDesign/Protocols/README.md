# WEB RTC (Real time communication)
- Standardized API which finds the most effecient (low latency) `peer to peer` path to exchange data
- If there's a server (turn hop / reverse proxy) which acts as a broker for the communication it adds an overhead
# WEB RTC Overview
1. A finds out all possible ways the public can connect to it, and all the supported media and security (encryption, media formats)
    - The public IP address (Exposed by the router NAT)
2. B performs the same operation and finds all possible ways that public can connect to it, and all the supported media formats and encryption
3. All this collected information is stored in the form of a big string (Session Descriptor), A and B signal the session information with each other through some other Protocol (HTTP, Web Sockets, QR, Message)
4. If there already exists a connection over HTTP or Web Sockets why do we need Web RTC ?
    - Web RTC finds an optimal (Low Latency Path) for 2 way real time communication unlike the other protocols.
5. once the session descriptor is shared A can conenct to B using WEB RTC and start communicating

## Network Address Translation ( NAT )
- If the public IP address is exposed without a `firewall`, hackers can start sending malicious packets and target the device, it is possible to use public IP with a firewall for better protection
- But when we have large number of devices, assigning public IPs for each of the devices and setting up Firewall rules would be a hassle
- Thus people use NAT (on the `router`) which acts as an extra layer of protection.
- The device connected to the router get a local IP address, and the NAT public IP (Routers Public IP) would be exposed (and the `NAT public IP will be assigned a firewall`)

- Interface:  Each endpoint which can be assigned an IP in the network (Ethernet port)  (A WIFI connection => 2 end points), switches don't have an IP they use MAC addresses(physical addresses) to forward the packets

<div style="display: flex; justify-content: center; flex-direction: column;">
    <img src="./WEB_RTC/images/NAT.png" alt="Windows">
</div>

-  In the above diagram the router has 2 interfaces, f0/0 has a private IP address  and is connected to the private IP and the other interface f0/1 has a public IP
- who ever wants to send data to the devices (PC1, PC2, PC3) will have to hit the routers public `NAT configured interface` first, which will be then forwarded to the right device using the `NAT table`

### How packets are sent over NAT
- consider that the client is sending a get request to the server, and it responds with the data and status (200 OK)
- when we send a packet, we first check if the IP belongs to the same subnet using the subnet mask. If the IP doesn't belong to the same subnet then the Router forwards the packet into the public network
- when forwarding the packet the router replaces the sender's details(port, IP) with a random port and its public IP, and this `mapping is stored in the NAT table`
<div style="display: flex; justify-content: center; flex-direction: column;">
    <img src="./WEB_RTC/images/NAT_FORWARDING.png" alt="Windows">
</div>
- The response (200 OK) from the server is sent to the routers public NAT configured interface's IP

## ( STUN )

## ( TURN )

## ( ICE )

## SDP

## Signalling of SDP