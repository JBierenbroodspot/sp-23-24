#ifndef MASTERMIND_DATATYPES_H_
#define MASTERMIND_DATATYPES_H_

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
typedef Colour* Code;
/**
 * An alias for a pointer to a FeedbackState. This pointer is mainly meant to
 * point at arrays. 
 */
typedef FeedbackState* Feedback;

/**
 * @brief Defines different levels of correctness for when two Codes are 
 * compared. 
 */
typedef enum {
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
 * @brief Stores a pointer to a Code and optionally one to a corresponding 
 * Feedback.
 */
typedef struct {
    Code* code;
    Feedback* feedback;
} Guess;

/**
 * @brief Stores the state of a game of Mastermind. 
 */
typedef struct {
    /** The width of the game, e.g. the length of Codes. */
    const size_t game_width;
    /** The amount of turns before the game is over. */
    const size_t game_length;
    bool in_progress;
    bool guesser_has_won;
    const Code* const secret_code;
    /** The guesses that have been submitted in the game. */
    Guess** const guesses;
} GameState;

#endif // MASTERMIND_DATATYPES_H_