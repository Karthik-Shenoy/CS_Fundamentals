# SQL vs NO-SQL

| SQL | NO-SQL |
|---|---|
| Slower Ops (Insertion/retrieval/deletion/updates) | Faster Operations |
| Non-Flexible Schema | Flexible Schema |
| Very Complicated to scale (needs a lot of logic) | Built For Scale |
| Suited For Complex Queries | Built for metrics/analytics/aggregation.<br>But not suited for complex queries |
| Optimized for large number of writes/updates. | Not built for large number of updates/writes. |
| Read times are comparatively faster, when a subset<br>of table is read | Read times are comparatively slower,<br>when a subset of the documents is read. |
| Built for optimized join operations on tables. | need for Implementation of complex explicit. <br>join logic, to join collections. (Makes Code<br>more error prone) |
| Implicit enforcement of <br>constraints (like foreign key)/relations | Explicit complex logic for enforcing foreign <br>key constraints are needed. (Makes code more<br>error prone) |

## PROS of NO-SQL Database
- usually DB operations like insertions/retrieval/deletion operate on the entirety of data concerned with the entity 
    - example : query concerned with user data => get user details for userId=23 (Name, address, role, books)
    - In case of SQL the data for address and books could be stored across tables (due to normalization), thus requiring more number of operations (queries and joins), these tables could be across different blocks/pages on the disk further slowing down the operations.
    - In case of NO-SQL the data concerned with an entity is stored at a single place (only one operation to get the data) thus enabling more efficient retrieval (the data concerned with an entity is usually stored in the same/adjacent blocks on the disk)
- NO-SQL has flexible schema, in case of missing values we can drop the field from the object, but in case of SQL we need to store empty/null values in case of missing data
    - New Attribute addition in SQL Table, is an expensive operation, we will need a large number of locks to maintain consistency, and might end up with a lot of missing values
    - but we can add a new attribute to a single object in NO-SQL collection, without other objects/documents needing to have the same attribute
- Usually NO-SQL Databases have built-in horizontal scaling (Availability over Consistency), when having multiple replicas and partitions of the DB we can not guarantee strong-consistency, thus when scaling databases we can only promise on eventual consistency
- Built for metrics/analytics/ and aggregations (thus usually best choice in case for monitoring the health of the various components present in the app architecture, and in case of running machine learning/ statistical analysis on the big data)

## CONS of NO-SQL Database
- Not built for large number of writes/updates (updates are not inherently supported)
- Eventual Consistency (ACID Transactional Properties are not guaranteed) thus systems with the need of high consistency (Finance, Ticket booking) do not usually use NO-SQL
- Not Read optimized, in NO-SQL when we need to perform an operation with respect to a specific set of columns, we get all the objects onto the memory, iterate over each of the objects and retrieve the necessary data and perform the operation, which is not optimal
    - in SQL when we need to perform an operation with respect to a specific set of columns, the reader gets only the data concerned with those columns from the table, instead of the whole table
- Relations are non implicit, in case of NO-SQL the Foreign Key constraints which allow us to form relationships across tables can not be enforced implicitly , we need to enforce them through code, which might lead to more error prone system