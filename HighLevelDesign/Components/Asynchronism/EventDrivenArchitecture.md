# Event driven architecture
- This design pattern is used in both LLD and HLD of various systems
- Used for collaboration between services, if the state of some service changes then it notifies the concerned services that `observe/(might get affected by) this change`, 
- a poll based architecture is one where the `observer services` keep on polling the given service to see if it's state has changed, this continuous polling wastes resources like cpu cycles and network bandwidth (here the responsibility of getting a notification lies at the observer who continuously polls the service at hand enquiring if its state has changed)
- instead of a poll based architecture we can use an event driven architecture where its the responsibility of the subject/publisher to notify the observers/subscribers that it's state has changed
- on getting notified the observer performs some action based on the notification received
- `Example : ` Systems that use an EDA (event driven architecture) : React, Node.js, Git, 

## EDA in a distributed system
- `EventBuses:` act as brokers between publishers and subscribers (MQTT)
- the services become decoupled, they do not need to know where the event is coming from, they just need to know to communicate with event bus and process the events
- The Observers/Subscribers can store the latest event (that represents last known state) that they got from the `remote service`, this improves availability in the case where the remote-service/event-bus goes down, but it degrades the consistency of the system (as we might persist stale data). if we care about availability then we will need to settle with eventual consistency.
< overall EDA diagram >
- Persisting remote events at local store gives following advantages
    - improves visibility of issues, and gives good telemetry, thereby making debugging simpler
    - We can rollback events in the case of failure
    - replacing services becomes easy, we just need to replay the same `persisted events` on the new service and replace the old service
    < replace service diagram >
- `Transactional nature of events : ` we can have `guaranteed delivery` or `fire and forget` events
    - events also tell us on the intent (`what state was changed at remote`), and the observers can decide on the corresponding operation to perform based on the intent

## Cons of EDA
1. Eventual Consistency
2. If we get `time dependent response` to the operations triggered by the events, then replaying the events will get back different responses based on the time of replaying, thus the system can become inconsistent. `We usually get time dependent responses if the service is communicating with some external service (this mostly happens at the gateways/edge of the distributed system)`
3. We do not have `granular control over the interactions` (as we can only send events, which trigger some operation at some other service)
    - All the Control over the events lie with the event-bus/event-broker, the timer delay in events getting sent is decided based on the traffic at the event-bus, thus we might need complex logic of event-priority and priority-queue at the event-bus/broker to enforce constraints on the events.
    - We publish events when internal state of some service changes, we might want only particular services to get notified about this event and prevent others from getting notified, Implementing the pub sub model to allow certain events to be only seen by certain subscriber might add more complexity.
    - in case of request/response architecture, we had control over both the requests and responses sent by the event, we can also define time constraints on the requests and responses
4. `Rollback Complexity` : We can roll back to a particular state in 3 ways (the first 2 methods fail if we get time varying responses for the operation triggered by the event) `We do not want to end-up in an inconsistent state after roll back`
    - replay all the events (`can be done but costly`)
    - store the initial state followed by only diffs done by each event (`can be done for all but costly`)
    - we can improve efficiency by squashing all the events into a bulk event
    - undo the operations till certain point (`A few operations can not be undone`)
5. `Hidden Flow : `The flow of data between services is not easy to understand (as we might need to go through the internals of multiple event-brokers to understand the topics/publishers and subscribers to get to know how the data is flowing through the distributed system)
< get some diagram here >
6. migration of the system or a few services to a different architecture (like request/response) becomes difficult as the services get coupled to the event-bus/event-brokers 

## Applications of EDA
- EDA can be used to ensure that things are consistent, Events can be `time stamped` and `replayed/undone`
    - in case of consistency conflicts, we can go back in time (using undo operations on the event) or (by replaying all the events up till that certain timestamp) and resolve the conflicts (look at the following `game` example for more clarity)
    - we can also know the order in which the events occurred and transform the events based on the order to ensure consistency (Operational Transforms)
    - Events can also be logged along with the timestamp (better telemetry gathering) that allows us more visibility into the interaction between the services, and helps in easy debugging
-  