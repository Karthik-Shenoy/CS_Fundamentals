# OOP basics
- We must mainly focus on how `Abstraction` and `Polymorphism` work, once our core SOLID principles are strong we can apply these principles when writing code and try to match it one of the design patterns. 
- we combine/group related functions and the data/variables that is/are operated upon by those functions into a single unit called as `object`. The object must abide by all the OOP principles.
    - The variables stored in the object are called as `properties`, and the functions are called as `methods`



### Abstraction
- Hide the implementation complexities from the higher level modules that use a given modules
- We use an interface + private methods, to hide unnecessary methods and properties, and expose only the function signatures present in the interface.
- Provides a simple interface and makes the code easy to read, reduces the rigidity of the code, the changes made to the private methods don't ripple out (as the private members are never used by the outside world)

### Polymorphism
- 

--- 
### How Polymorphism and Abstraction go hand in hand
- Abstraction allows the higher level modules to `use/interact` with the lower level modules which handle all the low level complexities.
- When using these low-level modules the Higher Level modules only knows about the `function signatures exposed by the contract/interface` and do not care who is implementing these methods or how these methods have been implemented
- example: `stdio`

--- 

### Encapsulation
- couples related variables and functions into a single unit, encapsulation reduces the amount of parameters to be passed to functions. the variables are directly accessed by the functions through the objects they belong to (using `this` keyword)
    - The best functions are the one with no parameters
    - the fewer the parameters the easier it gets for the client to use our class (without needing to know about the implementation details of our class)
- `encapsulation enables a bit of abstraction`, the methods can be used without knowing about the low level implementation details.
- 

### Inheritance
- allows us to reduce redundant/duplicate code