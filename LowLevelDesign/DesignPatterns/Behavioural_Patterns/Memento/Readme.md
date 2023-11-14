# Memento
- save and restore previous state of the object, without exposing the implementation details of the object
- To save the state of an object we first need to go through all the `fields` in the object then `copy and store` them
- `issue-1 : `most of the significant fields of the objects will usually be `private`, to `prevent external people from fiddling` with these important fields
- `issue-2 : `even if we assume all the fields are `public` (bad design, as it is unsafe), even then when the user needs change and you add a field to the object, then we will also need to `update the code` which goes through the fields, and `stores their copy`
- if we use some kind of container to persist the fields of an object (`Originator`), then it introduces 2 problems
    - exposes all the private fields of the `Originator (object to be persisted)` to all the classes that use this container
    - `makes code fragile`, as all the classes are dependent on the container class which itself is depenednent on the `Originator`, changes (not all changes) made to the `Originator` will `ripple out` to the dependent classes (direct dependency, instead of dependency on an interface)

## Solution to the issues discussed above
- The responsibility to generate the state snapshot lies with the `originator object`, as it has full access to its own state
- The patterns suggests, storing the object state in a special object called Memento, (contents of the memento is only completely accessible by the originator object)
- other objects communicate with the memento using a `limited interface`  (which exposes only few methods like getMetadate -> creationTime, operationPerformed etc)
- the object which store mementos, will have a limited interface to the mementos state (can not access private fields), thus it can not tamper with it

## Responsibilities
- `Memento` : stores a reference to the originator and restores the state (based on memento/snapshot content)
- `Originator` : creates the memento (passes `self` as reference)