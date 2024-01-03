# Streams and buffers

### Stream
- `Stream :` is a sequence of data that is moved from one point to another over time
    - a stream of data over the internet from one host to other
    - a stream of data being transferred from one file to another within the same PC
- we `stream data`, by breaking a `large File/object` into chunks and sending the chunks one by one from one point to other, rather than sending the entire large file/object in one go.
    - when streaming data the stream is processed in chunks (each chunk is processed separately) `rather than waiting for the entire data to be available`
    - makes the application more responsive, after processing the chunks are stored together at the destination by `writing these chunks on to the destination one by one`
    - there will be enough free memory for the processing of `small chunks`.
    - `Example :` large file transfer from one disk location to other, large file download over http, live streaming on youtube 
- `issues faced if we don't stream data`if we send the large file in one go the application has to wait for the entire file/object to arrive before processing it
    - the allocated `memory space might not be sufficient to store the entire large file/object` while processing 

### Buffers
- The rate at which data is produced and consumed might be vastly different, if the data production rate is very high and consumption is slow, then by the time `consumption/processing` is done at the consumer `a lot of data which was sent during processing/consumption will be lost`
    - if the consumption rate is faster than production. consumer `will poll for data unnecessarily` for multiple times which will waste the CPU cycles.
- `Buffers :` help in solving the issues with uneven data rates, 
    - in case when we are sending a large file, we buffer the chunks at the `WRITE_BUFFER`, and wait for it to reach a certain capacity we club the chunks together to form a bigger chunk and send it, instead of multiple smaller chunks, this reduces the number of messages sent over the medium
    - in the case when we are expecting a large file to be received in chunks, rather than consuming a small chunk every time it arrives, we buffer/store the chunks in the `READ_BUFFER`, and consume it when the buffer is filled to a certain capacity, this reduces the number of reads
    - `READ_BUFFER :` does not requiring polling to check if there is any data, it notifies the process when the buffer is filled more than certain capacity.
    - We can read from the buffer, when ever we want (when we read from the buffer the entire data is emptied/consumed)