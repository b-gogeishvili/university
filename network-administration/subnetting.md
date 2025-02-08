### Subnet is a network inside a network

A subnetwork, or subnet, is a logical subdivision of an IP network. 

### Subnet Mask

In subnet mask 1 is network bit and 0 is host bit. 

For instance: 11111111.11111111.11111111.00000000
We have 24 network bits and 8 host bits.

By remembering [[ip-address]] and how it is divided into classes, we can determine their subnet masks:
- A class - 255.0.0.0
- B class - 255.255.0.0
- C class - 255.255.255.0

### Dividing network into subnetworks with subnet mask

We can add bits to the network part. For instance, lets take subnet mask of C class IPv4 address:

***We had*** - 11111111.11111111.11111111.00000000 - same as - 255.255.255.0
***We can add 1 bit to the network portion*** - 11111111.11111111.11111111.10000000 - same as - 255.255.255.128

So, network has 25 bits and host has 7 bits. Therefore, we have two subnets:
- x.x.x.0 - x.x.x.127
- x.x.x.128 - x.x.x.255 

**Subnet Range** is 256 - host portion (in decimal)

### Wildcard Mask

A wildcard mask is the inverse of a subnet mask. It is used in access control lists (ACLs) and routing protocols (such as OSPF and EIGRP) to match IP ranges. Instead of defining the network and host portions, a wildcard mask specifies which bits should be ignored (1s) and which should be matched (0s).

#### How to calculate Wildcard Mask

Wildcard Mask = 255.255.255.255 - Subnet Mask