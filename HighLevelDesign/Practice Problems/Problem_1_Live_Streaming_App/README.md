# Live Streaming App
Consider a company which broadcasts video to a large number of users, come up with a system that can handle this larger user base.

## Step1: Defining Product Requirements
- Live streaming (Real Time)
- Likes, Comments
- Processing Video
- Broadcasting
- Failproof
- Ads
- Automatic video quality degradation based on bandwidth
- Multi device support

## Step2: Creating Abstract Features
- Live Streaming: capture video from source, store it somewhere, query it later ( in real-time / later )

## APIs required
### Version 0.1
- `GET VideoFrame(videoId, deviceType, offset)`, get a video frame which starts from a given offset
- `POST comment(id, data, userId, videoId)`

## Defining Schemas
### Version 0.1
- from the APIs defination we can create a basic schema as a starting point for the design process
<div style="text-align:center">
  <img src="./DatabaseDesignBasic.png" alt="Example image" style="width:450px;height:225px;">
  <p style="font-style:italic;font-size:14px;">Basic Schema Design</p>
</div>

## Implementation Details
From the user specification understand the behaviours of the defined objects 
### `Version 0.1`
Here objects are (video, user and comment)
- **Comments :** the notifications about comments, reply to comments can be given out periodically thus, there's **no realtime behaviour**, thus we can use HTTP (***REST***) model to get the comments.

- **VideoFrame :** continuous requests will be sent to this endpoint in ***realtime***, there are many things to be taken care of like, what resolution does the device support, what if the device has poor bandwidth, there's no need for packet retransmission if the packet is lost then ignore and move foreward as you cant have delays in live feed (UDP: real time effecient protocol), thus we are using WebRTC. Some other useful protocols are MPEG-DASH or HLS.

- **Data base Communication :** most of the ***database solutions*** define how exactly the client interacts with the database, usually **DB-Solutions*** use a TCP based reliable protocol for data transmission, examples are as follows :
  1. MySQL, PostgresSQL (SQL)
  2. ElasticSearch uses HTTP based protocol
  3. Cassandra, Amazon DYnamo DB

- **Which DataBase ? :** We will be storing following kinds of data: 
  1. **Video Files** a file based database is essential, like HDFS, Amazon S3, VIMEO (Vido hosting solution),
(both amazon S3 and HDFS are cheap, easy to query, and can store large file, SQL databases are easy to query, but the capabilities provided by database won't be suitable for ***large static files***)
  2. **Comments and User :** Comment Data, might have a complex data structure and it's structure might be subject to dynamic change (maintaining conversation thread), if the datastructure is dynamically changing then SQL will not be an optimal choice as it stores the data by using normalization and modifying the number of columns will become an expensive process. Thus for comment data we go with a **NoSQL Database**, we can store the user data in a **SQL Database**  

- **Who fills the Data ? :** we need to allow the users to stream real time live footage, we need the streaming to be reliable from client to the database thus we use ***RTMP (Real Time Media Protocol)***. We can loose the data at the consumer side (thats why we are using WebRTC which is reliable enough for consumers but still there might be some data loss), but at the source we must ensure that there is no **Data Loss** as this will cause data loss to all the users, even the one's with good bandwidth.

- **Caching at server :** We can cache the recent segements of the video at the servers for fasteer response

- **Fault Tolerence :** We can use CDN(persists static data) authentication becomes a challenge when using CDN 




## How to convert RAW data and make it suitable for end users
- We need a ***transformation service*** which takes in live stream and converts it into different resoulutions
- we break the raw video into segments, and this segments are processed, and converted into different resolutions
- the transformation service converts the video into a particular resolution and format, based on the request recieved
- **MAP Reduce :** we break the high quality video into smaller segments send these segments to various servers which process these videos (the process can have n number of steps) independently. 



## References
1. Types of databases
2. Distributed Storage
3. Protocols for different behaviours (HTTP, WebRTC, RTMP)
4. Stateful vs Stateless (live feed)
5. Microservices
6. HighLevel Design Patterns (MAP REDUCE)