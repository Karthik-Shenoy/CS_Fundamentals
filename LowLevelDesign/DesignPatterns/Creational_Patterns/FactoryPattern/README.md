# The Factory Pattern
## things to look for
- multiple classes that get instantiated based on conditions (instantiated inside conditonal blocks)
- coupled system, for every new type of class you need to make changes at multiple places
- Single Responsibility Principle: You can move the product creation code into one place in the program, making the code easier to support.
- Open/Closed Principle: You can introduce new types of products into the program without breaking existing client code.