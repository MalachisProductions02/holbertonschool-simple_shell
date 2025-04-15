# simple_shell

## Description
**simple shell** is a simple UNIX command interpreter written in C that mimics the behavior of the original UNIX shell.
It allows the user to interact with the operating system by typing commands which are then executed.

---

## Features
- Display a prompt and wait for user input.
- Execute commands with arguments.
- Handle built-in commands ('exit', 'env').
- Use PATH enviroment variable to locate executables.
- Handle errors gracefully.
- Works in both interactive and non-interactive modes.

---

## Compilation
Compile using:
'''bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
