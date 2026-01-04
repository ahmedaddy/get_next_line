# get_next_line

## Description
**get_next_line** is a C function that reads a line from a file descriptor, returning it one line at a time on each call.  
The goal of this project is to deepen the understanding of file descriptors, static variables, memory allocation, and buffer management in C.

The function handles reading from regular files as well as standard input and supports multiple file descriptors simultaneously (bonus part).

## Function Prototype
```c
char    *get_next_line(int fd);
How It Works

Reads from a given file descriptor using a fixed buffer size (BUFFER_SIZE)

Returns a line ending with \n (except for the last line if EOF is reached)

Manages leftover data between calls using static variables

Allocates memory dynamically and frees it when necessary

Files Structure
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c        (bonus)
├── get_next_line_utils_bonus.c  (bonus)
└── README.md

Compilation

You can compile the project using:

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c


For the bonus version:

gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c

Usage Example :
check main.c

