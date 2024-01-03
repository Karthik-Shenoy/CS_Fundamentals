# Low Level Design
- things to look for when doing low level design
    - make extensible only if required (do not over engineer)
    - where to cache data (do not go on creating instances of large objects, reuse wherever possible)
    - code reuse 
    - avoid recomputation
    - separation of non-relative concerns (don't be to specific about the concerns) prevents code rigidity (example keep data-base code and analytics code separated, so that in future when migrating DBs, changes to DB code should not ripple out to analytics and cause issues in PROD)
- Use  a lot of tests
    - unit tests
    - integration tests



## Classes
classes consists of **fields/artributes/data-members** and **Operations/methods/member-functions** which can be performed on those data members.
- `Package/Namespace` decides where the class will be declared and defined
- `Static` members can be called directly without creating an **instance/object** of the class
- `Constructor` gets called automatically when a new instance of a class is created, **Usually used to initialize the members/objects of the class**
- Constructors can be overloaded, constructor with no arguments is called **default constructor**

## Relation between classes

## Coupling
Tells us how much a given class is coupled or dependent on another class
- all the dependent class on a given class must be recompiled if the given class is modified
- Coupling adds overhead, we must design application such that it allows us to make changes to the components independetly of other components
- We can use interfaces to reduce coupling by ( Dependency inversion )

> Tight coupling makes the code fragile and Rigid

## Rigidity
- If there is a lot of interdependencies between the classes (related/unrelated), we can conclude that the code is tightly Coupled 
- This makes it hard to make isolated changes in the modules as the changes have a **ripple effect** throughout the code base

## Fragile code
- Breaks in strange un-predictible ways, because of tight coupling (dependency) between unrelated classes
- completely arbitrary changes may cause some unrelated code to break in the code base

> The above mentioned problems (Rigifity, Fragility and Coupling) can be solved by using `interfaces` (**Abstraction, Polymorphism and Dependency Inversion**)
