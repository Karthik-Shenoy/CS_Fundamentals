

## Index
1. Busy database
2. Chatty I/O (high throughput)
3. Extraneous fetching (high latency)

## Busy database anti-pattern

### pre-requisites
- `Stored Procedures` :  are user defined functions, which execute some piece of PL/SQL code and returns some result, they need to be executed explicitly 
- `Triggers` : are stored procedure that get invoked automatically when some event (INSERT/UPDATE/DELETE) occurs on a specific table, it is mainly used to ensure referential integrity is maintained across tables
    - we can validate data using a trigger when an insert event occurs, or compute some value for a new column

### The problem
- Busy database problem occurs when we use the database as a service instead of a repository, A database is a shared resource and will be used by many distributed servers, and if the database performs a lot of compute intensive processing, it might fail to accept client requests and fetch data (A Busy Database Becomes the bottleneck for the distributed system)
    - A `service` performs some compute intensive task, while as a repository only (stores data)/(helps in retrieval of data), we generally transmit the data from a repository to a separate compute resource (VM/server) and perform compute intensive tasks there.
    - Transmitting data over network requires the following steps: cloning the data, serializing, sending serialized data over network and deserialization, this process is costs us compute and network resources, so for `trivial compute tasks` we can utilize stored-procedures instead of transmitting data over the network
    - But the issue occurs when we have a `lot of stored-procedures` running on the data base, thus the `database becomes busy performing compute tasks` and might fail to accept new client requests and fetch the queried data 
    - Scaling out databases is not a trivial task (we can only scale-up to a certain limit)
- Databases are highly optimized for performing certain tasks like `aggregation of data over large datasets`, don't move such natively supported/optimized processing like aggregation out of the database
- We need to reduce the complexity of the processing the data at the database while keeping the amount of data transmitted over the network as minimum as possible
    - `we just need to find the the right balance between [Amount of processing] and [Amount of data transmitted over the network]`
    - If we transmit Large amount of data over the network then the `Network calls become the bottleneck` for the distributed system, when the network calls become bottleneck it is called [Extraneous Fetching Anti Pattern]()

### Considerations

### The fix


## Chatty IO
- File fragmentation
