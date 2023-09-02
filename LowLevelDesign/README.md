# Low Level Design

## Classes
classes consists of **fields/artributes/data0-members** and **Operations/methods/member-functions** which can be performet on those data members.
- `Package/Namespace` decides where the class will be declared and defined
- `Static` members can be called directly without creating an **instance/object** of the class
- `Constructor` gets called automatically when a new instance of a class is created, **Usually used to initialize the object of the class**
- Constructoes can be overloaded, constructor with no arguments is called **default constructor**

## Coupling
Tells us how much a given class is coupled or dependent on another class
- all the dependent class on a given class must be recompiled if the given class is modified
- Coupling adds overhead, we must design application such that it allows us to make changes to the components independetly of other components
- We can use interfaces to reduce coupling by ( Dependency inversion )


## OOP principles


We must mainly focus on how `abstraction` and `interfaces` works, once our core SOLID principles are strong we can apply these principles when writing code and try to match it one of the design patterns. 

## SOLID Princicples

### Single responsibility principle
before applying the single responsibilty principle we must know what `responsibilities` are and its types.

<object data="/NotesDesignpattern.pdf" type="application/pdf" width="100%"></object>

