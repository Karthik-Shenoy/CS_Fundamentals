# Operational Transforms
- traditional locks (Mutex/Semaphores) are pessimistic, they give turn based edit access to the clients (not feasible if we want the clients to be able to edit concurrently)
- `Optimistic Locking :` all the users can edit the resource at the same time, (if there's a conflict then we follow a few rules), the rules must be followed to ensure that all the local versions of the document converge to be consistent with each other (we don't want the local version of the clients to diverge from each other)

### synchronization issue
- synchronization of the operations made at the clients becomes a major issue, consider the following scenario
- every shared resource will have a version or a timestamp or a hash associated with it. 
- When a client reads the server data, it remembers the version associated with it. When client wants to write the new data back to the server, it should increment the version. 
- Now, if in the meantime, another client updates the data and the version, the first client cannot write it back since its local copy was not branched from this server version. 
- So, it should discard its local data, fetch the new server data again, and operate from start.

### Sync Strategy (Operational Transform)
- `Event Passing (Operational Transform) :` client sends raw events (operations performed at the local copy of the resource) to the server, this method is also called operation based sync.  
- The intention of `Operational Transformation algorithm` is to maintain and synchronize a consistent state between any number of users in a shared document in `high latency` environments such as Internet.

### Issue with sending plain operations
- whenever a local operation is performed on a resource at a client its state diverges, from the state of other clients
- after this step if we send the plain operation to the other clients, and perform them at the respective client's local, the final state will be completely different (divergent)
- To ensure converging behaviour (consistent state across all clients) we need a mechanism to sync the operation
- The final state should be independent of the order in which we perform the operations (To achieve this we use Operational Transformations)

### Transformation
- The transformation function is defined in code, will be different for different operations

### Bridge
