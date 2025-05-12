# Structs

In C, there is something called a struct, which is a user-definable type that holds multiple pieces of data, potentially of different types.

You are familiar with the idea of classes and objects. These don’t exist in C, natively, but you can think of a struct as a class with only data members, and no methods.

You can declare a struct like so:

```c
struct car {
    char* name;
    float price;
    int speed;
}
```

When you do this, you’re making a new type. The full type name is `struct car`. (Not just `car` — that won’t work.)

#### How to initialize Struct?

```c
// Method 1
struct car saturn;

saturn.name = "Saturn SL/2";
saturn.price = 15999.99;
saturn.speed = 175;

// Method 2
struct car saturn = {"Saturn SL/2", 16000.99, 175}


printf("Name: %s\n", saturn.name);
printf("Price (USD): %f\n", saturn.price);
printf("Top Speed (km): %d\n", saturn.speed);
```

### Size of Structs

https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/