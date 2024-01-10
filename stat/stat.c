#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

// Get file status for the file at 'path' and store it in the 'buf' structure.
int stat(const char *restrict path, struct stat *restrict buf)
{
    int result;

    // Use the correct system call number for stat
    result = syscall(__NR_stat, path, buf);

    if (result < 0) {
        // An error occurred, set errno
        errno = -result;
        return -1;
    }

    return 0;
}
