#include "datatypes.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

size_t sprintf_feedback(char *restrict buffer,
                        size_t size,
                        const Feedback feedback[size])
{
    static const size_t fb_print_len = 1 + 3;
    size_t offset = snprintf(buffer, 3, "{ ");

    for (ptrdiff_t i = 0; i < size - 1; i++)
        offset += snprintf(buffer + offset, fb_print_len, "%u, ", feedback[i]);

    offset += snprintf(buffer + offset,
                       fb_print_len,
                       "%u }",
                       feedback[size - 1]);

    return offset;
}

bool feedback_equals(size_t size,
                     const Feedback lhs[size],
                     const Feedback rhs[size])
{
    unsigned lhs_code = 0, rhs_code = 0;

    for (ptrdiff_t i = 0; i < size; i++)
    {
        lhs_code += (unsigned)pow(100, (double)lhs[i]);
        rhs_code += (unsigned)pow(100, (double)rhs[i]);
    }

    return lhs_code == rhs_code;
}