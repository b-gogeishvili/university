### IPv4 address

IPv4 address is a 32 bit number. It is divided by 4 parts, called octets. Every octet ranges from 0 to 255 ( 2^8  - 1 ).

IPv4 is unique address that is used to identify hosts (devices) in the network. 

It is logically divided into **two parts**, one representing network address and the other representing host address.

IPv4 is divided into classes. A class being the biggest, each one is used for smaller networks.

* A class - First octet is the network part ( 1-126 : 00000001-01111110 )
* B class - First two octets are network parts ( 128-191 : 10000000-10111111 )
* C class - First three octets are network parts ( 192-223 : 11000000-11011111 )
* D class - All octets are host parts ( 224-239 : 11100000-11101111 )
* E class - For experimenting ( 240-255 : 11110000-11111111 )

There are two addresses that can't be assigned to a host
1. Network address (first)
2. Broadcast address (last)
