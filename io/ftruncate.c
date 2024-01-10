#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Define the system call number for 'ftruncate' if not available.
#ifndef SYS_ftruncate
#define SYS_ftruncate 77
#endif

int ftruncate(int fd, off_t length)
{
    // Perform the 'ftruncate' system call.
    int result = syscall(SYS_ftruncate, fd, length);
    if (result < 0) {
        // An error occurred during the system call; set 'errno' to the error code.
        errno = -result;
        return -1;
    }
    return 0;
}
