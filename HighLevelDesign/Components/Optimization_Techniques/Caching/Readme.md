# Caching
- helps improving effeciency of the system by storing frequently requested data at a place which can be accessed faster (by the consumer) than sending a request to the original producer
- usually a system will have several layer of caching, at each layer we have multiple strategies for caching data, which can be chosen based on the constraints of the system

## Prevelancy of Caching within a computer
- usually in a computer we will 3 levels of CPU hardware cache namely L1-cache, L2-cache and L3-cache
    - L1 cache is the fastest and the smallest cache, typicallt integrated on to the CPU
    - L2 cache is Slower than L1 but is larger in size
    - L3 cache is the slowest out of the 3 but has the largest size, shared across CPU cores
- Translation Lookaside Buffer (TLB): stores the most recently used virtual to physical address translations/mappings, allows faster conversion of virtual to physical address thereby speeding up the process of accessing memory

## how caching is used in traditional system application architecture
- `Client Side Caching` in the app frontend, the web-browsers can cache (at `Client Side Cache`) HTTP responses to enable faster retrieval of the data, 
- when the user requests data over HTTP for the first time, it is returned with an `expiration policy (cache invalidation timer)` in the HTTP header, when the same HTTP request, the response can be retrieved from the cache instead of the server based on the timer.
- `CDNs` used to improve the delivery speeds of static content (Images, videos, and other web assets)
- Messages can be cached on disk for a specified period of time based on the retention policy (message brokers such as Kafka allows us to cache messages on the disk)
- Distributed Caches

## caching in relational databases
- write ahead log