# Write Ahead Logs

### Prerequisites
- `Reliability` is one of the most important things for a Database/Storage service
- Usually Databases `persist data on disk` (no volatile memory), to make sure that the data is not lost in case of unforeseen circumstances like Database crash, OS crash, Power loss, etc.
- When ever an operation is performed the data is is updated/committed and the corresponding disk blocks are modified
    - each time we perform some commit (update/insert/delete) we need a disk IO operation
    - Disk IO is a complicated operation, to open a file from the disk, it has to be first loaded onto the memory and the descriptors need to be populated in the file table.
    - When writing to the disk we first write the data on to the in memory buffer, which then goes to the OS Buffer Cache followed by the disk cache and finally is written on to the disk (we can skip the cache writes by opening the file in sync mode)
    
### What is a Write Ahead Log (WAL)
- standard method for ensuring data integrity (Reliability)
- Core Idea : Before Making changes to the actual data on the disk (tables/indexes) write the log of the operations to a separate file (log the entire description of the change)
- Reads are not stored in WAL, only updates are stored

> This can be applied anywhere to achieve reliability not just Databases

- The Flow for WAL is as follows (when updated)
    - Log an entry in the WAL (The description of the operation, usually the queries are logged instead of the entire data) example: log a long ops query instead of each updated record (update millions of rows where a specific condition is true)
    - The Write operation on the Write ahead log is very fast (opened in sync/append mode), so if there's a crash during the `long operation`, the operation `can be rerun from the logs`, and the reliability is ensured

### Benefits of Write Ahead logs
- `No need flushing data to disk on every commit :` The commits can be buffered on the primary memory and a bulk update can be made asynchronously, as there is no risk of losing volatile data from the primary memory in case when there is a crash
- Recovery from failure can be achieved by replaying the logs.
- `Reduce number of disk writes` (WAL file is sequential/append-only, this significantly reduces the cost of the file update)
    - Databases allow you to change the flush frequency to control the number of disk writes
- `Point in time snapshot : ` of the database can be recovered, by applying the logs till a particular point in time

### Data integrity in WAL
- each Write ahead log is CRC-32 protected (Cyclic redundancy check)
- In case of crash when writing the log, The CRC helps in checking if the written log is valid, CRC also allows recovery of the corrupted log if sufficient data is present in the log

### Structure of WAL
- WAL is segmented into 16MB files, and the files are further broken down into smaller pages (based on the page size)
- Each line stores the byte offset of the entry (LOG Sequence Number), CRC and the operation description
    - 

