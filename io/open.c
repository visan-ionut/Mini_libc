#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

// Define the system call number for 'open' if not available.
#ifndef SYS_open
#define SYS_open 2
#endif

// Open a file specified by 'filename' with the given 'flags' and optional 'mode'.
int open(const char *filename, int flags, ...)
{
    int mode = 0;
    // If the 'O_CREAT' flag is set, extract the 'mode' from the variable arguments.
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, int);
        va_end(args);
    }

    // Perform the 'open' system call.
    int result = syscall(SYS_open, filename, flags, mode);
    if (result < 0) {
        // An error occurred during the system call; set 'errno' to the error code.
        errno = -result;
        return -1;
    }
    return result;
}
