# DNS 
- is a good example for a basic distributed system (it is distributed over the entire world, and handles high traffic and provides high availability)
    - good starting point to understand how to build highly available, low latency systems (and how consistency becomes a bottle neck as we try to improve on availability)

<img style="display: block; margin: 2rem auto;" src="DNS_Hierarchical_Design.jpeg">

## The Lifecycle of a DNS query
1. the browser sends the DNS query to ISP-DNS resolver (`recursive resolver/re-cursor`), or a `public DNS resolver` based on how the device is configured, 
    - examples for public DNS resolvers are (Google-DNS, Cloudflare DNS --> 1.1.1.1) they are often faster than ISP DNS resolver servers, the DNS resolver caches all the name-server responses (Authoritative/TLD/Root), so that it can serve the subsequent DNS queries faster
    - The DNS resolver either responds with the cached IP addresses or requests the root-name-severs for the IP address 
2. The DNS resolver forwards the DNS query to the nearest DNS Root-Name-Server for resolution using [anycast](../../../Fundamentals/Computer%20Networks/NetworkLayer/Anycast/Readme.md)
3. there ar 13 IPs for the root name servers (there are hundreds of machines behind a give root name server IP), anycast routing is used to route the queries to these machines
4. Root name server responds wit the IP address to the appropriate TLD server based on the URL extension (.com, .in ...) big orgs maintain these TLD (`Top level domain name servers`), and the query is then forwarded to the TLD name server
5. the TLD name server returns the appropriate authoritative name server (owned by the hosting platforms), and the query is forwarded to the authoritative server
6. all the name-servers (Authoritative/TLD/root) use anycast which provides sufficient load balancing, routing, fault tolerance capabilities, thus making the system highly available with low latency.
    - All the servers and dns-resolvers have some form of cache, to reduce response latency, and this cache might get stale if not invalidated properly (`causing consistency issues`)

- there are 13 logical `Root Nameservers`
- many physical servers behind each of the `13 IP Addresses`
- If the DNS resolvers doesn't have the corresponding IP Address for a particular query, it  sends the DNS query to the closest Root-Name-server using `Anycast`

<img style="display: block; margin: 2rem auto; " width="400px" src="AnycastRouting.png">

- Root Nameservers forward the query to a `Top level domain (TLD) Name-server`
- TLD Nameservers have the IP Addresses of all the `Authoritative Nameservers` for all domains under them
- Authoritative Nameservers provide an **authoritative answer (final answer)** to a dns query
- When we register a domain name we register it with one of the Authoritative Nameservers
- The hierarchical design makes DNS highly decentralized and robust
- DNS update propagation is slow because there is a `TTL` on each `cached record`, thus we will have to wait for the TTL to expire before making any updates, hence when creating new `cached records` keep small TTL

<img style="display: block; margin: 2rem auto; " width="400px" src="TTL.png">

- Some of the DNS servers are buggy and take some time to get updated, hence de-commissioning a server might cause the incoming requests to be redirected to the wrong ( old IP address ), hence de-commission a server only when the incoming traffic is sufficiently low

<img style="display: block; margin: 2rem auto; " width="400px" src="CacheUpdate.png">

### What protocol does DNS use
- DNS usually uses UDP with retries, but some tasks (tasks with large response packet size) utilize TCP, to ensure reliability, DNS servers are usually run on `port 53`. a DNS query comprises of a single request-response cycle.
- We do not need DNS to be a blocker for loading the website, thus we use UDP which is fast, because unlike TCP does not require any handshakes or round trips.


