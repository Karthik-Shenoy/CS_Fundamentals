# Consistency Patterns
- `Consistency models` decide the rules for the operations that can run in parallel, and the strategy to merge the results of those operations

## Strict Consistency
- All writes are instantly visible to all subsequent reads 
- consider that there are multiple reader and writer threads, competing for the CPU time, at a given instance of time only one thread can run on the CPU, assume that the threads share the same memory
- some variable/object will be used to synchronize the threads (synchronization decides the order in which the threads execute)
- The shared memory (critical section) must be mutually exclusive (only one thread can enter the critical section at a time)
- Atomic operations : operations that will be either completely executed or not executed at all. atomic operations can not be partially executed (atomic operations can not be interrupted midway)
- Only one thread (producer) can write to and read from the shared memory at a time, when writing/reading to the shared memory, the thread acquires a lock (the acquiring of lock is an atomic operation), and the other threads can not enter the critical section when one of the threads is writing to the shared memory
- blocking other threads from writing/reading, will cause loss of CPU time, This method works fine only in high frequency operations (in this case thread context switches occur at very high frequencies)
- employing this method in case of comparatively slower concurrent operations might cause a bad user experience as one of the producers remain blocked while other producer is writing  (example: users collaborating on a document, users commenting at the same time)

## Sequential Consistency
- Superset of Sequential consistency, each thread/client has their own cache (copy of the shared resource), all the write operations go to a write queue and are broadcasted to all the threads/clients that have subscribed to this value, which then update their caches accordingly
- Follows a PUB/SUB model (Consumer threads subscribe to the write events) and a queue is maintained which holds all the write operations in a `Sequence`, A `log` is also maintained which stores all the writes/read operations in sequence of the order in which they occurred
- Every thread is sequentially consistent (appears to follow the same sequential ordering), in databases this concept is called serializability
- Used in multiprocessor computers, all writes are sent over the same shared BUS (the bus acts as the broadcasting write queue)
- Can be used with distributed systems with one controller process that controls all the reads and writes (usually used with applications where the reads exceed the number of writes)
- Sequential consistency allows parallel reads, there by improving the speed of the system

## FIFO Consistency
- Each thread/client has its own cache, but the clients use point to point links instead of broadcast
- Each operation is propagated to all the connected clients in the order they where performed at the given host/client (this in order nature gives this pattern it's name `FIFO`)
- Updates from the same host/clients get applied in order, but in case of updates from different clients there is no guarantee of proper  ordering
- To handle the updates that might come out of order, we need to write extra code (`Operational Transform`)
- No central write queue bottleneck, needs more programming, n^2 scaling of number of message
    - we can solve this issue by using in-order multicast (one channel to share one message with multiple clients,)
- same order of operation from the same process, but operations from different processes may interleave differently on each node.

## Release Consistency
- Use the Primitive Locks with FIFO consistency, and only propagate the operations that between the acquisition and release of the lock
- used in file-systems like google drive and drop box (File content is re-downloaded if the cache is stale)

## Eventual Consistency
- The system converges to a consistent state after finite amount of time, 
- Example : cross DC propagation of updates in a sharded/partitioned database (The diffs get propagated and merged eventually and everyone sees the same consistent view eventually) 
- APP Examples : Social media comments/posts


