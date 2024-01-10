// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    // Create a pointer 'dest' to keep track of the current position in 'destination'.
    char *dest = destination;

    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    // Null-terminate the destination string
    *dest = '\0';
    return destination;
}


char *strncpy(char *destination, const char *source, size_t len)
{
    // Create a pointer 'dest' to keep track of the current position in 'destination'.
    char *dest = destination;

    // Copy characters from 'source' to 'destination' while there are more characters
    // to copy and the source character is not a null terminator.
    while (len > 0 && (*source != '\0')) {
        *dest++ = *source++;
        len--;
    }

    while (len > 0) {
        *dest++ = '\0';
        len--;
    }

    return destination;
}


char *strcat(char *destination, const char *source)
{
    char *dest = destination;

    // Move the destination pointer to the end of the string
    while (*dest != '\0') {
        dest++;
    }

    // Copy characters from the source to the destination
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    // Null-terminate the destination string
    *dest = '\0';

    return destination;
}


char *strncat(char *destination, const char *source, size_t len)
{
    char *dest = destination;

    // Move the destination pointer to the end of the string
    while (*dest != '\0') {
        dest++;
    }

    // Copy characters from the source to the destination, up to 'len' characters
    while (*source != '\0' && len > 0) {
        *dest = *source;
        dest++;
        source++;
        len--;
    }

    // Null-terminate the destination string
    *dest = '\0';

    return destination;
}


int strcmp(const char *str1, const char *str2)
{
    // Iterate through the characters of 'str1' and 'str2' until a difference is found.
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0; // Both strings are equal
        }
        str1++;
        str2++;
    }

    // If a difference is found, return the difference of the mismatched characters.
    return *str1 - *str2;
}


int strncmp(const char *str1, const char *str2, size_t len)
{
    // Iterate through the characters of 'str1' and 'str2' for up to 'len' characters.
    while (len > 0) {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        } else if (*str1 == '\0') {
            return 0; // Both strings are equal up to 'len' characters
        }

        // Move to the next character in each string and decrement 'len'.
        str1++;
        str2++;
        len--;
    }

    return 0; // Both strings are equal up to 'len' characters
}


size_t strlen(const char *str)
{
	size_t i = 0;

    // Iterate through the characters of 'str' until a null terminator ('\0') is encountered.
	for (; *str != '\0'; str++, i++)
        // No explicit return statement is needed as 'i' will contain the length when the loop exits.
		;

	return i;
}

char *strchr(const char *str, int c)
{
    while (*str != '\0') {
        // If the current character matches 'c', return a pointer to this character in 'str'.
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }

    // If 'c' is not found, return NULL
    return NULL;
}


char *strrchr(const char *str, int c)
{
    // Initialize a pointer to the last occurrence of 'c' to NULL.
    const char *last = NULL;

    // Iterate through the characters of 'str' until a null terminator ('\0') is encountered.
    while (*str != '\0') {
        if (*str == (char)c) {
            last = str;
        }
        str++;
    }

    // If 'last' is not NULL, it means 'c' was found in 'str'. Return a pointer to the last occurrence of 'c'.
    if (last != NULL) {
        return (char *)last;
    } else if (c == '\0') {
        return (char *)str; // Return a pointer to the null terminator for c == '\0'
    } else {
        return NULL;
    }
}


char *strstr(const char *haystack, const char *needle)
{
    // Iterate through the characters of 'haystack' until a null terminator ('\0') is encountered.
    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        // Iterate through the characters of 'n' and 'h' while they match.
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        // If 'n' reaches the end of 'needle', it means the substring 'needle' was found in 'haystack'.
        if (*n == '\0') {
            return (char *)haystack; // Substring found
        }

        haystack++;
    }

    return NULL; // Substring not found
}


char *strrstr(const char *haystack, const char *needle)
{
    const char *lastFound = NULL;

    // Iterate through the characters of 'haystack' until a null terminator ('\0') is encountered.
    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        // Iterate through the characters of 'n' and 'h' while they match.
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        // If 'n' reaches the end of 'needle', it means a substring 'needle' was found in 'haystack'.
        if (*n == '\0') {
            // Update last found position
            lastFound = haystack;
        }

        haystack++;
    }

    // Return the last found occurrence or NULL
    return (char *)lastFound;
}


void *memcpy(void *destination, const void *source, size_t num)
{
    // Cast the 'destination' pointer to a char pointer.
    char *dest = (char *)destination;
    // Cast the 'source' pointer to a const char pointer.
    const char *src = (const char *)source;

    // Iterate through 'num' bytes in the 'source' memory area and copy them to the 'destination' memory area.
    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

    return destination;
}


void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (dest < src) {
        // Copy forward from the beginning to the end
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        // Copy backward from the end to the beginning
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }

    return destination;
}


int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    // Cast 'ptr1' to an unsigned char pointer.
    const unsigned char *p1 = (const unsigned char *)ptr1;
    // Cast 'ptr2' to an unsigned char pointer.
    const unsigned char *p2 = (const unsigned char *)ptr2;

    // Iterate through 'num' bytes in the memory areas pointed to by 'p1' and 'p2'.
    for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
            // If a mismatch is found, return 1 if 'p1[i]' is greater, -1 if 'p2[i]' is greater.
            return (p1[i] > p2[i]) ? 1 : -1;
        }
    }

    return 0; // Both memory regions are equal
}


void *memset(void *source, int value, size_t num)
{
    // Cast 'source' to an unsigned char pointer.
    unsigned char *p = (unsigned char *)source;
    // Cast 'value' to an unsigned char.
    unsigned char v = (unsigned char)value;

    // Iterate through 'num' bytes in the memory area pointed to by 'p' and set them to 'v'.
    for (size_t i = 0; i < num; i++) {
        p[i] = v;
    }

    return source;
}

