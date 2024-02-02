# Operating System Fundamentals
Operating system is a software package (device drivers, utils, system libraries and kernel) that does the following things.
- creates environment to run apps on top of the hardware
- provides highlevel interface (GUI / CLI) to interact with the low level hardware (**`kernel acts as mediator`**)
- Manage Resources (network, storage, compute, I/O)
- Acts as the interface between the User and the hardware. **`Abstracts`** out the interaction with the hardware
    - this abstraction can be a very highlevel abstraction (GUI windows) or low level system calls (File IO/ socket system calls) that programmers use
- Kernel is the core component of the operating system, that manages storage, compute, network and I/O
<div style="display: flex; justify-content: center;">
    <div style="flex: 50%; text-align: center;">
        <h3>Windows</h3>
        <img src="./images/OperatingSystyemKernelHierarchy.png" alt="Windows">
    </div>
    <div style="width: 10px;"></div> 
    <div style="flex: 50%; text-align: center;">
        <h3>Linux</h3>
        <img src="https://github.com/Karthik-Shenoy/CS_Fundamentals/blob/1f244a53a7117668d9803bdb081e79e4ef6dd28d/Fundamentals/OS/Images/KernelHierarchyLinux.jpg" alt="Linux">
    </div>
</div>

## Processes and Process Management
- Process is basically a Program (set of instrucions, stored in files => dll, exe, etc) which is in execution (loaded into the memory)
- when this program gets loaded on to the memory it becomes a process
- The process has 4 main sections (stack, heap, text and data)
    - `Stack`: The process Stack contains temporary data (basically the data with a short scope/lifetime) such as function param values (in case pass by value is used) and return address of the variables. when the data, stored in the stack goes out of scope, this memory automatically gets freed. (Stack space is fixed and is allocated during runtime)
    - `Heap`: Dyanamically allocated memory (`Managed Memory`) to the process during run time (Variables created in heap have `user managed life time`)
    - Look into [Memory_Management] to get more insights into how `stack and heap` memory is managed
    - `Text`: Program Counters (pointer to the `current executing instruction`) and the contents of Processor's registers, (The registers are used to run the CPU level instructions in `assembly language`)
    - `Data`: 

### Process and Thread Control Block Registers vs CPU registers
- The register in the process control blocks is data structure that stores the state (snapshot) of the CPU when the process is not running. 
- The CPU registers are small storage units inside the CPU that hold data, instructions, and the current status of the processor. 
- The registers in the process are used to save and restore the context of the process when it is switched in and out of the CPU. 
- The CPU registers are used to perform operations and access memory quickly and efficiently


## Threads and Concurrency

## Scheduling

## Memory Management
- Manage primary memory (RAM), and move processes back and forth between disk and main memory `during execution`
    - keep track of every memory location regarless of it being allocated to a process or free
    - how much memory is to be allocated at what time to a certain process
    - tracks allocation and deallocation of the memory
- each process gets its own `process address space`, that is a set of logical addresses that a process references in its code (example a 32 bit logical address can range from 0 to 0X7FFFFFFF -> first bit is zero rest all ones)
- OS maps the logical addresses to the physical address during the time of memory allocation to the process

## Inter process Communication

## I/O management

## Virtualization

## Distributed File Systems

## Distributed Shared Memory

## References
1. [Important OS concpets blog](https://data-notes.co/the-10-operating-system-concepts-software-developers-need-to-remember-480d0734d710)


