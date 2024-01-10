// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

// Map files or devices into memory.
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    // Invoke the system call using syscall with the appropriate arguments.
    unsigned long result = syscall(__NR_mmap, (unsigned long)addr, (unsigned long)length,
        (unsigned long)prot, (unsigned long)flags, (unsigned long)fd, (unsigned long)offset);
    if (result > -4096UL) {
        // If the result is greater than -4096, it indicates an error.
        // Set 'errno' to the error code and return 'MAP_FAILED' to signify an error.
        errno = -result;
        return MAP_FAILED;
    }
    return (void *)result;
}

// Remap a memory region to a new size.
void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
    // Invoke the system call using syscall with the appropriate arguments.
    unsigned long result = syscall(__NR_mremap, (unsigned long)old_address,
        (unsigned long)old_size, (unsigned long)new_size, (unsigned long)flags);
    if (result > -4096UL) {
        // If the result is greater than -4096, it indicates an error.
        // Set 'errno' to the error code and return 'MAP_FAILED' to signify an error.
        errno = -result;
        return MAP_FAILED;
    }
    return (void *)result;
}

// Unmap a memory region.
int munmap(void *addr, size_t length)
{
    // Invoke the system call using syscall with the appropriate arguments.
    unsigned long result = syscall(__NR_munmap, (unsigned long)addr, (unsigned long)length);
    if (result > -4096UL) {
        // If the result is greater than -4096, it indicates an error.
        // Set 'errno' to the error code and return -1 to signify an error.
        errno = -result;
        return -1;
    }
    return 0;
}

