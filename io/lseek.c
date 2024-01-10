#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// Define the system call number for 'lseek' if not available.
#ifndef SYS_lseek
#define SYS_lseek 8
#endif

// Set the file offset of 'fd' to 'offset' according to 'whence'.
off_t lseek(int fd, off_t offset, int whence)
{
    // Perform the 'lseek' system call.
    off_t result = syscall(SYS_lseek, fd, offset, whence);
    if (result < 0) {
        // An error occurred during the system call; set 'errno' to the error code.
        errno = -result;
        return (off_t)-1;
    }
    return result;
}
