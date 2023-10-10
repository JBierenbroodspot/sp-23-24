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

bool code_equals(size_t size, const Code lhs[size], const Code rhs[size])
{
    for (ptrdiff_t i = 0; i < size; i++)
        if (lhs[i] != rhs[i])
            return false;

    return true;
}
