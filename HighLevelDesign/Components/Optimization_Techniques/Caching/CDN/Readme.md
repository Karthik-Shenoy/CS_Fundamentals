# Content Delivery Networks
- Used to speed up the delivery of static content (the static here does not imply `strictly static`, the `loosely static` content at the CDN changes Rarely)
- A Content Delivery Network (CDN) is a geographically distributed group of servers that caches content close to end users
- `Static Content : ` Javascript, Images, HTML, CSS, Videos, Strings (Translatable)
- CDN caches the content and brings the content (`geo-spatially`) closer  to the User, there by decreasing the perceived load time at the client side
- CDN servers are deployed at multiple locations around the world, they are called as `POP (point of presence) or edge` servers, as CDNs are deployed across the world, Clients can quickly fetch cached data from the nearest CDN

## Routing requests for static content to the nearest CDN
- we can either use DNS or AnyCast to route the clients to their nearest `CDN-POP`
- `DNS based routing : ` when using DNS to route clients to the nearest POP, `each CDN-POP will have its own IP` and when user requests for the IP of the POP which serves static content  the `DNS sever` responds with the IP of the closest POP
- `Anycast based routing : ` all the POPs across the world have the same IP
- CDN improves response Speed, and reduces the load on the origin server, improves security and UP time as the CDN POPs are distributed
- CDN POPs subscribe to the static content at the origin server and when the subscribed content changes the POPs are notified accordingly

## How does an Edge/POP server works in a CDN
- Each POP/Edge works like a reverse proxy, with multiple content cache nodes (servers)
- when a client makes any request, the request comes to the nearest CDN, if the CDN does not have the requested content it requests the Origin server for the static content, caches it and forwards this to the client, all the subsequent requests are served from the POPs cache instead of sending the request again to the origin server
- The content is cached on the CDN servers only when a user requests it for the first time
- CDNs can also optimize the static content's format, or customize data according to the client (locale/endpoint)
    - convert `.js` and `.css` files into `minified` files
    - convert images into `WEBp/AVIF` (modern image format)
    - convert videos into multiple formats (720, 1080, 2k 4k) and server based on client bandwidth
    - show compliant web page content according to the users locale
- All the TLS connections terminate at the Edge/POP servers
    - TLS connections are expensive, as they need 3 way handshake, upon the usual TCP handshake
    - thus users can avoid multiple Round Trips to the origin servers and fetch contents directly without expensive TLS encrypted TCP connection
- some services which don't care about `high consistency` also cache the dynamic content at the CDN.
- CDNs have a huge network capacity at the edge, and can protect the origin from a DDOS attack (as the network will have a larger capacity than that of the attackers)
    - DDOS attack prevention is much prevalent, if the CDNs use anycast routing, as anycast diffuses the DDOS traffic across multiple POP servers
- `Improves Availability :` As CDNs are distributed and have copy of the content, they can handle more hardware failures than just the origin server

## CDN service providers
- Azure
- Amazon
- Akamai
- Cloudfront





### Useful links
- [Reverse Proxy]()
- [Anycast]()
- [DNS]()
- [CDN video](https://www.youtube.com/watch?v=RI9np1LWzqw)