#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Define the system call number for 'close' if not available.
#ifndef SYS_close
#define SYS_close 3
#endif

int close(int fd)
{
    // Perform the 'close' system call.
    int result = syscall(SYS_close, fd);
    if (result < 0) {
        // An error occurred during the system call; set 'errno' to the error code.
        errno = -result;
        return -1;
    }
    return 0;
}
