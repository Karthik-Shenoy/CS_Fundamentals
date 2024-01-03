# Message/Task Queues
- LoadBalancer + Heartbeat + Task/Request persistence (Rabbit MQ)
- Use messages-queues when there is high throughput (input-rate) to a service which can not handle high throughput, Message queues basically persist `Messages`, until this service becomes free to perform that task 
- Messages are stored on the queue until they are processed and deleted. Each message is processed only once, by a single consumer
- Message queues can be used to decouple heavyweight processing, to buffer or batch work, and to smoothen spiky workloads.

## issue that Message Queue addresses
- large throughput can overwhelm (Long ops block all threads) the service and the message buffer might overflow, which will cause all the further messages to be lost making the system unreliable
- We can queue the request and make client side estimation to keep UI interactive until we get a response (the response from the server is the source of truth)

## Message/Task Queueing
- This architecture technique helps in separation of concerns in services (decoupled services), asynchronous communication, Send the request to the message queue (usually priority queue based on some rule)
- All the services just need to be coupled with the queues interface (services only know how to communicate with the queue)
- The request will eventually get response, when they are popped from the queue and processed, the message-queue acts like an interface between sender and receiver, the senders and receivers can be of any type, only thing is that they must know how to communicate to the queue 
- senders/receivers don't know about other's existence and messages are popped only on consumption
- Message queues `Event Driven`, They notify all the subscribers about events (the events and event-consumption-acknowledgement can be pushed by the queue to the client or polled by the client)
- `Separation of concerns : ` allows, services to scale independently, hot swapping of the components

### Message vs Task Queues
- Both have almost the same functionality, the only difference is one stores messages and allows asynchronous consumption of messages by subscribed services when they get free, and other allows services/threads to perform task when ever the threads become ready.
    - (Thread Pool (Task Queue))[]

## Back Pressure
- When the queue size increases significantly, and becomes larger than memory. this might causes a large number of cache misses and disk-IO operations
- This is because the queue will be split and some parts will be in memory and others will be in disk, and if successive queue reads span across the queue then, the process will keep swapping blocks of data in and out of the memory, and cause a lot of cache misses, thus the throughput becomes less (since a lot of time is wasted in reading from the queue)
- Back pressure helps in such situations by `limiting the queue size` (prevent queue size from exceeding the memory limit), as queue size is limited throughput is preserved and we get faster response times for the jobs/messages already in the queue
- once the Queue fills up the client gets a 503 HTTP response from the server (503 -> Service unavailable)
- `exponential backoff algorithm` helps us decide the time after which the client can retransmit the request, so that it gets queued and processed by the service

### Rate limiting
- Limiting the number of requests a service can accept in a certain period of time, if the service gets more requests than the limit in that window of time, only those requests get a `error 503 response`, the subsequent request post the window are `handled normally`.
-  This can help preventing DOS attacks from bringing down our services
- following are the types of rate limiting
    - User-Based/IP/Subnet rate limiting (limit throughput for particular user/IP/Subnet)
    - Geo-Location based (limit throughput for particular Geo-Location)
    - Server based: when servers are designed to handle specific traffic, we can rate limit specific types of traffic that certain servers can't handle smoothly
- Following are a few rate limiting algorithms
    - Time-Window based: allow only a certain number of requests during a given window of time, if there's large traffic, this algorithm might only process a few requests in the beginning of the window and other requests will keep getting back an error 503 response until the time window expires, and as there are large number of requests, the same thing keeps repeating.
    - Sliding-Time-Based-window:  a dynamic window moves across the time axis, which keeps the counter based on the current time instead of fix time, (N number of requests can be accepted in the `last X seconds`), instead of resetting the counter every X seconds, we keep track of the count of requests in the last X seconds (basically a `recount is triggered when a new request comes in` or at some time interval)
        - to implement the window logic a data-structure like balanced tree can be used where we can evict stale requests at periodic interval as the window moves (use binary search logic to identify all the stale requests)
    - Token-Bucket: A bucket will keep getting filled with fix number of tokens in a fixed amount of time, when a request comes at the server if the bucket has tokens a token will be deleted from the bucket and request will be processed, in case of token being empty the request will get a 503 error response
    - Leaky-Bucket: uses a buffer to buffer the requests, and the service consumes these request at uniform rate. if the buffer overflows then the requests get an error  503 response. 
- all the rate limiting related data is usually stored in a key value store like Redis (key: IP/UID/SubnetMask)

### Dropping vs Throttling Request in a rate limited service
- Dropping the request is useful when we care about security (in case of DDOS attacks), and predictable performance (dropping requests will ensure consistent perf of the service)
- throttling of requests: does not degrade user experience drastically like dropping requests, throttling/slowing down processing is beneficial in scenarios which require graceful degradation, for instance high-availability services during excessive traffic

### Exponential backoff





## Cloud services
- Amazon SQS (Simple Queue Service)

## Useful Links
- [Sliding window rate limiting](https://dev.to/melbably/rate-limiting-the-sliding-window-algorithm-280a#:~:text=The%20Sliding%20Window%20Algorithm%20is%20a%20time-based%20method,effective%20tool%20for%20rate%20limiting%20in%20various%20applications.)
