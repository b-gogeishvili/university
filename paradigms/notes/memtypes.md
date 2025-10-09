When a program starts, operating system allocates virtual memory and maps it to physical memory.

Allocated memory is divided into three categories:

- Static
- Stack
- Heap

### Static

Static memory, also known as the data segment, stores global variables, static local variables, and constants. It is managed by the compiler and exists for the entire duration of the program. Unlike stack and heap, memory in the static area is initialized only once and retains its value between function calls.

### Stack

Stack memory is used for storing local variables, function parameters, and return addresses. It is automatically managed by the compiler and exists only for the duration of a function call. Stack memory is very fast and typically grows downward in memory. However, it is limited in size and can overflow if too much memory is used.

### Heap

Heap memory is used for dynamic memory allocation, typically via functions like malloc() or calloc() in C. It is manually managed by the programmer, meaning you must explicitly free the memory using free(). Heap memory persists until it is freed, regardless of function scope.

---

See: malloc, free, calloc, realloc.