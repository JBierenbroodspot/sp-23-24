#include "datatypes.h"

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

Code *allocate_code(size_t size) { return ALLOC_HEAP(Code, size); }

void free_code(Code *code) { free(code); }

const char *code_to_string(const Code *code, size_t size)
{
    const size_t print_brackets_size = 4,        // 2 chars for the '{  }'
        print_commas_size = (size - 1) * 2,      // 2 chars for ', '
        print_color_size = size * COLOR_STR_MAX, // the max chars for each color
        buffer_size = print_brackets_size +
                      print_commas_size +
                      print_color_size;
    // Clear buffer by using calloc
    char *buffer = calloc(buffer_size, sizeof(char));

    strcat(buffer, "{ ");
    size_t offset = strlen(buffer);

    for (size_t i = 0; i < size - 1; i++)
    {
        char color_str[COLOR_STR_MAX + 2];
        int num_char = snprintf(color_str,
                                sizeof(color_str),
                                "%u, ",
                                (*code)[i]);
        strncat(buffer + offset, color_str, num_char);
        offset += num_char;
    }

    char str_end[COLOR_STR_MAX + 2];
    snprintf(str_end, sizeof(str_end), "%u }", (*code)[size - 1]);
    strncat(buffer + offset, str_end, sizeof(str_end));

    return buffer;
}

bool code_equals(const Code *lhs, const Code *rhs, size_t size)
{
    for (size_t i = 0; i < size; i++)
        if ((*lhs)[i] != (*rhs)[i])
            return false;

    return true;
}
