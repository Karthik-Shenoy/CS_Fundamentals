# Structural Desin Patterns
- Assemble classes and objects into `larger structures`
- most of the structural patterns, follow the idea of wrapping the object with another object to add `additional behavior` (Wrapping here implies composition)
    - Wrap the object and add `additional behavior`, but the intent of wrapping and adding additional behavior is different
    - `Adapter: ` Wrap the class with incompatible interface, with a `concrete class` having compatible interface, the wrapper/concrete-class is responsible for data transformation from format supported by the compatible interface to the format supported by the incompatible interface (In `Adapter pattern` the Wrapper and the object getting wrapped implement different interfaces)
    - `Decorator: ` Wrap a class to extend its functionality, each wrapper adds a new functionality, but the method signatures remain the same (In `Decorator pattern` the Wrapper and the object getting wrapped implement same interfaces, to ensure the method signatures remain same)
    - `Bridge : ` Wrap one interface inside other, as each object that implements the first interface will be composed of a member implementing the second interface, this member can change dynamically (basically it can change into any object that implements the second interface) thus any object implementing the first interface can utilize any object implementing the second interface. < Image >
    - `Flyweight:` objects may be composed of immutable states (that gets `repeated` across objects) and mutable states (that are unique to the object), `we move the instantiation and caching of such repeated states to a separate class` (there by reusing already created object, reducing redundant objects in ram thereby preventing over utilization), `reuse states instead of repetition`
        - Basically the repeated state will be moved to a separate object, and the unique state will be kept in another object, the unique-state-object will have a reference to the repeated-state-object (composition/wrapping)
    - `Facade : `
    - `Proxy : `


- while keeping the structures flexible and efficient
- how are objects related to each other, Relationships between objects (Wrapper/Wrapee, Composition etc)

## Decorator
- Use Composition instead of sub-classing to extend the functionality (in case we want combination of functionalities from multiple classes)
- Recursive Wrapping, we assemble the objects to wrap around the wrappee and add extra functionalities
- Used when the object requires new functionality dynamically during runtime 
- Decorator is a wrapper object, which wraps a given object and adds extra functionality to the object, we can have multiple layer of decorators which adds functionality over the wrapped object
- Both decorators(wrappers) and the object they wrap implement the same abstract-class/interface, this allows us to wrap decorators inside decorators (recursive wrapping)

--- 

## Facade
- Create Abstraction (Simple interface) of a complex structure of objects
- Use Facade when we nee simple interface to a complex subsystem (like some library/framework)
- reduces the repetitive configuration boiler plate needed to use some library
- look at the RTC chat application here (look at the rtcHelper class)

### Pros
- isolate code from boilerplate/complexity of the subsystem
- simple invocation of facade method (faced handles all the complex ops)
### cons 
- a lot of coupling with the subsytem classes (becuase only single class is coupled to all the underlying complex classes)
- no polymorphism, interfaces or abstraction (direct coupling)

---

## Adapter
- Allows objects with incompatible interfaces to collaborate (in most cases the classes are coupled to an interface, and can not use code from other classes that don't implement that interface)
- implement a concrete class which implements the compatible-interface, the concrete class is composed of the `incompatible/adaptee class object` which implements `different interface`
- the adapter class wraps the service/class which needs to be used (adaptee), and also performs data transformation on the incoming data 
    - the incoming data will be in a format which is defined by the compatible-interface
    - the adapter class converts the incoming data format to the format defined by the incompatible interface
- the adapter class belongs to the interface to be adapted

--- 
## Proxy
- main intent is to control access to some object, 3 different types
    - Remote Proxy
    - Virtual Proxy (Caching/Lazy Evaluation/Deferred Loading): controls access to a `resource`, that is expensive to create
    - Protection Proxy: Access Management, controls access to a resource based on access rights (based on the current state of the app, is the client allowed to make the call)
- Placeholder/surrogate object that `controls access` to another object, thus instead of directly interacting with an object, the client interacts with the `Placeholder Object` which interacts with the underlying object on the behalf of the client

### Virtual Proxy
- usually used to refactor, library classes which `load stuff eagerly`, when you want to defer them and load them on demand and `cache the reusable results` (when there is a need)
- if it's not a library class and a lot of code is not dependent on that class, you can directly alter the class to `lazily Evaluate` complex stuff on demand and add `caching logic`, instead of using Proxy


### Diff between Adapter, Decorator, Facade and Proxy
- 