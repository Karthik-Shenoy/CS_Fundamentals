# Load Balancer
- when we have a `large amount of incoming requests` (only a single machine can not handle all these request) we will need multiple machines to serve all these requests
    - The request can come from multiple `geo-locations` (we will need multiple datacenters at multiple geolocations), each data center will have multiple machines
    - we need to distribute the load equally end ensure optimal utilization of resources (prevent under-utilization/starvation of resources)
- we will need multiple `Load balancers` to ensure optimal utilization of the resource
    - The Global Load balancer distributes load across data-centers, and the Data-center level load balancer distributes load across the machines in the particular datacenter (main thing to note here is `there will always be an hierarchy of load balancers` whose `hierarchy depth` will be decide by the `scale of the application`)
    - the load balancer routes requests to specific data-center/machine based on multiple factors (machine-health, geolocation, load etc)

## Consistent Hashing

### issue with using old method of hashing using MOD
- consider we have n servers, whiche serve large number of requests
- the incoming requests will have unique `request_id` (derived from uniform distribution, each id is equally likely to be chosen from the given `id_space`) 
- as the request_ids are uniformly random the requests will be uniformly distributed (almost uniformly distributed) among all the servers, if there are x requests each server will get x/n requests 
- but the above mentioned strategy is very fragile. when we want to add a new server, as we are using the `server = hash(request_id) % n` operator to route the requests based on the output of the hash function, the request routing logic will also chagne as n changes (where n is the number of servers)
    - on addition of a new server, the requests will bre routed to a different server than earlier (as n changes there by changing the roting logic -> `x mod n`)
    - usually the request_id remains `same for the same client` (computed from client_id)
    - the original server where the request was routed to, might have in memory cache of the frequently fetched data by the same client, so when new server is added the whole routing logic changes and the requests get routed to different servers and all the cached information becomes useless
    - in the case of `stateful service` (the session might need to `reloaded silently` => saved, shutdown at this machine and be opened at a separate machine)
    - the above mentioned issues cause a lot of problem when a new machine is added to the load balancer if we use just `mod n` as routing (where n is the numkber of machines)
- we can conclude that the issue is not load balancing but hashing which completely changes the routing data and causes large number of cache misses

### how consisting hashing solves the above mentioned issue
- we want to add new servers, while making sure that there is minimal change in the routing of requests (most of the old request_ids must be `consistently routed` to the same server, to avoid large amount of cache misses)
