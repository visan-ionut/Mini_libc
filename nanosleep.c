// SPDX-License-Identifier: BSD-3-Clause

#include "internal/syscall.h"
#include "time.h"

//	Define the system call numbers for nanosleep
#define __NR_nanosleep 35

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	//	Make a system call to request the specified sleep duration
	long result = syscall(__NR_nanosleep, req, rem);

	if (result == -1)
		return -1;//	An error occured
	return 0;//	Succes
}
