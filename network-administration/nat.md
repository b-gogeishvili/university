# NAT

NAT (Network Address Translation) საშუალებას აძლევს ლოკალურ ქსელში არსებულ ჰოსტებს გავიდნენ გლობალურ ქსელში.

მნიშვნელოვანია, რომ გავითვალისწინოთ - პირადი IP მისამართები არ
გამოიყენება გლობალურ ქსელში. მაგალითად, ჩვენი პირადი მისამართიდან
გაგზავნილ და გამოგზავნილ მოთხოვნებს Internet Service Provider, ანუ ISP
ბლოკავს (დროპავს).

მიუხედავად იმისა, რომ როუტერის შიდა ინტერფეისებს აქვთ ლოკალური IP მისამართები, გარე ინტერფეისს შეიძლება ჰქონდეს გლობალური მისამართი, მაგალითად 203.0.113.1, რომელიც უნიკალურია. როდესაც ჩვენს პირად მოწყობილობას დასჭირდება, რომ მიწვდეს გლობალურ
ქსელს, NAT საშუალებას მოგვცემს „ვითხოვოთ“ უნიკალური გლობალური
მისამართი.

NAT საშუალებას გვაძლევს შევცვალოთ ქსელური პაკეტის წყაროსა და
დანიშნულების IP მისამართი. შეცვლა საჭირო ხდება იმისთვის, რომ Private
ჰოსტებმა შეძლონ გლობალურ ქსელში კომუნიკაცია. ეს საშუალებას გვაძლევს,
რომ ბევრმა მოწყობილობამ გამოიყენოს ერთი, უნიკალური გლობალური
მისამართი.

#### NAT-ის ორი მეთოდი

1. DNAT (Destination Network Address Translation) - შიდა ქსელში არსებული ჰოსტი ხელმისაწვდომია გლობალურად.
2. SNAT (Source Network Address Translation) - შიდა ქსელში არსებულ ჰოსტს აქვს წვდომა გლობალურ ქსელზე.


# Static NAT

სტატიკური NAT გულისხმობს ერთი-ერთზე კავშირს Private და Public
მისამართებს შორის. პირველ რიგში უნდა გვესმოდეს შემდეგი ტერმინები:

- **Inside Local IP Address** - Before translation source IP address located inside the local network.
- **Inside Global IP Address** - After translation source IP address located outside the local network.
- **Outside Global IP Address** - Before translation destination IP address located outside the remote network. 
- **Outside Local IP Address** - After translation destination IP address located inside the remote network.

კონფიგურაციისთვის სამი რამ გვჭირდება:

1. უნდა დავუკავშიროთ ლოკალური IP მისამართი გლობალურ მისამართს.
```
- ip nat inside source static {local_ip} {global_ip}
```

2. დავაკონფიგუროთ Inside Local Interface
```
- interface {interface}
- ip nat inside
```

3. დავაკონფიგუროთ Inside Global Interface
```
- interface {interface}
- ip nat outside
```


# Dynamic NAT

დინამიური NAT-ის დროს, როუტერი დინამიურად აკავშირებს Private IP მისამართებს გლობალურ მისამართთან. დინამიური NAT _არ_ გულისხმობს, რომ ჩვენ შეგვიძლია ერთი გლობალური მისამართი მრავალი ჰოსტისთვის გამოვიყენოთ. თუ როუტერი მიიღებს პაკეტს და ამ დროს Pool-ში გლობალური მისამართები დაკავებული იქნება, როუტერი ასეთ პაკეტს დადროპავს.

დინამიური NAT-ის შესაქმნელად უნდა ვიცოდეთ შემდეგი თემები:

1. ACL - ვქმნით იმ ჰოსტების დასადგენად, რომლებიც გვინდა, რომ გლობალურ ქსელს მიწვდნენ, ანუ ლოკალური მისამართების სია.
2. NAT Pool - ეს არის გლობალური მისამართების სია რომელიც მიენიშება ACL-ში დადგენილ ჰოსტებს.

კონფიგურაციისთვის ხუთი რამ გვჭირდება:

1. უნდა შევქმნათ Access List
```
- access-list 1 permit {network}
```

2. უნდა შევქმნათ NAT Pool
```
- ip nat pool {name} {start_ip} {end_ip} netmask {subnet_mask}
```

3. დავუკავშიროთ ერთმანეთს Access List და NAT Pool
```
- ip nat inside source list {acl_num_or_name} pool {pool_name}
```

4. დავაკონფიგუროთ Inside Local Interface
```
- interface {interface}
- ip nat inside
```

5. დავაკონფიგუროთ Inside Global Interface
```
- interface {interface}
- ip nat outside
```


# PAT

PAT გარდაქმნის როგორც მისამართებს, ასევე პორტებსაც. მაგალითად, თითოეულ პაკეტზე სხვადასხვა უნიკალური პორტის გამოყენებით, ჩვენ შეგვიძლია ერთი გლობალური IP გამოვიყენოთ ბევრი მოწყობილობისთვის.