# Rust Borrow Checker

## Rust Ownership

- We can have one mutable reference and any number of immutable references
- We can only have one owner of a heap allocated object at a time, when we re-assign an object the object is moved from one pointer to other, the previous pointer gets deleted and the new pointer takes ownership
  - this prevents the case where one of the pointers might delete the object causing the other pointer refer to a null memory space (dangling pointer)
  - also prevents double-free of the allocated data (double free is undefined behavior)
- we can explicitly copy a heap allocated object using `object.clone()`
- the above mentioned rule holds when we pass/return the `heap allocated object pointers` to/from functions,
- mutability can be changed when transferring ownership;

### Partial Move

- when destructuring single variable, parts of the variable might get moved and others might get copied or `referenced`, in such case we can not use the entire variable, but the members of the variable can be used individually
  - `referencing heap allocated object : ` we can use the `&ptr` or `ref` key word to borrow reference to the object

### Borrowing
- gives `temporary access` to the heap allocated object `without taking the ownership` of it
- we don't move and delete the previous pointer to the object, instead we create a new `temporary` reference to the object
- ownership can be borrowed immutably or mutably
  - at a given time we can have only one `mutable reference`, or we can have any number of immutable references but we cant have both at the same time(write acquires a lock, reads prevents writes but we can have any number of reads happening in parallel) `&ptr: immutable reference , &mut mutable reference`
  - we can have multiple mutable and immutable references given that `only the most recent` out of all the references is being used after the acquisition of these mutable references
- references must be valid and not dangling

## Allocating data on the heap

- `Box::new()` allows us to allocate objects on to the heap, Box returns a pointer to the heap allocated object, we use the dereferencing operator to get the pointer referenced object `*ptr`
-
