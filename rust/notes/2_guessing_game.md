# Guessing Game

We'll implement a classic beginner programming problem: a guessing
game. Here's how it works:

* The program will generate a random integer between 1 and 100
* It will prompt the player to enter a guess
* After a guess is entered, the programm will indicate whether the guess
is too low or too high
* If the guess is correct, the game will print a congratulatory message and
exit

## Variables and mutability

In Rust, variables are immutable by default, meaning once we give the variable a value, the value won't change.

```
let apples = 5; // immutable
let mut bananas = 5;  // mutable
```

## Documentation

To build documentation of your local projects and its dependencies run:

```
$ cargo doc --open
```

## Summary

This project was a hands-on way to introduce you to many new Rust concepts:
let, match, functions, the use of external crates, and more. In the next
few chapters, you'll learn about these concepts in more detail. Chapter 3
covers concepts that most programming languages have, such as variables,
data types, and functions, and shows how to use them in Rust. Chapter 4
explores ownership, a feature that makes Rust different from other
languages. Chapter 5 discusses structs and method syntax, and Chapter 6
explains how enums work.
