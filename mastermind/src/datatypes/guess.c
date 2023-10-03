#include "datatypes.h"

#include <stdio.h>
#include <string.h>

const char *guess_to_string(const Guess *guess, size_t size)
{
    const char *code = code_to_string(guess->code, size);
    const char *feedback = (guess->feedback != NULL)
                               ? feedback_to_string(guess->feedback, size)
                               : "{}";

    const size_t print_overhead_size = sizeof("{ code = , feedback =  }"),
                 result_buffer_size =
                     strlen(code) + strlen(feedback) + print_overhead_size;

    char *result = calloc(result_buffer_size, sizeof(char));
    snprintf(result,
             result_buffer_size,
             "{ code = %s, feedback = %s }",
             code,
             feedback);
    return result;
}