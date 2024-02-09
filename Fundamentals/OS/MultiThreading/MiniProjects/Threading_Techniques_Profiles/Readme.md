## Working efficiently with threads
- Working with threads does not have a lot of overhead compared to processes, because context switching between threads is very easy (we just need to use different stack, registers, and program counter) (no TLB flush is needed as we will be using the same address space)
    - when switching between process, we need to swap a lot of stuff (the entire TLB needs to be flushed as we will be using a separate page table), load page table, swap other process data from the swap file if the process is outside the memory

## Multi threading approaches
1. Spinning up as many threads as possible
2. Spin up a set number of threads, and divide the task among them
3. Spin up a thread pool, break the tasks into smallest quantization unit and distribute among the threads
- dividing the tasks and synchronizing the threads is a complex


## Moving components
- Data Reversal Services (orchestrates all the multithreading approaches)
- File collection (Data-store class : only stores and retrieves data)
- Thread Pool: (responsible for the orchestration of the threads in processing the tasks pushed to thread pool)


## The file collection
- `Thread safe read/writes`: the reads and writes are thread safe, if no more than one thread reads/writes from/to a given memory location (each key maps to a given memory location)
- operations that manipulate the collection/collection-size are not thread safe (add a file/folder to the collection) 



## Catching Bugs in Multithreaded applications
- don't pass pointers to stack allocated values (undefined behavior if this pointer is used after object goes out of scope)
- How randomness of preemption can be an issue for correctness
    - write unit tests
- (Try catch in C++ (Debugger stack trace))[https://stackoverflow.com/questions/28553609/stdexceptions-what-returns-stdexception]