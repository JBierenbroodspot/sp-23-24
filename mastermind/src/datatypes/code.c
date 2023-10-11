#include "datatypes.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

size_t sprintf_code(char *restrict buffer, size_t size, const Code code[size])
{
    // The amount of characters required to print a code value, the extra 3 is
    // for the leading ', \0' after every code.
    static const size_t code_print_len = CODE_MAX_PRINT_LEN + 3;
    size_t offset = snprintf(buffer, 3, "{ ");

    for (ptrdiff_t i = 0; i < size - 1; i++)
        offset += snprintf(buffer + offset, code_print_len, "%u, ", code[i]);

    offset += snprintf(buffer + offset, code_print_len, "%u }", code[size - 1]);

    return offset;
}

bool code_equals(size_t size,
                 const Code lhs[restrict size],
                 const Code rhs[restrict size])
{
    for (ptrdiff_t i = 0; i < size; i++)
        if (lhs[i] != rhs[i])
            return false;

    return true;
}

bool code_is_in(size_t size, const Code val, const Code arr[restrict size])
{
    for (ptrdiff_t i = 0; i < size; i++)
        if (arr[i] == val)
            return true;

    return false;
}

bool int_is_code(size_t size,
                 unsigned max_code,
                 bool duplicates,
                 const int input[restrict size])
{
    ptrdiff_t i, j;
    for (i = 0; i < size; i++)
        if (!(0 <= input[i] <= max_code))
            return false;

    if (!duplicates)
        for (i = 0; i < size - 1; i++)
            for (j = i + 1; j < size; j++)
                if (i != j && input[i] == input[j])
                    return false;

    return true;
}

void int_to_code(size_t size,
                 int source[size],
                 Code dest[size])
{
    for (ptrdiff_t i = 0; i < size; i++)
        dest[i] = (Code)source[i];
}
