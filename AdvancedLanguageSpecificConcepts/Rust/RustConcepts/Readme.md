# Rust Concepts

## Strings in rust vs Other languages
- read the following for better context (`String Case Study`)
- string can change during run time (if its too large then it can occupy all the space in the stack and cause overflow)
- to resolve the string is initialized on the heap with the pointer to the string stored on the stack, rust releases the heap memory automatically as this reference goes out of scope
    - usually when you create an object using `new` in most of the languages the same thing happens, the object is created on the heap and a pointer to the object is stored on stack
    - in languages which do not use `RAII- principles` as soon as the reference goes out of scope the ref is deleted causing a `memory leak` (since the object stays in the heap for the entirety of the apps life time)
- in rust when we create a `string` we create an `object` which holds a reference to the string on the heap, this object also has the following content (capacity and the length of the string). the size of the string-ref-object will be 24 bytes (3 * `8-bytes`)
    - capacity in this case tells us about the total amount of memory received from the `allocator`.
    - in case of C the string length is never stored, we get to know that we have reached the end of the string using the `null-character (\0)` if the dev forgets to add this null char then we can iterate to any part in the memory causing undefined behavior.
- `string literals : ` are hardcoded on to the compiled binary file, and as its length is fixed, they are stored as `slices ---> &str`, the size of the slices are known at compile time hence they will be allocated on to the stack
    - think of slices as a fixed size slice of a string (whose size is known at compile time) and is allocated on the stack

### String vs str
-  `String : ` is stored vector of bytes (Vec), but `guaranteed` to always be a valid UTF-8 sequence. String is heap allocated, growable and `not null` terminated.
- we can only concatenate a `&str`

### how chars are stored

## Copy vs Move
- fixed size data allocated on stack is always copied
- dynamically sized data allocated on the heap (can grow huge) and copying this is expensive, thus we can only move dynamically sized data (take ownership)
- we can explicitly copy a heap allocated string using `stringPtr.clone()`
