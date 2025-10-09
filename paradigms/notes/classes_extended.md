## Destructor

A destructor is a special member function in C++ that is automatically 
called when an object goes out of scope or is deleted.

Syntax:
```cpp
class MyClass {
public:
    ~MyClass() {
        cout << "Destructor called!\n";
    }
};
```

## Static Members

A class method or attribute can be static. This means that it belongs to the class,
not the specific object. It is shared accross all instances of the class and must
be defined outside the class once.

#### Static Member Variables

```cpp
class Counter {
public:
    static int count; // Declaration
    Counter() {
        count++;
    }
};

int Counter::count = 0; // Definition (required)

int main() {
    Counter c1, c2, c3;
    cout << Counter::count; // Output: 3
}
```
#### Static Member Functions

```cpp
class Utility {
public:
    static void sayHello() {
        cout << "Hello!\n";
    }
};

int main() {
    Utility::sayHello(); // Call without object
}
```

## Friend class

A friend class can access the private and protected members of another class.

```cpp
class Engine {
private:
    int power = 400;

    // Declare friend class
    friend class Car;
};

class Car {
public:
    void showPower(const Engine& e) {
        cout << "Engine power: " << e.power << " HP\n"; // Accessing private member
    }
};
```

## Operator Overloading

Operator Overloading lets you redefine how operators (like +, ==, [], etc.) behave for your own classes.

```cpp
class Complex {
public:
    double real, imag;

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void print() {
        cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex a(1.2, 3.4);
    Complex b(5.6, 7.8);
    Complex c = a + b;  // Uses overloaded +
    c.print();          // Output: 6.8 + 11.2i
}
```
Operator names and their correspondent examples:

opeartor+ - a+b
opeartor- - a-b
opeartor== - a==b
operator[] - a[5]
opeartor() - a(10)
opeartor<< - cout << obj
operator>> - cin >> obj

## Inheritance

Inheritance is a core feature of Object-Oriented Programming (OOP), 
and in C++ it allows you to create a new class (child/derived) that inherits 
properties and behaviors (members and methods) from an existing class (parent/base).

Syntax:

```cpp
class Base {
public:
    void show() {
        cout << "Base class\n";
    }
};

class Derived : public Base {
    // Inherits show()
};

int main() {
    Derived d;
    d.show();  // Output: Base class
}
```
> Derived class gets variables, methods and opeartors of a Base class.
> ! Derived class do net get constructors and destructors, friend classes and assign (=) operator;

Example:
```cpp
class Animal {
public:
    Animal(string name) {
        cout << "Animal Constructor: " << name << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {  // Explicitly call base constructor
        cout << "Dog Constructor\n";
    }
};

int main() {
    Dog d("Rex");
}
```

Output:
```
Animal Constructor: Rex
Dog Constructor
```

There are 3 types of inheritance:

#### Public - `class Derived : public Base`
- Public/Protected members of Base stay public/protected in Derived

#### Protected - `class Derived : protected Base`
- Public members of Base become protected in Derived

#### Private - `class Derived : private Base`
- All inherited members become private in Derived

## Polymorphism

Polymorphism allows the same function or operator to behave differently depending on context.

### Compile-Time Polymorphism

Operator overloading is an example of compile-time Polymorphism.
Also, functions with same name but different parameters:

```cpp
class Printer {
public:
    void print(int x) {
        cout << "Integer: " << x << endl;
    }
    void print(string s) {
        cout << "String: " << s << endl;
    }
};
```

### Run-Time Polymorphism

Run-time polymorphism is achieved using virtual functions, base class pointers
and function overriding.

Virtual keyword allows derived classes to override base class methods and ensuring that the correct 
version is called based on the actual object type, not the pointer type.

Example:

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!\n";
    }
};

int main() {
    Animal* a = new Dog();
    a->speak();  // Output: Woof!
    delete a;
}
```

## Abstract

An abstract class in C++ is a class that cannot be instantiated 
(you cannot create objects of it directly). It’s meant to serve as a base class (a blueprint for other classes).

Abstract class is created by declaring at least one pure virtual function:

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
};
```

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Abstract method
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};
```
