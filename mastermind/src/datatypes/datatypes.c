#include "datatypes.h"

void *_allocate_heap(size_t type_size, size_t type_amount)
{
    void *ptr = malloc(type_size * type_amount);

    if (ptr == NULL)
        exit(EXIT_FAILURE);

    return ptr;
}
