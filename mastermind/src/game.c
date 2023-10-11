#include "game.h"

#include <string.h>

union int_or_code
{
    int *int_arr;
    Code *code_arr;
};

bool create_code_record(size_t game_width,
                        unsigned max_value,
                        bool duplicates_allowed,
                        int input_arr[game_width],
                        Code code_record[restrict game_width])
{
    if (!int_is_code(game_width, max_value, duplicates_allowed, input_arr))
        return false;

    // Assign input_arr to a union so that input_arr can be recognized as a
    // Code array once it has been converted, without allocating new memory.
    union int_or_code u_input = {.int_arr = input_arr};

    // This function takes int values, casts them into Code and puts them into
    // the destination array but both arrays passed as arguments here are the
    // same array (same address) so each value is being taken from an array of
    // type A, cast into type B and then put back into an array which the
    // compiler thinks is an array of type B but in actuality is the same
    // array.
    int_to_code(game_width, input_arr, u_input.code_arr);

    // Eventually the code array is being stored in a record. Instead of using
    // u_input.code_arr, input_arr could be used as well but the compiler will
    // warn us about the wrong type.
    store_code(game_width, u_input.code_arr, code_record);

    return true;
}

inline void store_code(size_t size,
                       const Code source[restrict size],
                       Code dest[restrict size])
{
    memcpy(dest, source, size * sizeof(Code));
}