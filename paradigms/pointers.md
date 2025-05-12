# What are pointers?

The one thing about C that hangs people up is pointers. Virtually everything else is familiar, but pointers are the weird one. The concept behind pointers is likely one you already know, but C forces you to be explicit about it, using operators you’ve likely never seen before.

Computer memory holds data of all kinds, right? It’ll hold floats, ints, or whatever you have. To make memory easy to cope with, each byte of memory is identified by an integer. These integers increase sequentially as you move up through memory. You can think of it as a bunch of numbered boxes, where each box holds a byte of data. Or like a big array where each element holds a byte, if you come from a language with arrays. The number that represents each box is called its address.

Now, not all data types use just a byte. For instance, an int is often four bytes, as is a float, but it really depends on the system. You can use the sizeof() operator to determine how many bytes of memory a certain type uses.

#### *A pointer is a variable that holds an address*

They are the address of data. Just like an int variable can hold the value 12, a pointer variable can hold the address of data.

You can identify the pointer type because there’s an asterisk (*) before the variable name and after its type.

```c
int main(void)
{
    int i; // i's type is "int"
    int *p; // p's type is "pointer to an int", or "int-pointer"
}
```
When you do an assignment into a pointer variable, the type of the right hand side of the assignment has to
be the same type as the pointer variable. Additionally, we can get address-of a variable with '&'.

```c
int i;
int *p; // p is a pointer, but is uninitialized and points to garbage
p = &i; // p is assigned the address of i, p now "points to" i
```

### Dereferencing

When you have a pointer to a variable (roughly “a reference to a variable”), you can use the referenced variable
through the pointer by dereferencing the pointer. You can think of this as “de-pointering” the pointer.

```c
#include <stdio.h>

int main(void)
{
    int i;
    int *p; // this is NOT a dereference--this is a type "int*"

    p = &i; // p now points to i, p holds address of i

    i = 10; // i is now 10
    *p = 20; // the thing p points to (namely i!) is now 20!!

    printf("i is %d\n", i); // prints "20"
    printf("i is %d\n", *p); // "20"! dereference-p is the same as i!
}
```

---

Good to know: When you have a data type (like your typical int) that uses more than a byte of memory, the bytes that make up the data are always adjacent to one another in memory. Sometimes they’re in the order that you expect, and sometimes they’re not. While C doesn’t guarantee any particular memory order (it’s platform-dependent), it’s still generally possible to write code in a way that’s platform-independent where you don’t have to even consider these pesky byte orderings.

The order that bytes come in is referred to as the endianness of the number. The usual suspects are big-endian (with the most significant byte first) and little-endian (with the most-significant byte last), or, uncommonly now, mixed-endian (with the most-significant bytes somewhere else).