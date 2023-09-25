#pragma once

#include <stddef.h>

#include "_code.h"
#include "_feedback.h"

/**
 * @brief Stores a pointer to a Code and optionally one to a corresponding
 * Feedback.
 */
typedef struct
{
    Code *code;
    Feedback *feedback;
} Guess;

/**
 * @brief Allocates a new Guess with the game_width from a GameState.
 *
 * @param size The number of elements in the arrays inside the guess.
 * @return Guess* A newly allocated Guess with empty values.
 */
Guess *allocate_guess(size_t size);

/**
 * @brief Frees a Guess from memory.
 *
 * @param guess A pointer to the Guess to be deleted.
 */
void free_guess(Guess *guess);

const char *guess_to_string(const Guess *guess, size_t size);