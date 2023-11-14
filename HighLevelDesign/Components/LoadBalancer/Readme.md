# Load Balancer
- when we have a `large amount of incoming requests` (only a single machine can not handle all these request) we will need multiple machines to serve all these requests
    - The request can come from multiple `geo-locations` (we will need multiple data-centers at multiple geo-locations), each data center will have multiple machines
    - we need to distribute the load equally end ensure optimal utilization of resources (prevent under-utilization/starvation of resources)
- we will need multiple `Load balancers` to ensure optimal utilization of the resource
    - The Global Load balancer distributes load across data-centers, and the Data-center level load balancer distributes load across the machines in the particular data-center (main thing to note here is `there will always be an hierarchy of load balancers` whose `hierarchy depth` will be decide by the `scale of the application`)
    - the load balancer routes requests to specific data-center/machine based on multiple factors (machine-health, geo-location, load etc)

## The client/backend-pool connection connection
- Load-balancing is one of the subset features of a reverse proxy
- the client never really knows about the individual servers in the backend pool of the load-balancer, the client sends the request to the load-balancers IP-address (obtained through DNS), which then forwards the load to one of the servers in the backend pool using one of the following distribution methods (hash-based, round-robin, session-persistance/sticky sessions)
    - The server sends the response back to the load balancer's IP address, which forwards the message back to the right client by matching the destination IP-address. The client only sees the Load balancer's IP address, and doesn't really care which server responds to the request (some times it does care in case of persistent connections like web-sockets)
- There are 2 types of load-balancers, based on the OSI-layer at which they operate.
    - `Layer 4 Load balancer : ` works at the transport layer, it does not know any details about the HTTP request, it can only see the segments being sent (which do not convey any information on their own, because of encryption). no need of TLS handshake between the load-balancer and the client.
    - `Layer 7 Load balancer : ` works at the application layer, it knows about the details of HTTP request (it decrypts the packet, and reads the headers) based on the data in the headers it makes smart routing choices, as the message is decrypted it can be cached. the client and Load-balancer need to perform a TLS handshake to share the keys (without decryption smart routing based on header data is not possible)

### difference between layer 4 and layer 7 load-balancers
- `Layer 4 Load balancer : ` works at the transport layer, it does not know any details about the HTTP request, it can only see the segments being sent (which do not convey any information on their own, because of encryption). no need of TLS handshake between the load-balancer and the client.
    - based on the forwarding rule (round-robin, num_connections, sticky_sessions) the TCP connection is formed between the client and one of the servers in teh backend pool of the load-balancer (the load-balancer forwards any segment to teh appropriate servers using its NAT table entry)
    - the NAT table entry is made based on the server decided by the forwarding rule, there is no TCP connection formed between the client and load-balancer, thus no state (seq_num and window size) maintained at the client, except for NAT table entries. The only rowe of the Load balancer is to forward the segments
    - The TCP connection is not a physical route, but the state of the other host that both the hosts maintain (sequence number, window size, max segment size) which is decided based on the TCP 3 way handshake (the handshake segments are also forwarded thus forming only one connection with one of the servers from load-balancer's backend pool)
    - TLS handshake is performed between one of the servers in the backend bool and the client
    - Can not cache the data, because it does not know any thing about the requests/responses, only knows the segment. there by it does not know which response should be sent to which request (as it can not decrypt the request)
    
- `Layer 7 Load balancer : ` works at the application layer, it knows about the details of HTTP request (it decrypts the packet, and reads the headers) based on the data in the headers it makes smart routing choices, as the message is decrypted it can be cached. the client and Load-balancer need to perform a TLS handshake to share the keys (without decryption smart routing based on header data is not possible)
    - Load-balancer decrypts the request and based ont he header data it forwards the request to the appropriate server, based on the forwarding rules (round-robin, hash-based, sticky-session)
    - Layer 7 Load balancer can see what the actual request and response was, thus they can cache the data, and respond to appropriate requests with the cached data.
    - TLS handshake is needed between the Load-balancer and the client (to retrieve the cached data, and responses)
    - 2 TCP connections are needed, one between the client and load balancer, and another between the load balancer and the servers in the backend pool
    - TCP connections with the backend servers can be pooled, and one of the connections can be used to forward the requests rather than spinning up and closing connections for every request (expensive TCP + TLS handshake is needed for connection setup)
    - `connection pooling : ` create connections and keep the alive in waiting state, and as soon as a request arrives use one of the connections for forwarding instead of creating a new connection
    - as handshakes, decryption and 2 connections are needed at the layer 7 load balancer it is more expensive to maintain.

### issue with using old method of hashing using MOD
- consider we have n servers, whiche serve large number of requests
- the incoming requests will have unique `request_id` (derived from uniform distribution, each id is equally likely to be chosen from the given `id_space`), and we distribute requests based on the `mod value with respect to number of servers (n)` of these request id
- as the request_ids are uniformly random the requests will be uniformly distributed (almost uniformly distributed) among all the servers, if there are x requests each server will get x/n requests 
- but the above mentioned strategy is very fragile. when we want to add a new server, as we are using the `server = hash(request_id) % n` operator to route the requests based on the output of the hash function. 
- the request routing logic will also chagne as n changes (where n is the number of servers)
    - on addition of a new server, the requests will be routed to a different server than earlier (as n changes there by changing the routing logic -> `x mod n`)
    - usually the request_id remains `same for the same client` (computed from client_id)
    - the original server where the request was routed to, might have in memory cache of the frequently fetched data by the same client, so when new server is added the whole routing logic changes and the requests get routed to different servers and all the cached information becomes useless
    - in the case of `stateful service` (the session might need to `reloaded silently` => saved, shutdown at this machine and be opened at a separate machine)
    - the above mentioned issues cause a lot of problem when a new machine is added to the load balancer if we use just `mod n` as routing (where n is the numkber of machines)
- we can conclude that the issue is not load balancing but inconsistent hashing which completely changes the routing data and causes large number of cache misses, on addition/removal of servers

### how consisting hashing solves the above mentioned issue
- we want to add new servers, while making sure that there is minimal change in the routing of requests (most of the old request_ids must be `consistently routed` to the same server, to avoid large amount of cache misses)

## Consistent Hashing
- The approach of solving the inconsistent, hashing when we add/remove servers (when n changes), to keep the `position of the server consistent on the request space`
- thereby making sure that the request mapping does not go through drastic change on addition/removal of servers. 
- one way map the servers on to the request space (`by hashin the serverID`) and redirect all the requests to the `next nearest mapped server`
- even on addition/removal of the server the hash of the serverID remains the same, thus there won't be a large change in the mapping of the requests, thereby avoiding large number of cache misses
- as the hashes are uniformly random we can expect the distance between them to me `Uniform`, as the distance is Uniform the load is uniform (on average)

## issue and fix
- although theoretically the load on each server would be 1/n, but sometimes when we a sever is removed, we could `endup with a skewed distribution of load` (happens in case when we have few servers)
- `Fix : ` we can assign multiple virtual positions to the servers on the request space, so that the load is distributed uniformly (since we emulate large number of servers positions on the request space using only few servers)
    - we can map same server to multiple virtual positions by using multiple hash functions (h1, h2, h3....hk) and the same server multiple positions ---> (h1(req) % M, h2(req) % M, ....), there by distributing the load evenly (remember output of each hash function will be different) 
    - if we choose the number of hash functions (k) appropriatly (around log(M)) we can drastically reduce the likelyhood of skewed distribution of load  
    - when we remove a server we just have to remove all the k points of that server on the request space, and reasign (in a clockwise fashion) all the requests to different servers.


