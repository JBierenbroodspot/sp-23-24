/**
 * @file datatypes.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains datatypes and functions to manipulate them.
 * @version 0.1
 * @date 2023-09-12
 */

#ifndef MASTERMIND_SRC_INCLUDE_DATATYPES_H_
#define MASTERMIND_SRC_INCLUDE_DATATYPES_H_

/**
 * @brief Shorthand for allocating memory on the heap.
 *
 * This exists because you cannot pass datatypes as arguments.
 *
 * source: ChatGPT.
 */
#define ALLOC_HEAP(dtype, size) (dtype *)_allocate_heap(sizeof(dtype), size)

#include <stdbool.h>
#include <stdlib.h>

/**
 * Gives and alias to the `unsigned int` type. Not 100% necessary but makes code
 * a bit more verbose.
 */
typedef unsigned int Colour;

/**
 * An alias for a pointer to a Colour. This pointer is mainly meant to point at
 * arrays.
 */
typedef Colour *Code;

/**
 * @brief Defines different levels of correctness for when two Codes are
 * compared.
 */
typedef enum
{
    /**
     * A code has for any given Colour no corresponding Colour within another
     * Code.
     */
    INCORRECT = 0,
    /** A Colour is present in both Codes but not the correct position. */
    ALMOST = 1,
    /** A Colour is present in both Codes in the correct position. */
    CORRECT = 2
} FeedbackState;

/**
 * An alias for a pointer to a FeedbackState. This pointer is mainly meant to
 * point at arrays.
 */
typedef FeedbackState *Feedback;

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
 * @brief Allocates memory on the heap.
 *
 * A catch-all function for allocating memory on the heap. If memory allocation
 * fails the program will exit with error code `EXIT_FAILURE`.
 *
 * Src: ChatGPT.
 *
 * @param type_size The size of the type being allocated.
 * @param type_amount If array: the amount of contiguous memory of size
 *      `type_size` should be allocated.
 * @return void* A pointer to the first memory address allocated.
 */
void *_allocate_heap(size_t type_size, size_t type_amount);

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

/**
 * @brief Allocates a new Guess with the game_width from a GameState.
 *
 * @param game_state The GameState that is going to own the guess.
 * @return Guess* A newly allocated Guess with empty values.
 */
Guess *allocate_guess(GameState *const game_state);
/**
 * @brief Frees a Guess from memory.
 *
 * @param guess A pointer to the Guess to be deleted.
 */
void free_guess(Guess *guess);

const char *guess_to_string(const Guess *guess);

/**
 * @brief Allocates memory for a new Feedback using the game_width from a
 * GameState.
 *
 * @param game_state The GameState that is going to own the Feedback.
 * @return Feedback* A newly allocated Feedback.
 */
Feedback *allocate_feedback(GameState *const game_state);
/**
 * @brief Frees a Feedback from memory.
 *
 * @param guess A pointer to the Feedback to be deleted.
 */
void free_feedback(Feedback *feedback);

const char *feedback_to_string(const Feedback *feedback);

/**
 * @brief Allocates memory for a new Code using the game_width from a GameState.
 *
 * @param game_state The GameState that is going to own the Code.
 * @return Feedback* A newly allocated Code.
 */
Code *allocate_code(GameState *const game_state);
/**
 * @brief Frees a Code from memory.
 *
 * @param guess A pointer to the Code to be deleted.
 */
void free_code(Code *code);

const char *feedback_state_to_string(FeedbackState fbs);

/**
 * @brief Compares two `Feedback`s for position-based equality.
 *
 * Iterates over two `Feedback`s and compares each position with eachother. Uses
 * the `game_state` to determine the length of the arrays.
 *
 * @param game_state The game state.
 * @param lhs Left-hand side `Feedback`.
 * @param rhs Right-hand side `Feedback`.
 * @return true if all values in the same position are equal;
 * @return false if not.
 */
bool feedback_equals(Feedback *const lhs, Feedback *const rhs, size_t size);
/**
 * @brief Compares two `Code`s for position-based equality.
 *
 * Iterates over two `Code`s and compares each position with eachother. Uses
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

#endif // MASTERMIND_SRC_INCLUDE_DATATYPES_H_