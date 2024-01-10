// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

// Write 'len' bytes from 'buf' to the file descriptor 'fd'.
ssize_t write(int fd, const void *buf, size_t len)
{
	int ret = syscall(__NR_write, fd, buf, len);

	if (ret < 0) {
		// An error occurred during the system call; set 'errno' to the error code.
		errno = -ret;
		return -1;
	}

	return ret;
}

// Read up to 'len' bytes from the file descriptor 'fd' into 'buf'.
ssize_t read(int fd, void *buf, size_t len)
{
	int ret =  syscall(__NR_read, fd, buf, len);

	if (ret < 0) {
		// An error occurred during the system call; set 'errno' to the error code.
		errno = -ret;
		return -1;
	}

	return ret;
}
