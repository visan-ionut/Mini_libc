// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1 //	Define STDOUT_FILENO if not available
#endif

#ifndef EOF
#define EOF (-1) //	Define EOF if not available.
#endif

int puts(const char *s)
{
	int len = 0;

	//	Calculate the length of the string.
	while (s[len] != '\0')
		len++;

	if (write(STDOUT_FILENO, s, len) != len)
		return EOF;//	Return an error code if not all bytes were written.

	//	Add a newline character.
	if (write(STDOUT_FILENO, "\n", 1) != 1)
		return EOF;
	//	Return the total number of characters written, including the newline.
	return len + 1;
}

