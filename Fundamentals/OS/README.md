# Operating System Fundamentals
Operating system is a software package (device drivers, utils, system libraries and kernel) that does the following things.
- creates environment to run apps on top of the hardware
- provides highlevel interface (GUI / CLI) to interact with the low level hardware (**`kernel acts as mediator`**)
- Manage Resources (network, storage, compute, I/O)
- Acts as the interface between the User and the hardware. **`Abstracts`** out the interaction with the hardware
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
- - `Stack`: The process Stack contains temporary (basically the data with a short socope/lifetime) data such as function params and return address of the variables. when the data, stored in the stack goes out of scope, this memory automatically gets freed. (Stack space is fixed and is allocated during runtime)
- - `Heap`: Dyanamically allocated memory (`Managed Memory`) to the process during run time (Variables created in heap have `user managed life time`)
- - Look into [Memory_Management] to get more insights into how `stack and heap` memory is managed
- - `Text`: Program Counters (pointer to the `current executing instruction`) and the contents of Processor's registers, (The registers are used to run the CPU level instructions in `assembly language`)
- - `Data`: Comnt


## Threads and Concurrency

## Scheduling

## Memory Management

## Interprocess Communication

## I/O management

## Virtualization

## Distributed File Systems

## Distributed Shared Memory

## References
1. [Important OS concpets blog](https://data-notes.co/the-10-operating-system-concepts-software-developers-need-to-remember-480d0734d710)


