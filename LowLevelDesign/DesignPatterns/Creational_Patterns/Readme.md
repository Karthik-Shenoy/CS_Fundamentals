# Creational Design Patterns

## The Factory Pattern
- Move the Object creation logic into a separate Factory class, thus the object creation is separated from the class which uses the object (if the class which uses the object is fragile, adding more complicated logic of object creation might cause a rippling effect and cause more bugs)
    - more over if the fragile class critical (tightly coupled with other classes) is already in Prod, then adding more complex code will only increase the possibility of bugs
- `Single Responsibility Principle:` You can move the object creation code into one place in the program, making the code easier to support.
    - The lifecycle management could also be done using the factory pattern, the factory class is the place where we keep freeing the memory


### things to look for
- multiple classes that get instantiated based on conditions (instantiated inside conditional blocks), a lot of complex tasks to perform to create an object
- coupled system, for every new type of class you need to make changes at multiple places

---

## Builder Pattern
- Helps building an object step by step, (add certain functionality and don't add others based on provided constraints)
- `Problem` consider we want to create a complex object, with `multiple properties and nested objects`, and we need to discard a few of the properties, based on the constraints passed
    - thus we need a different set of fields for the object based on different constraints (Protected Mode), such creation will need a `thick constructor`, and the constructor will have complex logic of what to include and what not to include
- To overcome the constructor pollution with complex code, we can break the object creation into a set of steps (steps are basically methods which compute a set of fields of the object) and move it into a `builder class`
- The builder is responsible for creation of the object (creates the object steps/methods which compute the object fields/properties based on the input/constraints)
- The object on the other hand is responsible only for the operations that can be performed on it.

### Components of the builder pattern
- `Builder : ` has methods to build the objects step by step based on constraints, basically we will have a lot of setter methods, the Builder is responsible for providing details about how the object is built (all the API calls are made to the services from builder)
- `Director : ` builds the actual object using the builder, the director has a builder (can take any type of builder and build objects) the director should not be coupled with the builder
    - director method invokes all the steps exposed by the builder, it does not know the implementation details (as director needs to be able to build different things)