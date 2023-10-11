#include "secret_code.h"

void generate_secret_code(size_t code_size,
                          Code max_code,
                          Code result[restrict code_size],
                          bool allow_repeat)
{
    if (!allow_repeat)
        return _generate_secret_code_no_duplicate(code_size, max_code, result);

    for (ptrdiff_t i = 0; i < code_size; i++)
        result[i] = (Code)rand() % (max_code + 1);
}

static void _generate_secret_code_no_duplicate(size_t code_size,
                                               Code max_code,
                                               Code result[restrict code_size])
{
    for (ptrdiff_t i = 0; i < code_size;)
    {
        Code rand_code = rand() % (max_code + 1);

        if (code_is_in(code_size, rand_code, result))
            continue;

        result[i] = rand_code;
        i++;
    }
}