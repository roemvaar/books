# Common Programming Concepts

Core programming concepts in the context of Rust.

## Variables

Variables are immutable by default. You have the option to make them
mutable.

Immutable: `let x = 5;`

Mutable: `let mut x = 5;`

## Constants

Like immutable variables, constants are values that are bound to a name
and are not allowed to change, but there are a few differences between
constants and variables.

You aren't allowed to use `mut` with constants. You declare constants
using the `const` keyword instead of the `let` keyword. You must always
annotate the type.

## Shadowing

You can declare a new variable with the same name as previous variable.
The first variable is *shadowed* by the second.

Shadowing allows us to mutate the data type of the variable we're using.

## Basic types

Every value in Rust is of a certain data type, which tells Rust what kind
of data is being specified so it knows how to work with that data. 

Rust is statically typed language, which means that it must know the types
of all variables at compile time.

## Scalar Types

A `scalar` type represents a single value. Rust has four primary scalar
types: integers, floting-point numbers, Booleans, and characters.

Integers can be signed or unsigned, and can be 8, 16, 32, 64, 128 bit long
or arch long (using isize). Signed numbers are stored using two's complement
representation.

Rust also has two primitive types for floating-point numbers, which are 
numbers with decimal points. Rust’s floating-point types are f32 and f64, 
which are 32 bits and 64 bits in size, respectively. The default type is 
f64 because on modern CPUs, it’s roughly the same speed as f32 but is 
capable of more precision. All floating-point types are signed.

Boolean type has two values: true and false. Booleans are one byte in
size.

Note that we specify char literals with single quotes, as opposed to string 
literals, which use double quotes. Rust’s char type is four bytes in size 
and represents a Unicode Scalar Value, which means it can represent a lot 
more than just ASCII.

## Compound Types

Compound types can group multiple values into one type. Rust has two
primitive compound types: tuples and arrays.

A tuple is a general way of grouping together a number of values with
a variety of types into one compound type. Tuples have a fixed length:
once declared, they cannot grow or shrink in size.

Another way to have a collection of multiple values is with an array.
Unlike a tuple, every element of an array must have the same type.
Arrays in Rust have a fixed length.

Arrays are useful when you want your data allocated on the stack rather
than the heap or when you want to ensure you always have a fixed number
of elements.

A vector is a similar collection type provided by the standard library
that is allowed to grow or shrink in size. If you're unsure whether to
use an array or a vector, chances are you should use a vector.

## Functions

We define a function in Rust by entering `fn` followed by a function name
and a set of parenthesis. The curly brackets tell the compiler where the
function body begins and ends.

Rust doesn't care where you define your functions (before or after you call
them), only that they're defined somewhere in a scope that can be seen by
the caller.

We can define functions to have parameters, which are special variables that
are part of a function's signature. Technically, the concrete values are
called arguments. In casual conversation, people tend to use the words
parameters and argument interchangeably for either the variables in a
function's definition or the concrete values passed in when you call a
function.

In function signatures, you must declare the type of each parameter.

Functions bodies are made up of a series of statements optionally ending
in an expression.

Statements are instructions that perform some action and do not return
a value.

Expressions evaluate to a resultant value.

## Comments

Simple comment:

``// Hello world`

For comments that extend beyond a single line, you'll need to include `//`
on each line.

You'll more often see comments used in the format where the comment is on
a separate line above the code it's annotating.

## Control flow

If statements are expecting a boolean expresion, if the expression is true
it will execute the block of code inside the brackts. You can also specify
else if and else statements to control the flow of your program.

## Repetition with Loops

Rust has three kinds of loops: `loop`, `while`, and `for`.
