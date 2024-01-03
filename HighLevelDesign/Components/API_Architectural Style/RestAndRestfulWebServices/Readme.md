# REST
architectural style which provides a standard way of communicating between computers over the web (uniform way to communicate with the systems over the web). REST compliant systems are called RESTful (Stateless and separation of concerns between server and client).

### Separation of concerns
- The client and server are decoupled, the can change independently, without the changes rippling to the other. but both must agree on how they are going to communicate (message format)
- The backend will expose a few REST endpoints, using the REST interface, and if the client knows the message format for requests and responses then they can communicate with each other.
- different clients across different platforms can use the REST Interface to get the data from the backend
- Both the client/Servers depend on REST interface and message format, as long as the message format and the REST Interface (Rest Endpoints) remains the same we can swap servers and clients without caring about the platform

<p align="center">
    <img src="./Images/REST INTERFACE.png" width="700px">
</p>

### Stateless server (Mandatory for Restful service)
- The server needs to be able to understand  the current request without remembering the context of the previous request, each request should be made such that it can be processed independently.
- each request must contain all the information necessary to understand it (we can not store any context on the server that would help us understand the request), session state is kept entirely on the client
- Reliability is improved, even if there is a failure there is no need to recover any lost state/context, as the request will have everything needed to understand it.
- Scalability : As there is no need of managing state, we do not need server affinity, `any server` can be used to respond to the request (as the request has all data needed for processing the request),
    - The resources can be freed up quickly as we do not need to managing any state between requests (The HTTP connection can be closed after the request is made)
- Issues : each request being sent will have extra overhead (repetitive/redundant information) which reduces the network perf
    - The server has less control over reliability and consistent app behavior, as the state is maintained at the client side. the consistency depends on the correct client implementation of the application state management

### Caching
- In order to improve network perf we can use [HTTP Caching](../../Optimization_Techniques/Caching/ClientSideCaching/Readme.md), we set the cache-flag at the server to notify if the response is cache-able, cache-able responses are cached and reused later for the equivalent requests.
- caching improves the user-perceived performance and efficiency by reducing the number of round-trips to the server, and increase availability (`use cached responses if the server is down`) but caching might reduce the reliability/consistency of the responses (as the users might get back stale responses)
- caching also introduced more complexity at the client side (cache eviction and management to ensure consistency)

### Uniform interface
- uniform interface guaranteed separation of concerns that enabled service to evolve independently in isolation, but it degraded the efficiency for some of the applications, as all the services (irrespective of the use-case) had to follow the same uniform standard to share information over the network.
- The REST interface is designed to be efficient for `large-grain hypermedia data transfer,` optimizing for the common case of the Web.
    - The header size is large to ensure reliable transmission of large files
    - connection establishment and management is complex to ensure reliability
    - usually clients request large data and filter whatever they want, implementing granularity (`request only what client wants`) is very complex and may cause the endpoints to get bloated (`"/user/food/spices/company?spice_id=a1"`)
- but this interface might not be optimal for all the other forms of interactions

### Resource
- any thing that can be named/identified is a resource (text/image/objects/file/)
- resources can be static or dynamic with respect to time, the `state of the resource` at any point in time is called as `resource representation`
    - the resource representation consists of (data, metadata, and links to the next desired state)
    - resource model: a set of inter-linked resources
- `Resource Identifiers : `
    - `media-type : ` tells us how the resource in the response must be handled (`media-type:text/html` will notify the client-app to render the HTML)
    - `self-descriptive : ` the resource format and media-type tells the client how to handle the particular resource 
- `Resource Methods : ` operations that can be performed on the resources

### Layered architecture
- A given service must only care about interacting with the interface (must not care about the low-level details of the service it is interacting with, or else it will get coupled with that service) using this interface it can communicate with any service.
- we can swap out the services on the other end of the interface and that should cause no issues


### Key takeaways
- Resource : object, document, or anything that you want to persist and send to the client service.
- **Statelessness constraint :**  The server needs to be able to understand  the current request without remembering the context of the previous request, each request should be made such that it can be processed independently. (State of the client is persisted at the browser and not server)
- The services do not rely on how the interfaces ( End Points ) are implemented, they rely on a few standard operations/methods (like CRUD) on the resources
- This makes the system Reliable and performant, and the system can be managed, updated and scaled easily (due to the decoupled services)
- HTTP != REST

---
# HTTP based REST service
- the uniform interface in this case is a combination of `URI + HTTP Methods`
- Resources can be any of the following (service/document/collection/store), they can be singleton or a collection
    - `service` : the `controller` that is going to handle the given request
    - `document` : `single` object/file/database record
    - `collection` : 
- when using a resource name comprising of multiple words use hyphens (`-`) to separate these words to maintain readability of the URIs
- do not use file extensions, use the `content-type` tag provided by HTTP to render the content at the client
- use query params to provide data for filtering at the backend
    - filteringQueries = `https://domainName/service-name/collection-name?param1=value1&param2=value2`
- do not use verbs in the URIs to execute `extra operations` (operations not present in the Uniform interface)
    - if we want to execute some operation in isolation which is not defined in the Uniform Interface (`URI + HTTP methods`), then RPC will be a more suited architectural style
    - To execute methods and still stick to REST Architectural style then we can use the colon (`:`) syntax defined here [Google: Custom Methods with REST](https://cloud.google.com/apis/design/custom_methods)

### Resource Identifiers 
- each resource has an unique identifier (URI), the URI starts with the domain name followed by a path to the resource (`https://domainName/path/to/the/resource`) 
    - document = `https://domainName/service-name/collection-name/{resource-id}`
    - collection = `https://domainName/service-name/collection-name/{resource-id}/collection-name`
    - 

### Building a rest backend
- Create a HTTP server using language of choice
- create HTTP endpoints, create services (classes/structs) and handlers that handle these endpoints
- choose a DB to manage data, choose a suitable ORM for safety
- think of caching strategies, based on the frequency of data
    - Caching at server, caching at proxies,http caching and redis cache
    - `end-point + query params` is used a keys for caching
- use docker to configure spin up containers for the app servers
- set up a load-balancer/reverse-proxy decide on load balancing strategies


## Useful Links
- HTTP
- Load balancing
- Stateful vs Stateless services

https://www.ics.uci.edu/~fielding/pubs/dissertation/rest_arch_style.htm