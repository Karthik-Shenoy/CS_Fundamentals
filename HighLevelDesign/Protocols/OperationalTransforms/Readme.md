# Operational Transforms

## Operations
- Any changes to the shared resource is considered as `operation`
- let's consider the following operations on text `insert(char c, int index)` which inserts the given character at the given index, `delet(int index)` deletes the character at the given index


## Rules
- To synchronize clients they should start from a common origin state (initial state)
- each operation must have a time-stamp associated with it, and a version number (helps in ordering the operations)

## Operation Transforms
- Operation Transforms are transformed operations such that he following property holds
- We converge the state of the client and server using the transformed operations
- In the case of text we need to transform the remote-operations based on all the previous operations applied at the client
- All the operations are sent to the server, server broadcasts the transformed operation to the other clients

## Bridges
- When client keeps performing operations, before the server can send the transforms of the operations it received, the client and server may go out of sync
- bridges are basically the transforms of the operations sent by the server computed at the client with respect to the previously performed operations (Thus we need to buffer all the operations at the client to form bridges)
- Client needs to buffer the bridges and apply them after all the operations have been acknowledged
- we also have to buffer the bridges, and apply them 
- bridges bring client and server to a common intermediate state and prevents client and server from diverging

### State space
- the space client and server traverses, when processing through operations
    - left traversal is caused by client operation
    - right traversal is caused by server operation
- To ensure consistency we need to keep track of the state space of each of the clients, maintaining this at server will require massive amount of memory
- we maintain the server state space (in some data structure) at the server
- each client maintains its own state space, and the server's state space

### Server rules
- server orders the operations, and updates all the clients with the order of operation.

### Client Rules
- send one operation at a time, (buffer the operations if multiple ones are done)
- each delta must be acknowledged by the server (client waits for ACK)
- client then transforms the cached operations to form before sending it to the server (based on the server's state)
- when client receives back the operation it knows it's time to perform operational transform and converge

### Main Idea
- Take the complexities away from the Server and move it to client side, to improve perf.
    