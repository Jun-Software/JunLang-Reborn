# JunLang Reborn

JunLang Reborn is a lightweight C++17 language/interpreter project.
The repository currently provides a command-line program that reads and executes `JunLang` source files.

## Features

- C++17
- Reads source code from files
- Prints version and usage when no argument is provided
- Supports comments and basic expression parsing

## Build

The project uses CMake:

```bash
cmake -S . -B build
cmake --build build
```

## Run

Pass a source file path to the executable:

```bash
JunLang <filename>
```

If no argument is provided, the program prints its version and usage.

## Syntax Notes

- Keywords and identifiers are converted to lowercase when read
- Whitespace is normalized
- Everything after `#` is treated as a comment

## Project Layout

- `src/main.cpp`: program entry point
- `src/read.hpp`: file reading logic
- `src/interpreter.hpp`: interpreter entry
- `src/init.hpp`: basic types, global state, and helpers

## Version

Current version: `v1.0.0`

## License

This project uses the license listed in `LICENSE`.
