# Redis in-memory caching
- stores `key-value pairs in-memory`, providing high read/write performance compared to traditional databases
- Redis is fast because it performs I/O at the Memory level (provides High throughput/data-rate, low latency)
    - memory I/O keeps the `code simple`, as there is no need of `opening and closing files`, we just need to write the data into some `quick access` data-structure like set
    - The only issue is the Dataset cannot be larger than the amount of primary memory
- Redis is `single threaded`, and uses I/O multiplexed single threaded read/write event loop (we usually think that the multi-threaded processes are always fast, but that is not the case here)
- Multi-Threaded Read/Write applications require a lot of synchronization mechanisms like (exclusive and shared locks), this adds a lot of complexities and makes the code bug prone
- I/O multiplexing is used to overcome the problem of thread getting blocked on a single request (wait on a single socket connection, even when there's a request on a separate socket)
- Using the I/O multiplexing provided by the operating system A single thread waits on multiple sockets connection simultaneously

## I/O multiplexing
