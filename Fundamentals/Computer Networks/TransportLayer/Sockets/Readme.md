### Things to remember about ports
- smaller ports `(0 to 1023)` are well known ports usually used for application level services/servers `(FTP:20/SSH:22/DNS:53/HTTP:80/HTTPS:443)`
- ephemeral ports `(ports lasting for a very short time)`, usually have a high value (1024 to 65535) used by client applications to connect to various services, multiple client applications use different ephemeral ports to connect to services
    - once the client app terminates the port, it is available for reuse by other client apps
    - Thus Client App ports are usually a large random number (16bit)
- A set of two `[IP:Port]` combinations uniquely identifies a communication
    - `([ClientIP:ClientPort],[ServerIP:ServerPort])`,