## Necessary properties of a synchronization mechanism
the first 2 rules are mandatory, the other two rules are optional
- **`Mutual exclusion (Mutex)`**
- **`progress`**
- Measurable wait time :  there could be a situation, where on of the threads enter the critical section (lock mutex) and throw an exception and crash without unlocking the mutex, this leads to the critical section to be locked forever. and the wait time is infinite.
- Hardware independent : a few of the operation might be atomic (no need of synchronization) in some CPU architectures, such assumptions must not be made and all the architectures must be considered

### Problems with mutex lock
- Overhead:
- Deadlock:
- Starvation: high priority threads starve for CPU resource, because of low priority thread locking the CPU resource.
- Debugging