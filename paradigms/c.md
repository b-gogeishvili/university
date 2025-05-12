# C Programming Language

C is a low-level language. 

It didn’t use to be. Back in the day when people carved punch cards out of granite, C was an incredible way
to be free of the drudgery of lower-level languages like assembly. 

But now in these modern times, current-generation languages offer all kinds of features that didn’t exist in 1972 when C was invented. This means C is a pretty basic language with not a lot of features. It can do
anything, but it can make you work for it.

# Compiling C

C is a compiled language. Compilation is the process of taking your C source code and turning it into a program that your operating system can execute.

If you have a source file called hello.c in the current directory, you can build that into a program called
hello with this command typed in a terminal:

`gcc -o hello hello.c`

If your source is broken up into multiple files, you can compile them all together by putting all the .c files on the command line:

`gcc -o awesomegame ui.c characters.c npc.c items.c`

# Variables

| Type               | Example         | C Type  | Bytes (64bit arch) |
| :----------------- | :-------------: | :-----: | -----------------: |
| Integer            | 3490            | int     |         4          |
| Long Integer       | 12345678910     | long    |         8          |
| Floating Point     | 3.14f           | float   |         4          |
| Double-Precision   | 3.14159         | double  |         4          |
| Character (single) | 'c'             | char    |         1          |
| String             | "Hello, World!" | char *  |         x          |
| Boolean            | true            | bool    |         1          |

# printf()

_printf()_ prints variables using format specifiers that match the type of each variable.

```c
int n = 2;
float pi = 3.14f;
char a = 'a';
char* word = "example";

printf("This is an %s.", word);
printf("Pi is equal to %.2f", point); // .2 means that two number will be printed after a point, e.g. 3.14.
printf("Random examples - n = %d, a = %c", n, a);
```