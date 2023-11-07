# Transmission Control Protocol
- TCP is a stateful Protocol, it maintains the state for data transmission between endpoints.
- Connection oriented protocol
- TCP breaks down the message into smaller packets (called `segment`) and sends it to the IP layer, and the packets are routed to the destination through different routes (based on connection health, congestion)
- The TCP layer waits until it gets acknowledgment for all the transmitted packets, and once all the packets that were transmitted get acknowledged it sends an acknowledgment to the higher layers.

## Segmenting The message
- The message is broken down into smaller packets (called `segment`) 
- Each Segment is assigned `sequence number` before being transmitted (both at client and server)
- `acknowledgement numbers` are assigned to received segments

