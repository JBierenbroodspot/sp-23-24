/**
 * @file _code.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains definitions and functions for manipulating Mastermind codes.
 * @version 0.1
 * @date 2023-10-04
 *
 * TODO: Add license
 */
#pragma once

#include <stddef.h>

/**
 * @brief Denotes a combination of different values used as a code in the game
 * Mastermind.
 */
typedef unsigned int Code;

/**
 * @brief Generates a string representation of a Code.
 *
 * @param size Number of elements.
 * @param code The Code to turn into a string;
 * @return const char* A string representation of the Code.
 */
const char *code_to_string(ptrdiff_t size, const Code code[size]);

/**
 * @brief Checks if all values at the same index are equal.
 *
 * @param size Number of elements.
 * @param lhs An array of known size;
 * @param rhs An array of known size;
 * @return true if all values at the same index in both arrays are equal;
 * @return false if not.
 */
bool code_equals(ptrdiff_t size, const Code lhs[size], const Code rhs[size]);
