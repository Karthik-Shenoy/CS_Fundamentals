# Networking


### Things to remember 
- TLS sits between the transport and the application layer (OSI is not a strict standard, so we can place TLS at application or presentation layer). A TLS handshake advertises the Ciphers and security capabilities supported by the hosts, and decides the capabilities that will be used throughout the connections (also key exchange occurs here) 