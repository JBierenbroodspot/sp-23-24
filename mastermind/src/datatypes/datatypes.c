#include "datatypes.h"

#include <stdio.h>

void *_allocate_heap(size_t type_size, size_t type_amount)
{
    void *ptr = calloc(type_size, type_amount);

    if (ptr == NULL)
    {
        fprintf(stderr, "Heap allocation failure.");
        exit(EXIT_FAILURE);
    }

    return ptr;
}