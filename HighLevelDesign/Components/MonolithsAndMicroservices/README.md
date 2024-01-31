# Monoliths vs Microservice


## Components, interfaces and abstractions
- Good software is built using components, interfaces and abstractions
    - components: unit of software that can be upgraded independently or can be easily replaced with another component
    - interface: all the components are decoupled from each other by coupling them to interfaces, this allows us to replace components (given that the new component can implements the interface/contract)
    - abstractions: hide the implementation logic from the other components that are using it, so that the components can be used easily (it also prevents one component from getting coupled to the low level implementation details of other components)
    - remember abstractions and interfaces go hand in hand 

## Microservices
A microservice is a backend service that performs a specific function and communicates with other services. By dividing the functionalities of an app into microservices, we can achieve better scalability, flexibility, and maintainability.

Microservices can communicate over different APIs such as **REST**, **WebSockets**, and **RPC**. These are different communication styles that can be used depending on the nature and requirements of each service. For example, 
- **REST** is a common style for querying data from other services using HTTP request/response, 
- **WebSockets** enable bidirectional communication between services using TCP sockets. 
- **RPC** is a style that allows services to invoke procedures or methods on other services using a specific protocol such as gRPC⁴.

Another important aspect of microservice communication is whether it is **synchronous** or **asynchronous**³⁵. Synchronous communication means that the caller waits for a response from the receiver, while asynchronous communication means that the caller does not wait and the receiver sends a response later, usually through a message broker or an event stream³⁵. Asynchronous communication can help reduce **coupling** and improve scalability and availability of microservices.

> A microservice is a small, independent, and loosely coupled service that communicates with other services over well-defined APIs (each microservice has its own tech stack and databse)
> each microservice can `scale independently`

### PROS
- we can break the app into a group of smaller services (each service will run as a separate process)
    - We can code different services in different languages that specifically suite the functionality, and we can scale these services independently
    - the services use light weight mechanisms like grpc/http(rest)/TCP-Sockets(custom protocol)  to communicate with each other
- We can scale services independently (based on the load it is handling)
- Migration of the services becomes easy (We can do a hot replacement, no need of redeployment lke it is done in case of Monolithic architecture)