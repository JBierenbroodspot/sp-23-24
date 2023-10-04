/**
 * @file datatypes.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains datatypes aMASTERMIND_INCLUDE_CODE_H_nd functions to manipulate them.
 * @version 0.1
 * @date 2023-09-12
 */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Shorthand for allocating memory on the heap. This exists because you
 * cannot pass datatypes as arguments.
 *
 * @internal
 * Written using OpenAI's ChatGPT model version 3.5
 * @endinternal
 */
#define ALLOC_HEAP(dtype, size) (dtype *)_allocate_heap(sizeof(dtype), size)

/**
 * @brief Calculates how many characters are needed for printing a decimal.
 *
 * @internal
 * Answer taken from StackOverflow (https://stackoverflow.com/a/44024876/21104520),
 * licensed under CC BY-SA 3.0. No modifications have been made.
 * @endinternal
 */
#define MAX_DECIMAL_SIZE(x) ((size_t)(CHAR_BIT * sizeof(x) * 302 / 1000) + 1)

/**
 * @brief Allocates memory on the heap.
 *
 * A catch-all function for allocating memory on the heap. If memory allocation
 * fails the program will exit with error code `EXIT_FAILURE`.
 *
 * @param type_size The size of the type being allocated.
 * @param type_amount If array: the amount of contiguous memory of size
 *      `type_size` should be allocated.
 * @return void* A pointer to the first memory address allocated.
 *
 * @internal
 * Written using OpenAI's ChatGPT model version 3.5
 * @endinternal
 */
void *_allocate_heap(size_t type_size, size_t type_amount);

// Include these after all definitions so that the code inside can use the
// macros defined above.
#include "_code.h"
#include "_feedback.h"
#include "_game_state.h"
#include "_guess.h"
#include "_string.h"
