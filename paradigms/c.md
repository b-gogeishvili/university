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

# Preprocessors

Before your program gets compiled, it actually runs through a phase called preprocessing. It’s almost like
there’s a language on top of the C language that runs first. And it outputs the C code, which then gets
compiled.

A header file is a file containing C declarations and macro definitions to be shared between several source files. You request the use of a header file in your program by including it, with the C preprocessing directive ‘#include’.

Including a header file produces the same results as copying the header file into each source file that needs it. Such copying would be time-consuming and error-prone. With a header file, the related declarations appear in only one place.

### Macros

A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro. There are two kinds of macros. They differ mostly in what they look like when they are used. Object-like macros resemble data objects when used, function-like macros resemble function calls. 

#### Object-like

An object-like macro is a simple identifier which will be replaced by a code fragment. It is called object-like because it looks like a data object in code that uses it. They are most commonly used to give symbolic names to numeric constants. For instance:

`#define BUFFER_SIZE 1024`

defines a macro named **BUFFER_SIZE** as an abbreviation for 1024. If somewhere after this ‘#define’ directive there comes a C statement of the form 

`int bufsize = BUFFER_SIZE;`

then the C preprocessor will recognize and expand the macro **BUFFER_SIZE**. The C compiler will see the same values as it would if you had written 

`int bufsize = 1024;`

#### Function-like

You can also define macros whose use looks like a function call. These are called function-like macros. To define a function-like macro, you use the same ‘#define’ directive, but you put a pair of parentheses immediately after the macro name. For example, 

```c
#define SQR(x) x * x

int main(void) {
    pintf("%d\n", SQR(12));
} 
```