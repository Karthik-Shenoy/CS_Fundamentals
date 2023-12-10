# Caching
- helps improving efficiency of the system by storing frequently requested data at a place which can be accessed faster (by the consumer) rather than sending a request again to the original producer
- usually a system will have several layer of caching, at each layer we have multiple strategies for caching data, which can be chosen based on the constraints of the system

### Prevalence of Caching within a computer
- usually in a computer we will 3 levels of CPU hardware cache namely L1-cache, L2-cache and L3-cache
    - L1 cache is the fastest and the smallest cache, typically integrated on to the CPU
    - L2 cache is Slower than L1 but is larger in size
    - L3 cache is the slowest out of the 3 but has the largest size, and is shared across CPU cores
- Translation Look aside Buffer (TLB): stores the most recently used virtual to physical address translations/mappings, allows faster conversion of virtual to physical address thereby speeding up the process of accessing memory

### how caching is used in traditional system application architecture
- `Client Side Caching` in the app frontend, the web-browsers can cache HTTP responses to enable faster retrieval of the data, 
- when the user requests data over HTTP for the first time, it is returned with an `expiration policy (cache invalidation timer)` in the HTTP header, when the same HTTP request is made, the response can be retrieved from the cache instead of the server based on the timer.
- `CDNs` used to improve the delivery speeds of static content (Images, videos, and other web assets)
- Messages can be cached on disk for a specified period of time based on the retention policy (message brokers such as Kafka allows us to cache messages on the disk)

### Distributed caches
Caching helps a lot in distributed systems, if some requests are frequently made by a host (client/server/DB) then the results can be cached at the host with some `expiration policy` (to avoid stale data)
- Caching `reduces the number of network calls` happening in the distributed system
- `Reduces the Load on the servers/DBs`, Caching enables the client to hit the caches and get the cached data instead of hitting the servers/DBs and increasing the load on them and avoiding `Recomputation`
- `Things to keep in mind when using a cache : ` The main intention of using caches is the faster retrieval times from the caches when compared to recomputation and network calls
    - Storing large amount of data on caches, will slow the retrieval/lookup time. getting caches with large size doesn't make sense as the caches are stored in expensive storage devices like SSDs/Primary memory

### Cache policies
- as we know the amount of data that can be stored at the cache is limited/small, we need to set some data eviction policies, such that there is optimal usage of this space, and a lot of network calls and recomputation are avoided, we need to answer 2 questions to create an effective cache policy
    - `When to make an entry in the cache ?`
    - `When do we evict data from the cache ?`
- Examples for caching policy: LRU (least recently used), when making an entry keep it at the top, and remove the least recently used entry (oldest entry) from the cache. The number of entries in the cache at a time will be limited based on the cache size.
    - `Sliding window caching policy :` 
- `Why does LFU fail`
- There are 2 types of caches `Write through cache` and `Write Back cache`
    - Write through Cache : when ever there is an update request, it comes to the cache first, the cache is updated first, and the request is forwarded to the database and data base gets updated. if we have multiple servers with in memory caches writ through method makes the caches inconsistent
    - Write back cache : the update request directly goes to the data base, and write back the update to the cache (one more way is to send the request to the cache evict the entry to be updated, and update the database. the cache gets updated on subsequent requests to the updated resource)
    - Write back uses pub sub to update all the servers who have cached the particular resource in memory but this publishing requests to multiple servers (and might cause expensive high throughput network calls, as we are multi-casting every update)
    - main issue with write back is high throughput of updates and we know DBs are not good at handling high throughput
    - `Hybrid method : ` To improve efficiency buffer the write through updates on cache ar one server and forward the bulk updates with one network call, and then the DB (Writes back )publishes the bulk updates to the all the servers subscribed to the resources in one go. 
    - Hybrid method will only work when consistency is non-critical for the system, it wont work with systems that need high consistency (passwords/banks/finance data)
    - < Images for cache types with multiple server nodes >
    = draw cache type rank  based on consistency
> For an idea on LRU cache look at `./CachingAlgos/LRU`
 
### Issues with caching
- If we have a poor eviction policy and evict the frequently requested entries, then we will have to fall back to the DB for data, while making an `extra call` to the cache for lookup
- if there are frequent inserts and removals from the cache, with no real utilization (cache hits/retrievals) of the cache then it ends up reducing the overall efficiency (large number of cache misses)
    - cache miss => network call + cache lookup 
- data In-Consistency, we should `avoid caching` data which needs high consistency
- < Issue description Image >

### placing the caches at the right places
- `In Memory : ` placing the cache in memory at the server will provide with faster retrieval and is simple to implement
    - utilization of the servers memory space (block some space for the cache) might reduce the amount of load the server can handle.
    - Synchronization across the in memory caches between the server nodes is difficult, they can be come inconsistent with each other, which will lead to similar requests getting different responses based on the server responding to those requests
    - < In memory Caching Image >
- `Global Cache : ` A distributed global cache, sits between the server and the Data base (same router/machine-group same subnet/data-center). is more consistent, resilient, does not eat up server memory
    - The global cache would be multiple redis servers behind a reverse proxy (acts as load balancer), that respond with the data in cache, if there has been a cache hit
    - `on cache miss` the reverse proxy forwards the request to the DB, gets the response, caches it and sends the result back to the servers
    - Main thing to note here is that the redis does not have to compute the query results (no need of loading pages onto memory and buffering the results from each page), redis offers  a simple memory  lookup operation. thus the cache retrieval is faster, than actually querying the database
    - Both Redis and the DB calls are made over the network (but redis retrieval is faster)
    - < Global Caching Image >


# Useful Links
- [Why not LFU](https://en.wikipedia.org/wiki/Least_frequently_used)
- [Sliding expiration](https://steven-giesel.com/blogPost/b355a042-2c5b-4d96-b1ca-a9dc0fc23509#:~:text=In%20a%20sliding%20expiration%20window%2C%20the%20cache%20item,they%20remain%20in%20the%20cache%20longer%2C%20improving%20performance.)