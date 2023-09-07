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

/**
 * @brief Allocates memory for a new GameState.
 * 
 * @param game_width The width of the game, e.g. the length of Codes.
 * @param game_length The amount of turns before the game is over.
 * @return GameState* A pointer to a newly allocated GameState.
 */
GameState* allocate_game_state(
    size_t const game_width, 
    size_t const game_length
);
/**
 * @brief Frees a GameState from memory.
 * 
 * @param game_state A pointer to the GameState to be deleted.
 */
void free_game_state(GameState* game_state);

/**
 * @brief Allocates a new Guess with the game_width from a GameState.
 * 
 * @param game_state The GameState that is going to own the guess.
 * @return Guess* A newly allocated Guess with empty values.
 */
Guess* allocate_guess(GameState* const game_state);
static Guess* _allocate_guess(const size_t code_length);
/**
 * @brief Frees a Guess from memory.
 * 
 * @param guess A pointer to the Guess to be deleted.
 */
void free_guess(Guess* guess);

/**
 * @brief Allocates memory for a new Feedback using the game_width from a 
 * GameState.
 * 
 * @param game_state The GameState that is going to own the Feedback.
 * @return Feedback* A newly allocated Feedback.
 */
Feedback* allocate_feedback(GameState* const game_state);
static Feedback* _allocate_feedback(const size_t code_length);
/**
 * @brief Frees a Feedback from memory.
 * 
 * @param guess A pointer to the Feedback to be deleted.
 */
void free_feedback(Feedback* feedback);

/**
 * @brief Allocates memory for a new Code using the game_width from a GameState.
 * 
 * @param game_state The GameState that is going to own the Code.
 * @return Feedback* A newly allocated Code.
 */
Code* allocate_code(GameState* const game_state);
static Code* _allocate_code(const size_t code_length);
/**
 * @brief Frees a Code from memory.
 * 
 * @param guess A pointer to the Code to be deleted.
 */
void free_code(Code* code);

#endif // MASTERMIND_DATATYPES_H_