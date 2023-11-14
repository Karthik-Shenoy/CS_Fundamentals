# Message Queues
- LoadBalancer + Hearbeat + Task/Request persistence (Rabbit MQ)
- Messages are stored on the queue until they are processed and deleted. Each message is processed only once, by a single consumer
- Message queues can be used to decouple heavyweight processing, to buffer or batch work, and to smoothen spiky workloads.

## issue that Message Queue addresses
- large throughput can overwhelm (Long ops block all threads) the service and the message buffer might overflow, which will cause all the further messages to be lost making the system unreliable
- We can queue the request and make client side estimation to keep UI interactive until we get a response (the response from the server is the source of truth)

## Message Queueing
- architecture technique that helps in seperation of concerns in services (decoupled services), asynchronous communication, Send the request to the message queue (usually priority queue based on some rule)
- The request will eventually get response, when they are popped from the queue and processed, the messae queue acts like an interface between sender and reciever, the senders and recievers can be of any type, only thing is that they must know how to communicate to the queue 
- senders/receivers dont know about other's existence and messages are popped only on consumption
- Message queues `Event Driven`, They notify all the subscribers about events (the events and event-consumption-acknowledgemnet can be pushed by the queue to the client or polled by the client)
- `Seperation of concerns : ` allows, services to scale independently, hot swapping of the components

## Cloud services
- Amazon SQS (Simple Queue Service)
