#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

// Get file status for the file descriptor 'fd' and store it in the 'st' structure.
int fstat(int fd, struct stat *st)
{
    int result;

    // Use the correct system call number for fstat
    result = syscall(__NR_fstat, fd, st);

    if (result < 0) {
        // An error occurred, set errno
        errno = -result;
        return -1;
    }

    return 0;
}
