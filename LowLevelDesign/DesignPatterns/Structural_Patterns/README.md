# Structural Desin Patterns
- Assemble classes and objects into `larger structures`
- most of the structural patterns, follow the idea of wrapping the object with another object to add `additional behavior`
    - Facade/Decorator Wrap the object and add `additional behavior`, but the intent of wrapping and adding additional behavior is different

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
- Allows objects with incompatible interfaces to collaborate
- implement a concrete class which implements the interface to be adapted, the concrete class  is composed of the `incompatible/adaptee class object` which implements `different interface`
- the adapter class wraps the service/class which needs to be used(adaptee)
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