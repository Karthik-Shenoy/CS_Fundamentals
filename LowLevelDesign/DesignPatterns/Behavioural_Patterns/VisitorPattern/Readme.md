# Visitor pattern
- You can use `Visitor` along with `Iterator` to traverse a complex data structure and execute some operation `over its elements`, even if they all have `different classes`.
- Lets you separate the algorithms from the objects (usually large complex objects) on which they operate ()
- Example : separate the graph algorithms (Traversal/Shortest-Path/Minimum Spanning Tree) from large graph/tree object, (Large Geographic Information Graph which stores large amount of info about interconnected cities)
- The Object on which the algorithms operate might be fragile/critical (strongly coupled to the app), separating the concerns would allow us to work on the algorithms separately without having concerns about breaking critical components.
- in cases where you need to add new behaviour to existing fragile/critical classes which are already in `PRODUCTION environment`, we can use the visitor pattern to add these behaviours to the existing classes `without altering their code`
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
