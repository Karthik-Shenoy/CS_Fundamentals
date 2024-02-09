# Server Side Caching

- sometimes we might need to cache large amounts of data and the primary memory is insufficient to cache large amount of data, in such cases data can be `cached on disk` too, (Message brokers such as Kafka can cache massive amount of messages on the disk too)
- Some load balancers (`reverse proxies` can act as load balancers) can cache the server responses to reduce the load on the backend servers (avoid re-computation of the unchanged data at the backend)

### Kafka Disk caching
- The messages can be consumed asynchronously at it's own pace, and can be persisted over large amount of time
- the cached data is not lost when the system goes down (thus based on the retention policy we can cache data for long periods of time)

### Optimizing requests to a Distributed cache
- to maintain the Application Server to the Cache server affinity we use consistent hashing, as we cache the most frequently requested data to a given app-server in the corresponding cache server
< AppServer + LB + CacheServer >

### Redis in-memory caching
- stores key-value pairs in-memory, providing high read/write performance compared to traditional databases
- Redis is fast because it performs I/O at the Memory level (provides High throughput/data-rate, low latency)
    - memory I/O keeps the code simple, as there is no need of opening and closing files, we just need to write the data into some quick access data-structure like set\
    - The only issue is the Dataset cannot be larger than the amount of primary memory
- Redis is `single threaded`, and uses I/O multiplexing single threaded read/write event loop (we usually think that the multi-threaded processes are always fast, but that is not the case here)
- Multi-Threaded Read/Write applications require a lot of synchronization mechanisms like (exclusive and shared locks), this adds a lot of complexities and makes the code bug prone
- I/O multiplexing is used to overcome the problem of thread getting blocked on a single request (wait on a single socket connection, even when there's a request on a separate socket)
- Using the I/O multiplexing provided by the operating system A single thread waits on multiple sockets connection simultaneously

### I/O multiplexing

## Caching in Relational Database

### WAL (Write ahead Log)
- The description of the operation is written to write ahead log before being indexed in a B-Tree (usually used to recover from failure and synchronization between various DB replicas)

### Buffer Pool
- area used to `cache query results`

### Materialized View
- pre-compute `frequently requested queries` for faster performance

### Transaction Log
- Record all transactions and the updates made to the database

### Replication Log
- tracks replication state in a database cluster
