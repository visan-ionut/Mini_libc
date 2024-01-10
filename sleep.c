// SPDX-License-Identifier: BSD-3-Clause

#include "time.h"

//	Suspends program execution for 'seconds' seconds.
unsigned int sleep(unsigned int seconds)
{
	struct timespec req, rem;

	req.tv_sec = seconds;
	req.tv_nsec = 0;

	//	If nanosleep is interrupted and there is time remaining in 'rem', retry the sleep.
	while (nanosleep(&req, &rem) == -1) {
		if (rem.tv_sec == 0 && rem.tv_nsec == 0)
			break;//	The sleep completed
		req = rem;//	Update the sleep request to the remaining time.
	}

	return 0;
}
