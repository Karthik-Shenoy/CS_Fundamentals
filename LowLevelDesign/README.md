# Low Level Design

## Classes
classes consists of **fields/artributes/data-members** and **Operations/methods/member-functions** which can be performed on those data members.
- `Package/Namespace` decides where the class will be declared and defined
- `Static` members can be called directly without creating an **instance/object** of the class
- `Constructor` gets called automatically when a new instance of a class is created, **Usually used to initialize the members/objects of the class**
- Constructoes can be overloaded, constructor with no arguments is called **default constructor**

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
## OOP principles
We must mainly focus on how `Abstraction` and `Polymorphism` work, once our core SOLID principles are strong we can apply these principles when writing code and try to match it one of the design patterns. 