#include "datatypes.h"

#include <stdio.h>
#include <string.h>

const char *feedback_state_to_string(FeedbackState fbs)
{
    switch (fbs)
    {
    case 0:
        return "INCORRECT";
    case 1:
        return "ALMOST";
    case 2:
        return "CORRECT";
    default:
        return "UNKNOWN";
    }
}

const char *feedback_to_string(const Feedback *feedback, size_t size)
{
    const size_t print_brackets_size = 4,    // 2 chars for the '{  }'
        print_commas_size = (size - 1) * 2,  // 2 chars for ', '
        print_fbs_size = size * FBS_STR_MAX, // the max chars for each fbs
        buffer_size = print_brackets_size +
                      print_commas_size +
                      print_fbs_size;
    // Clear buffer by using calloc
    char *buffer = calloc(buffer_size, sizeof(char));

    strcat(buffer, "{ ");
    size_t offset = strlen(buffer);

    for (size_t i = 0; i < size - 1; i++)
    {
        char fbs_str[FBS_STR_MAX + 2];
        int num_char = snprintf(fbs_str,
                                sizeof(fbs_str),
                                "%s, ",
                                feedback_state_to_string((*feedback)[i]));
        strncat(buffer + offset, fbs_str, num_char);
        offset += num_char;
    }

    char str_end[FBS_STR_MAX + 2];
    int str_end_size = snprintf(str_end,
                                sizeof(str_end),
                                "%s }",
                                feedback_state_to_string((*feedback)[size - 1]));
    strncat(buffer + offset, str_end, str_end_size);

    return buffer;
}