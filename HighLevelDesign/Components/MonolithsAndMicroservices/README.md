# Monoliths vs Microservice

A microservice is a backend service that performs a specific function and communicates with other services. By dividing the functionalities of a web app into microservices, we can achieve better scalability, flexibility, and maintainability.

Microservices can communicate over different APIs such as **REST**, **WebSockets**, and **RPC**. These are different communication styles that can be used depending on the nature and requirements of each service. For example, 
- **REST** is a common style for querying data from other services using HTTP request/response, 
- **WebSockets** enable bidirectional communication between services using TCP sockets. 
- **RPC** is a style that allows services to invoke procedures or methods on other services using a specific protocol such as gRPC⁴.

Another important aspect of microservice communication is whether it is **synchronous** or **asynchronous**³⁵. Synchronous communication means that the caller waits for a response from the receiver, while asynchronous communication means that the caller does not wait and the receiver sends a response later, usually through a message broker or an event stream³⁵. Asynchronous communication can help reduce **coupling** and improve scalability and availability of microservices³⁵.

> A microservice is a small, independent, and loosely coupled service that communicates with other services over well-defined APIs (each microservice has its own tech stack and databse)
> each microservice can `scale independently`