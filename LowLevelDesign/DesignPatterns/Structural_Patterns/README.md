# Structural Desin Patterns
- Assemble classes and objects into `larger structures`
- while keeping the structures flexible and effecient
- how are objects related to eachother, Relationships between objects (Wrapper/Wrapee, Composition etc)

## Decorator
- Use Composition instead of subclassing to extend the functionality (in case we want combination of functionalities from multiple classes)
- Recursive Wrapping, we assemble the objects to wrap around the wrappee and add extra functionalities
- Used when the object requires new functionality dynamically during runtime 
- Decorator is a wrapper object, which wraps a given object and adds extra functionality to the object, we can have multiple layer of decoratros which adds functionality over the wrapped object
- Both decorators(wrappers) and the object they wrap implement the same abstract-class/interface, this allows us to wrap decorators inside decorators (recursive wrapping)

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

## Adapter
- Allows objects with incompatible interfaces to collaborate
- implement a concrete class which is composed of the `incompatible class object` from the `interface` to be adapted
- wraps the service/class which needs to be used(adaptee)
