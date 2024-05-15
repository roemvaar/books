# Ownership

Ownership is a set of rules that govern how a Rust program manages memory.

All programs have to manage the way they use a computer's memory while running.
The two most common approaches are:

1. Some languages have **garbage collection** that regularly looks for no-
longer-used memory as the program runs.

2. In other languages, the programmer must **explicitly allocate and free the
memory**.

Rus uses another approach:

3. Memory is managed through a system of ownership with a set of rules that the
compiler checks. If any rules are violated, the program won't compile. None of
the features of ownership will slow down your program while it's running.

## Stack and Heap

Both the stack and the heap are parts of memory available to your code to use
at runtime, but they are structured in different ways.

The stack stores values in the order it gets them and removes the values in the
opposite order. Last in, first out. You can push and pop data from the stack.
All data stored on the stack must have a known, fixed size.

The heap is less organized: when you put data on the heap, you request a certain amount of space. The memory allocator finds an empty spot in the heap
that is big enough, marks it as being in use, and returns a pointer, which is
the address of that location (the process is called allocating).

## References

A reference is like a pointer in that it's an address we can follow to
access the data stored at that address; the data is owned by some other
variable. Unlike a pointer, a reference is guaranteed to point to a valid
value of a particular type for the life of that reference.

& - ampersands represent references, and they allow to refer to some value
without ownership of it.

The opposite of referencing by using & is dereferencing, which is
accomplished with the dereference operator, *.

We call the action of creating a reference borrowing. As in real life,
if a person owns something, you can borrow it from them. When you're done,
you have to give it back. You don't own it.

Just as variables are immutable by default, so are references. We're not
allowed to modify something we have a reference to.

## Data Race

A data race is similar to a race condition and happens when these three
behaviours occur:

* Two or more pointers access the same data at the same time
* At least one of the pointers is being used to write to the data
* There's no mechanism being used to synchronize access to the data

Data race cause undefined behaviour and can be difficult to diagnose and fix
when you're trying to track them down at runtime.

## Dangling Pointers

In languages with pointers, it's easy to erroneously create a dangling
pointer - a pointer that references a location in memory that may have been
given to someone else - by freeing some memory while preserving a pointer
to that memory.

## The Rules of References

* At any given time, you can have either one mutable reference or any
number of immutable references
* References must always be valid

## The Slice Type

Slices let you reference a contiguous sequence of elements in a collection
rather than the whole collection. A slice is kind of reference, so it does
not have ownership.

## Summary

The concept of ownership, borrowing, and slices ensure memory safety in
Rust programs at compile time. The Rust language gives you control over
your memory usage in the same way as other systems programming languages,
but having the owner of data automatically clean up that data when the
owner goes out of scope means you don't have to write and debug extra
code to get this control.
