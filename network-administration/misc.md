# Miscellaneous

## DHCP

```
- ip dhcp pool {pool_name}
- default-router {gateway_ip}
- network {network_ip} {network_subnet_mask}
- dns-server {dns_server_ip}
```

## Setting password to privileged mode

```
- enable secret {password}
```

## Setting password to virtual interface

```
- line vty 0 4
- password {password}
- login
```

## Copy configuration to remote server

```
- copy running-config tftp:
```