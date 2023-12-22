# Hello World

In ``println!("Hello, world!")``, `println!` calls a Rust macro.
If it had called a function instead, it would be entered as `println`
(without the `!`).

## Compiling and Running

```
$ rustc <file>.rs
$ ./<file>
```

Compiling using `rustc` is good for small programs, if you're gonna
build a bigger project using `Cargo` is more suitable. This is similar
to C, using `gcc` vs `Makefiles`.

# Summary

* Install the latest stable version of Rust using rustup
* Update to a newer Rust version
* Open locally installed documentation
* Write and run a “Hello, world!” program using rustc directly
* Create and run a new project using the conventions of Cargo
