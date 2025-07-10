Functional Programming (FP) is a programming paradigm where computation is treated as the evaluation of mathematical functions, and programs are built by composing pure functions instead of changing state or using loops.

### Core Concepts

- **No Side Effects** - No changes to external state (no modifying global variables, I/O, etc.)
- **Pure Functions** - A function with no side effects and same output for same input
- **Immutability** - Data cannot be changed — create new copies instead
- **First-Class Functions** - Functions can be passed, returned and assigned to variables
- **Higher-Order Functions** - Functions that take functions as arguments or return Functions

Benefits of Functional Programming
- Easier to reason about: no hidden state

- Fewer bugs: because of pure functions and immutability

- Easier to test: output depends only on input

- Concurrency-friendly: no shared mutable state

### Imperative vs Functional

#### Focus
- **Imperative:** Focuses on *how* to do things step-by-step.
- **Functional:** Focuses on *what* to do by declaring desired outcomes.

#### State
- **Imperative:** Uses mutable state (variables are updated as the program runs).
- **Functional:** Emphasizes immutability; data is not modified once created.

#### Functions
- **Imperative:** Functions may have side effects and rely on/modifying global state.
- **Functional:** Functions are pure — same input always gives same output and has no side effects.

#### Control Flow
- **Imperative:** Uses explicit loops (`for`, `while`, etc.).
- **Functional:** Uses recursion and higher-order functions like `map`, `filter`, and `reduce`.

#### Data Handling
- **Imperative:** Often modifies data structures in-place.
- **Functional:** Creates and returns new versions of data structures.

#### Concurrency
- **Imperative:** Concurrency is harder due to shared mutable state.
- **Functional:** Easier to manage due to no shared state or side effects.

## Lambda

Lambda expressions in C++ are a way to define anonymous functions directly in your code, allowing you to write short snippets of code without needing to name them.

Syntax:
```cpp
[capture](parameters) -> return_type {
    // function body
};
```

```cpp
int factor = 10;

auto multiply = [factor](int x) {
    return x * factor;
};

cout << multiply(5);  // Output: 50
```
