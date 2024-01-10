// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

// Allocate memory block of 'size' bytes using mmap.
void *malloc(size_t size)
{
    // Allocate memory using mmap
    void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED) {
        return NULL;  // Allocation failed
    }

    // Add allocated memory to the mem_list
    if (mem_list_add(mem, size) == -1) {
        // Remove from mmap if adding to mem_list failed
        munmap(mem, size);
        return NULL;
    }

    return mem;
}

// Allocate memory for an array of 'nmemb' elements, each of 'size' bytes, and initialize to zero.
void *calloc(size_t nmemb, size_t size)
{
    // Calculate the total size required for the array.
    size_t total_size = nmemb * size;

    // Allocate memory using 'malloc' for the total size.
    void *mem = malloc(total_size);

    if (mem != NULL) {
        // Initialize the allocated memory to zero using 'memset'.
        memset(mem, 0, total_size);
    }

    return mem;
}

// Deallocate the memory block pointed to by 'ptr'.
void free(void *ptr)
{
    if (ptr == NULL) {
        // If 'ptr' is NULL, there's nothing to free, so return without any action.
        return;
    }

    // Find the memory block in the memory list using 'mem_list_find'.
    struct mem_list *item = mem_list_find(ptr);

    if (item == NULL) {
        // The provided pointer was not found in the memory list
        return; // Do nothing and return
    }

    // Unmap the memory region
    munmap(item->start, item->len);

    // Remove the item from the memory list
    mem_list_del(ptr);
}

// Resize the memory block pointed to by 'ptr' to 'size' bytes.
void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        // If ptr is NULL, this is equivalent to malloc(size)
        return malloc(size);
    }

    struct mem_list *item = mem_list_find(ptr);

    if (item == NULL) {
        // If ptr is not found in the mem_list, return NULL
        return NULL;
    }

    if (size == 0) {
        // If size is 0, this is equivalent to free(ptr)
        free(ptr);
        return NULL;
    }

    // Try to extend or shrink the existing memory block
    void *new_ptr = mremap(ptr, item->len, size, MREMAP_MAYMOVE);

    if (new_ptr == MAP_FAILED) {
        // mremap failed, try allocating a new block and copying the data
        new_ptr = malloc(size);

        if (new_ptr == NULL) {
            // Allocation failed
            return NULL;
        }

        // Copy the data from the old block to the new block
        memcpy(new_ptr, ptr, item->len);

        // Free the old block
        free(ptr);
    }

    return new_ptr;
}

// Resize the memory block pointed to by 'ptr' to accommodate an array of 'nmemb' elements, each of 'size' bytes.
void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    // Calculate the new size
    size_t new_size = nmemb * size;

    // Call realloc with the new size
    return realloc(ptr, new_size);
}
