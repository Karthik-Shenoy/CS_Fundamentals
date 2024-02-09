# Caching strategies

## 1. Cache Aside
- when the client request arrives, check if the requested data is in cache, if the requested data is present in cache, then return the response from the cache
- if the requested data is not in cache request the data source for the same, cache the response and forward it to the client
- For each request if the data is present in cache that situation is called a `Cache hit`, if the data is not present in cache then the situation is called `Cache miss`
- The Cache server's responsibility is to store and manage the cached data
- The Application Server is responsible for `data retrieval` from the source, thus app server keeps updating the cache on cache miss
- Server is the single source of truth
- as the name suggests most of the logic is present at the app server and we `cache aside` data that is requested frequently/recently.

### Pros
- Good approach for heavy read application (writes can lead to inconsistency if cache updation is not handled properly)
- Availability is maintained even if the cache servers are down, as `Servers are single source of truth`
- The data structure at cache and the data source can be different (cache data structure is independent from the data source) `Example : Redis Key-value cache and Relational Data source`

### Cons
- for every new request, there will always be a cache miss first (we can resolve this by pre heating the cache, `Preheating cache also has different strategies based on the application`)
- If appropriate strategy is not used for updating cache on writes then there can be inconsistencies as we will be reading stale data 

---

## 2. Read Through cache
- All the other characteristics are similar to cache aside, except for data retrieval from the data source (as the name suggests we `read through the cache`)
- Caching service (caching library) is responsible for retrieval of the data from the data store, instead of the application service
- On cache miss, the caching service retrieves the data, stores it in the cache and forwards the response to the application server

### Pros
- Separation of concern, the responsibility of fetching data and updating the cache now lies with the cache service, thus the complexity of the application server code is reduced
-  Similar Pros as `Cache aside`

### Cons
- No control over the updation of the cache, and the structure of the document being cached, everything is handled by the caching service/library
- Similar cons as `Cache aside`

---

# Handling Writes at distributed caches
- the write strategies are used along with read strategies (the write strategies are of no use if used in isolation)

## 1. Write Around Cache
- All the write operations are made at the `data source (DB)`, caches are not updated after the write is complete
- instead the cache is invalidated (the document on which the right was performed is evicted from the cache), or cache is marked dirty (`isDirty` flag is set to true)
    - On the subsequent read on that document, there's a cache miss and updated data is fetched from the source (DB)
    - Or we check the `isDirty` flag which will be set to `true`, the dirtied cache items are re-fetched from the source (DB)

### Pros
- generally used for `improved consistency`, in the case of heavy read applications (used along with read-through-cache/cache-aside strategies)

### Cons
- First time reads will always cause cache-miss (pre-heat the cache to solve this issue)
- First time reads after updates will also cause a cache miss
- the writes start to fail if the DB is down (thus we sub-par availability)
    - if we queue the operations using a `message queue` (to avoid data-loss during DB fail), (the updates wont get reflected unless the DB is backup and the queued operations get executed) thus there will only be weak/eventual consistency

## 2. Write through cache
- Writes are made to the cache first, followed by Synchronous writes to the DB
- whenever we write data we use the [`2-phase-commit`](../../../Databases/RelationalDatabases/) algorithm (to ensure consistency), in 2 phase commit we acquire locks on both cache and the data source (DB)
- The `(DB_WRITE + CACHE_WRITE)` operation will always be an atomic operation in this case, this operation should either be fully completed or not completed at all, `partial completion is not allowed`
- as the name suggests we write through the cache, but in this case the server handles the DB_WRITE, CACHE_WRITE, synchronization on managing of 2-phase-commit

### Pros
- cache and DB are always consistent, large cache hits
- Used when there are Both larger number of reads and writes (We can stick to write around cache along with message queue if we have large reads and minimal writes)

## Cons
- if there is no need of strong consistency then we will be making a lot of unnecessary network calls to maintain consistency
- 2 Phase commit must be supported by both cache and DB to maintain transactional property
- complex synchronization code
- if DB is down the writes will fail (but we can avoid this by maintaining a Task/Message Queue but we will loose out on the Transactional/Atomic nature guaranteed by 2 phase commit)

## 3. Write Back Cache
- Writes are made to the cache first, followed by Asynchronous writes (writes on to Task/Message Queue) to the DB

### Pros
- improved latency (due to async operation)
- 

