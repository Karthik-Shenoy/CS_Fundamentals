# Multi threading

- Pre-emption is probabilistic, if 2 operations are run in parellely, less number of times, it is less likely for the thread to get pre-empted in the critical section and cause issues.
- As the threads go into the critical section more frequently, then there is a high probability that race condition might happen and thread loss might occur