# Cargo

Cargo is Rust's build system and package manager.

Cargo handles the tasks of building your code, downloading the
libraries your code depends on, and building those libraries.

The libraries that your code needs are called `dependencies`.

## Create new project using Cargo

```
$ cargo new <project>
$ cd <project>
```

## Building and running a Cargo project

```
$ cargo build
$ ./target/debug/<project>
```

Default build is a debug build.

Use `cargo run` for build and run with one command.

Use `cargo check` to make sure your code compiles but doesn't produce
an executable.
