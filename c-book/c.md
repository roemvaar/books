# C Programming Language

> These notes were taken from R&K C programming language book and are meant only for personal use

C is a general-purpose programming language. The language is not tied to any particular
operating system or machine. 

C provides a variety of data types. The fundamental data types are:

| Data types | Description |
| ---------- | ----------- |
| char       | character - a single byte |
| int        | integer     |
| short      | short integer |
| long       | long integer |
| float      | floating point number |
| double     | double-precision floating point |

The sizes of these objects are machine-dependent. Each compiler is free to choose appropiate
sizes for its own hardware, subject only to the restriction that shorts and ints are at least
16 bits, longs are at least 32 bits, and short is no longer than int, which is no longer than long.

There are also derived data types, i.e. user defined data types, created with:

- Pointers
- Arrays
- Structures
- Unions

The qualifier **signed** or **unsigned** may be applied to char or any integer. unsigned numbers
are always positive or zero, and obey the laws of arithmetic modulo 2<sup>n</sup>, where n is the
number of bits in the type. Example:

- If chars are 8 bits, unsigned char variables have values between 0 and 255, while signed chars
have values between -128 and 127 (in a two's complement machine).

In C expressions are formed from operators and operands. 

Pointers provide for machine-independent address arithmetic.

C provides the fundamental control-flow constructions required for well-structured programs:

- Statement grouping
- Decision making (if-else)
- Selecting one of a set of possible cases (switch)
- Looping with the termination test at the top (while, for)
- Looping with the termination test at the bottom (do)
- Early loop exit (break)

Functions may return values of:

- Basic data types
- Structures
- Unions 
- Pointers

The function of a C program may exist in separate source files that are compiled separately,
e.g. using a header file.

A preprocessing step performs macro substitution on program text, inclusion of other source 
file, and conditional compilation.

In C, all variables must be declared before they are used. A declaration announces the
properties of variables; it consists of a type name and a list of variables, such as:

```c
    int fahr;
    float interest;
```

Local variables are typically "automatic" or created anew with each invocation. Variables
may be:

- Internal to a function 
- External but known only within a single source file
- Visible to the entire program.

C has the basic philosophy that programmers know what they are doing; it only 
requires that they state their intentions explicitly.

**Functions**

In C, a function provides a convenient way to encapsulate some computation, which can be used
without worrying about its implementation. With properly designed functions, it is possible to
ignore how a job is done; knowing what is done is sufficient. C makes the use of functions easy,
convenient and efficient; you will often see a short function defined and called only once, just
because it clarifies some piece of code.

The following code

```c
    int power(int base, int n);
```

declares the parameter types and names, and the type of the result that the function returns.

We will generally use *parameter* for a variable named in the parenthesized list in a function
definition, and argument for the value used in a call of the function. The value that power
computes is returned to main by the return statement.

There's a return statement at the end of main. Since main is a function like any other, it may
return a value to its caller, which is in effect the environment in which the program was
executed. Typically, a return value of zero implies normal termination; non-zero values signal
unusual or erroneous termination conditions.

Function calls:

- Call by value: the called function is given the value of its arguments in temporary variables
rather than the originals.
- Call by reference: it is possible for a function to modify a variable in a calling routing.
The caller must provide the address of the variable to be set (technically a pointer to the
variable), and the called function must declare the parameter to be a pointer and access the
variable indirectly through it.


**Definition vs Declaration**

According to R&K,

- Declaration list the variables to be used, and state what type they have and perhaps what their
initial values are.

```c
    int a;
    float interest = 0.42;
```

"Definition" refers to the place where the variable is created or assigned storage;
"Declaration" refers to places where the nature of the variable is stated but no storage is
allocated.

For further information, look at ["What is the difference between a definition and a
declaration?"](https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration)
on StackOverflow.

