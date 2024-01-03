# Visitor pattern
- You can use `Visitor` along with `Iterator` to traverse a complex data structure and execute some operation `over its elements`, even if they all have `different classes`.
- Lets you separate the algorithms from the objects (usually large complex objects) on which they operate
- Example : separate the algorithms (Query Matching/conversion/storage) from large `graph/tree node object` (Large Geographic Information Graph where each node stores large amount of info about interconnected cities)
    - suppose we already have an iterator that moves through such graph, but we want to print the count of all the shops in a given list of cities that has a certain pattern given by the user.
    - in such case we need to traverse through all the cities present in that complex node object and do a pattern matching.
    - to separate the algorithm from the node object we can create a `ListCitiesWithPatternvVisitor` visitor object
- The Object on which the algorithms operate might be fragile/critical (strongly coupled to the app), separating the concerns would allow us to work on the algorithms separately without having concerns about breaking critical components.
    - in cases where you need to add new behavior to existing fragile/critical classes which are already in `PRODUCTION environment`, we can use the visitor pattern to add these behaviors to the existing classes `without altering their code`
- We will use, `composition` instead of `inheritance/modification`, pass the object to the `visitors member functions` which implement the algorithms on the passed object.
- if we want to invoke the same algorithm for different objects of a data structure (example: graph might have multiple nodes -> city node, industry node, tourist sight node, etc.), the visitor will have all the methods implemented for each of the different classes.

``` typescript
class ExportVisitor implements Visitor {
    public doForCity(City c) { 
        // perform algorithm for the City object 
    }

    public doForIndustry(Industry f) { 
        // perform algorithm for the Industry object 
    }

    public doForSightSeeing(SightSeeing ss) { 
        // perform algorithm for the SightSeeing object 
    }
}
```
- We can either use a conditional (switch/if) to determine which visitor method to call based on the objects class, or we can use a technique called `double dispatch`
- `Double Dispatch : ` the object on which we need to perform the algorithm will have a member function which accepts the visitor and calls the respective method, as the `object will know which class it belongs to`, but in double dispatch we will end up changing the complex object's code, but the change is trivial
- if we have a language which allows method overloading (C++, Java, C#) we can use method overloading instead of the double dispatch technique to achieve complete decoupling
- We will have different visitors for each type of algorithm/extra-functionality that we want to add to the diverse classes, the visitor must implement methods for relevant classes, that adds a given algorithm/functionality to that particular class  

``` typescript
class City{
    public accept(Visitor v){
        v.doForCity(this)
    }
}

class Industry {
    method accept(Visitor v) {
        v.doForIndustry(this)
    }
}

```

## Reference
- https://refactoring.guru/design-patterns/visitor
