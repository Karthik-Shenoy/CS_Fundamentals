# Socket programming
- Add delimiters (as multiple messages can be read at once, `stream oriented` protocol)
- why does read system call take time and allow the buffer to be filled up (is it watermark)
    - blocking read with `timeout`, non blocking read.
- IO multiplexing
    - poll, select and epoll on a socket fd
- Non blocking IO sockets
    - non blocking Accept, IO multiplexing

## things to know 
- sub-netting, classless IP addresses

## What is a socket
- Socket can be thought of as one endpoint of a bi-directional communication channel
    - Socket follows same paradigm like other IO devices, remote streams data (), and the client buffers the data until the data is read, on reading the entire buffer is emptied
    - Usually the read call is blocking (to overcome this blocking nature and make sure our process stays responsive and is able to perform other tasks we should use the `Async I/O` paradigm)
- `How is Socket uniquely Identified`: A socket can be uniquely identified using the following pair (local_ip:local:port, remote_ip:remote_port)
- a single local port can be connected to multiple remote applications using different `remote_ip:remote_port` pairs
- consider the case where 2 applications are communicating with each other, client and remote apps have the following `IP:Port` pairs `192.168.1.1:5000` and `192.168.1.2:5001`
    - For 2 apps having the same IP addresses to have more than one connection, they both will need to use multiple ports

< diagram >


## socket address struct
- mostly networks use the big endian format (`When storing start with big`), but a few machines might store the data in memory in the little endian format (`when storing start from small`)
- `htonl() and htons()` methods basically convert the given long(32bits)/short(16bits) into network compatible format (returns the input as it is if the input is in network compatible format)
    - long is usually used for IP addresses (32bits) and short is used for port numbers(16bits)
- `AF (Address family) : ` an enum specifying the family of address the socket is going to use
    - IPv4: AF_INET
    - IPv6: AF_INET6
    - bluetooth: AF_BLUETOOTH

## Type gymnastics in C to mimic generics

## TCP connection backlog
- a socket will have a connection backlog queue, where connection requests will be queued up, if this queue is full then further connections will be rejected
    - the back log size needs to be determined based on time it requires to accept the next connection (time taken by the operations performed between accepts)
- The accept system call will pop a connection request from the backlog queue and establish a connection
- `SYN attacks and backlog size`
    - TCP SYN attack is one of the most popular DDOS attacks
    - if some malicious client keeps sending connection requests in a short period, a small backlog size will reject most of these connection requests, if the backlog is large, then the backlog might get flooded with SYN(`Handshake/connection`) requests
    - large backlog will eat up the memory space
    - both short and large backlogs are susceptible to SYN attacks, use dynamic backlog (automatically increases/decreases based on network conditions)

## Sockets
- `Server application`: A socket at the server will continuously be listening for new incoming connection requests (this is called a `Listening Socket`)
    - every time we accept a connection request we will create a new socket that will handle the communication with the clients
- `Client Application`: will have one socket which will connect to the server and then communicate with it
- `Accept` and `Recv` are blocking calls
- `Recv` returns -1 if there's some error with the connection, and returns number of bytes read on graceful communications


## Compiling on windows
- add linker flags (`-lwsock32 -lws2_32`) when compiling

### Things to remember about ports
- smaller ports `(0 to 1023)` are well known ports usually used for application level services/servers `(FTP:20/SSH:22/DNS:53/HTTP:80/HTTPS:443)`
- ephemeral ports `(ports lasting for a very short time)`, usually have a high value (1024 to 65535) used by client applications to connect to various services, multiple client applications use different ephemeral ports to connect to services
    - once the client app terminates the port, it is available for reuse by other client apps
    - Thus Client App ports are usually a large random number (16bit)
- A set of two `[IP:Port]` combinations uniquely identifies a communication
    - `([ClientIP:ClientPort],[ServerIP:ServerPort])`,