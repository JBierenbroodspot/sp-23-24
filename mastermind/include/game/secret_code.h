/**
 * @file secret_code.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains functions for creating and storing Mastermind secret codes.
 * @version 0.1
 * @date 2023-10-11
 *
 * TODO: Add license
 *
 */
#pragma once

#include "datatypes.h"

/**
 * @brief Writes a sequence of Code values to a buffer.
 *
 * @param code_size The number of elements to write to the buffer.
 * @param max_code The maximum allowed value for any Code value.
 * @param result A Code array buffer of size `code_size`.
 * @param allow_duplicate Whether to allow duplicate values or not.
 */
void generate_secret_code(size_t code_size,
                          Code max_code,
                          Code result[restrict code_size],
                          bool allow_duplicate);

static void _generate_secret_code_no_duplicate(size_t code_size,
                                               Code max_code,
                                               Code result[restrict code_size]);
