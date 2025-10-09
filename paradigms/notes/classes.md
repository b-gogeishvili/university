In C++ a class has following structure:

- **Constructor** - initializes an object.
- **Destructro** - runs when object is deleted.
- **Operator** - C++ has the ability to provide the operators with a 
                 special meaning for a data type, this ability is known as 
                 operator overloading. Operator overloading is a compile-time
                 polymorphism. For example, we can overload an operator '+' 
                 in a class like String so that we can concatenate two 
                 strings by just using +. 
- **Methods** - functions for classes.
- **Attributes** - variables for classes.

### Access Specifers

We have 3 access specifiers: private, public and protected.

```cpp
class class_name {
access_specifier_1:
...

access_specifier_2:
...

};
```

- **private** - Only class members and friend classess can access.
- **protected** - Same as private + child classess.
- **public** - No restrictions.


### Constructors

Constructor is a special member function that runs when an object is initialized.
It can be overloaded (multiple functions with different parameters).
There are three types of constructors:

- **Default** - a constructor with no parameters.
- **Parameterized** - a constructor that takes arguments.
- **Copy** - a constructor that creates a new object as a copy of an existing one.

```cpp
class Person {
public:
    string name;

    Person() {
        std::cout << "Object Initialized without any parameters!"; // default
    }

    Person(string n) {  // parameterized
        name = n;
    }

    Person(const Person& other) {  // copy constructor
        name = other.name;
    }
};

int main() {
    Person p1("Bob");
    Person p2 = p1;  // Calls copy constructor
}
```

### Creating Objects

In C++, once you've defined a class, you can create objects (instances of that class) in several ways.

```cpp
class Car {
public:
    string brand;
    void honk() {
        cout << "Beep!\n";
    }
};

int main() {
    Car myCar;           // Object creation
    myCar.brand = "BMW"; // Accessing member variable
    myCar.honk();        // Calling member function
}
```

> ⚠️ **Important Note:** Keep in mind that `Car mycar();` is not valid syntax for default constructors. 
                         We have to use `Car mycar;`


We can initialize class object in Stack memory or Heap memory.

Above is an example of intializing Class in stack memory.

In order to initialize object in Heap, we can use pointers and `new` keyword.

```cpp
class Box {
public:
    int size;
    Box(int s) { size = s; }
};

int main() {
    Box* b = new Box(10);         // Dynamic allocation
    cout << b->size << endl;      // Use '->' for pointer access
    delete b;                     // Free memory
}
```

### Constructor Initialization List

It's a way to initialize class members before the constructor body runs.

It’s required for:
- const members

- Reference members

- Members without default constructors

It’s often more efficient, especially for objects, because it avoids extra copy/move operations.

```cpp
class Car {
    const string brand;
    int year;
    double engineSize;

public:
    Car(string b, int y, double e)
        : brand(b), year(y), engineSize(e) {
        cout << brand << " | " << year << " | " << engineSize << "L" << endl;
    }
};

```

### this keyword

`this` is a pointer to the current object on which the method is called. 

```cpp
class Car {
    string brand;
public:
    Car(string brand) {
        this->brand = brand; // `this->brand` is the member, `brand` is the parameter
    }

    void print() {
        cout << "Brand: " << this->brand << endl;
    }
};
```
