# Basic Concepts


### Basic over view of a distributed system
- optimize process and increase the throughput using the same resources (Vertical scaling/ optimizing datastructures)
- get more machines to get more processing power
- Preprocessing and cron jobs ( handle all the non )
- Utilize Failovers and have backups to make the system resilient and fault tolerent
- `Microservice Architecture : ` Decouple systems and Seperate the concerns and scale these Decoupled Systems at different rate independently
- Distribute the system geographically, to reduce complete faliure incase of bad external events (such as power outages, Natural calamities)
    - this step adds a lot of complexity as there could be need for cross data center communication (to maintain consistency)
    - also the requests must be routed logically based on the factors such as geo-location, Datacenter Load/health thus we need `Load Balancer` for smart routing
    - we need intra and inter DC Loadbalancers to distribute load (requests) based on few constraints and rules (stateless/statefull[`machine affinity`])
- `Flexible to change`: Abstarction of using the interface, teh systems must use the interface without getting coupled with the interface provider
- Logging, Telemetry and Data driven decesion (monitoring, auditing and reporting)

## Scaling (Vertical vs Horizontal Scaling)

### Horizontal Scaling
- Load Balancing is required, or else there is starvation and underutilization of resources
- Resilient (as we have multiple failover machines)
- Data Inconsistency/ Eventual Consistency
- Expensive Network calls required if processes need to communicate with each other
- scales up easily (no limit on number of machines)

### Vertical Scaling
- No need to update load balancing rule, as only the machine's hardware is improved
- Single Point of failure (no failover machine)
- cheap Inter Process communication for collaboration and communication between processes
- Data Consistency can be easily achieved
- has a hardware limit on scaling out

## 




