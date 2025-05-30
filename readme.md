# Argument Manipulator

A command-line tool written in C that reads each supplied argument and prints it in three forms: original, uppercase, and lowercase. I learned and gained the skills to complete this project from my operating systems course.

## Objective

Reinforce core C skills—pointers, dynamic memory allocation, and variadic functions—while gaining comfort in a Linux development environment.

## Tech Stack

- **Language**: C  
- **Build Tools**: GCC, Make
- **Environment**: Linux shell

## Features

- Parses any number of command-line arguments (including none).  
- Generates uppercase and lowercase copies of each argument using a reusable `manipulate_args` function.  
- Manages heap-allocated strings safely, with a `free_copied_args` variadic cleanup routine.


## Key Takeaways

- **Pointers & Strings**  
  Allocated and manipulated null-terminated C-strings with pointer arithmetic.

- **Dynamic Memory**  
  Employed `malloc`/`free` robustly and handled allocation failures gracefully.

- **Variadic Functions**  
  Created a flexible `free_copied_args` routine to clean up multiple string copies.

- **Command-Line Workflow**  
  Solidified Linux shell proficiency, GCC build processes, and Makefile usage.


## Quick Start

```bash
# Compile
gcc -o nyuc argmanip.c nyuc_main.c   # or: make

# Run with arguments
./nyuc Hello, world
# Output:
# [./nyuc]    -> [./NYUC]    [./nyuc]
# [Hello,]    -> [HELLO,]    [hello,]
# [world]     -> [WORLD]     [world]

# Run without arguments
./nyuc
# Output:
# [./nyuc]    -> [./NYUC]    [./nyuc]
