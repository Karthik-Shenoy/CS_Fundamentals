# Database Indexing and Locking

### Prerequisites
- The data is stored in the disk sequentially (sequential with respect to address) in the form of blocks (collection of bytes)
- when we want to read some bytes from the disk, we first load the entire block (to which those bytes belong to) onto the memory
- To optimize the performance of the app we need to minimize the number of blocks being pushed in and out of the memory 
    - Store Frequently accessed data in the same block/nearby blocks (We can not decide which block the data is being inserted in, as it is inserted at random by the user)
    - Know in advance which blocks to look for when data is being queried (`Indexing`)
    - we can use a combination of the above mentioned ideas to increase performance (Store the indexes in nearby blocks)

## Database Indexing

## Database locking (Row Level Locks)
- There are 2 kinds of locks (an exclusive lock and a shared lock)
    - `Exclusive lock (single user Read/Write) : ` When a user acquires an exclusive lock on the row, no user can acquire any kind of lock on that row. the row is exclusively written on by the user (All the write ops acquire an exclusive lock)
    - `Shared Lock (Multi user Read only) : ` When a user acquires a shared lock on the row, `no user can acquire an exclusive lock on that row (no writes allowed)`, but multiple shared locks are allowed on a single row thus multiple clients can perform reads on a particular row by acquiring a shared lock, and `preventing any row level write ops when` reading the row.
- These locks where created to ensure high consistency and preserve Transactional (ACID properties) nature of the operations



## Useful Links
- [indexing overview](https://www.youtube.com/watch?v=3G293is403I&t=877s)
- 