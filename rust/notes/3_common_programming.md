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

* Functions
* Comments
* Control flow
