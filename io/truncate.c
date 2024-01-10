#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Define the system call number for 'truncate' if not available.
#ifndef SYS_truncate
#define SYS_truncate 76
#endif

// Truncate the file at 'path' to the specified 'length'.
int truncate(const char *path, off_t length)
{
    // Perform the 'truncate' system call.
    int result = syscall(SYS_truncate, path, length);
    if (result < 0) {
        // An error occurred during the system call; set 'errno' to the error code.
        errno = -result;
        return -1;
    }
    return result;
}
