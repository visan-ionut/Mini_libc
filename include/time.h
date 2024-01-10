// SPDX-License-Identifier: BSD-3-Clause

#ifndef TIME_H
#define TIME_H

#include <stddef.h>

// Define the time_t type
typedef long time_t;

// Define the timespec structure
struct timespec {
    time_t tv_sec;      // seconds
    long tv_nsec;       // nanoseconds
};

// Function declarations
int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

// Define the constants required for nanosleep
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1

#endif /* TIME_H */

