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
 * @brief Writes a code of `size` elements to buffer.
 *
 * @param buffer A string buffer with enough space to fit entire string.
 * @param size The number of Code elements in the code array.
 * @param code The code array.
 * @return size_t The number of bytes written to buffer as done by snprintf().
 */
size_t sprintf_code(char *restrict buffer, size_t size, const Code code[size]);

/**
 * @brief Checks if all values at the same index are equal.
 *
 * @param size Number of elements.
 * @param lhs An array of known size;
 * @param rhs An array of known size;
 * @return true if all values at the same index in both arrays are equal;
 * @return false if not.
 */
bool code_equals(size_t size,
                 const Code lhs[restrict size],
                 const Code rhs[restrict size]);

/**
 * @brief Checks if Code value is in Code array.
 *
 * @param size Size of the array.
 * @param val The value to look for in arr.
 * @param arr Code array of size `size`.
 * @return true if `val` is in `arr`;
 * @return false if not.
 */
bool code_is_in(size_t size, const Code val, const Code arr[restrict size]);

/**
 * @brief Checks whether an array of integers will validate as an array of code.
 *
 * @param size The number of elements in the array.
 * @param max_code The maximum value of a code.
 * @param duplicates Whether duplicates are allowed.
 * @param input An array of integers.
 * @return true `input` can be converted to `Code`;
 * @return false if not.
 */
bool int_is_code(size_t size,
                 unsigned max_code,
                 bool duplicates,
                 const int input[restrict size]);

/**
 * @brief Casts every element in an array of int into Code and puts them into an
 * array of code.
 *
 * Note: This function may cause undefined behaviour if the ints have not been
 * thoroughly checked for compatibility to be casted into Code (unsigned int).
 *
 * @param size The number of elements in both arrays.
 * @param source An array of integers.
 * @param dest An array of code.
 */
void int_to_code(size_t size,
                 int source[size],
                 Code dest[size]);
