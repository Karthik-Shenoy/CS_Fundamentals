# High Throughput applications
- blocking calls when performing high throughput and high priority work will increase latency and regress performance
    - Acquiring Lock, Allocating memory on the heap, and other blocking system calls will block the thread
    - avoid costly arithmetic ops like division and modulo, use bitwise ops


## priority thread callbacks

## Lock free data-structures data-structures
- Atomic types