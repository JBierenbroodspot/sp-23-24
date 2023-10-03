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

#include <limits.h>

#include "_string.h"

/**
 * @brief Gets the maximum amount of characters possible for all colors.
 */
#define COLOR_STR_MAX MAX_DECIMAL_SIZE(Color)

/**
 * @brief Gives and alias to the `unsigned int` type. Not 100% necessary but
 * makes code a bit more verbose.
 */
typedef unsigned int Color;

/**
 * @brief An alias for a pointer to a Color. This pointer is mainly meant to
 * point at arrays.
 */
typedef Color *Code;

/**
 * @brief Allocates memory for a new Code using the game_width from a GameState.
 *
 * @param The number of elements in the list.
 * @return Feedback* A newly allocated Code.
 */
Code *allocate_code(size_t size);

/**
 * @brief Frees a Code from memory.
 *
 * @param guess A pointer to the Code to be deleted.
 */
void free_code(Code *code);

/**
 * @brief Converts a Code object into a human-readable string.
 *
 * @param code A pointer to a Code to convert.
 * @param size The amount of elements in the Code and Feedback.
 * @return const char* A human-readable form of the Code.
 */
const char *code_to_string(const Code *code, size_t size);

/**
 * @brief Compares two `Code`s for position-based equality.
 *
 * Iterates over two `Code`s and compares each position with each other. Uses
 * the `game_state` to determine the length of the arrays.
 *
 * @param game_state The game state.
 * @param lhs Left-hand side `Code`.
 * @param rhs Right-hand side `Code`.
 * @return true if all values in the same position are equal;
 * @return false if not.
 */
bool code_equals(Code *const lhs, Code *const rhs, size_t size);
