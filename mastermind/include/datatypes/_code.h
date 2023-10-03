#pragma once

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

void code_subtract(
    const Code *const lhs,
    const Code *const rhs,
    Code *result_buffer,
    size_t size);