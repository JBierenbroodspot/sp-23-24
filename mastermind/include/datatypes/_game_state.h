#pragma once

#include <stddef.h>

#include "_code.h"
#include "_guess.h"

/**
 * @brief Stores the state of a game of Mastermind.
 */
typedef struct
{
    /** The width of the game, e.g. the length of Codes. */
    const size_t game_width;
    /** The amount of turns before the game is over. */
    const size_t game_length;
    bool in_progress;
    bool guesser_has_won;
    const Code *const secret_code;
    /** The guesses that have been submitted in the game. */
    Guess **const guesses;
} GameState;

/**
 * @brief Allocates memory for a new GameState.
 *
 * @param game_width The width of the game, e.g. the length of Codes.
 * @param game_length The amount of turns before the game is over.
 * @return GameState* A pointer to a newly allocated GameState.
 */
GameState *allocate_game_state();

/**
 * @brief Frees a GameState from memory.
 *
 * @param game_state A pointer to the GameState to be deleted.
 */
void free_game_state(GameState *game_state);
