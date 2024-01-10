=========
Mini libc
=========

A minimalistic standard C library implementation for Linux systems (named mini-libc),
that can be used as a replacement for the system libc (glibc in Linux).
The goal is to have a minimally functional libc with features such as string
management, basic memory support and POSIX file I/O.

Objectives
Learn about the structure and functionalities provided by the standard C library.
Accommodate with the syscall interface in Linux.
Gain a better understanding of strings and memory management functions.
Learn how the standard C library provides support for low-level input/output operations.

<string.h>: defines string-handling functions
<stdio.h>: defines printing and I/O functions
<unistd.h>, <sys/fcntl.h> and <sys/stat.h>: define I/O primitives
<stdlib.h> and <sys/mman.h> define memory allocation functions
<errno.h> and errno.c: declare and define the integer variable errno,
which is set by system calls and some library functions in the event of an error
to indicate what went wrong.

