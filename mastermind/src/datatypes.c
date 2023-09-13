#include "datatypes.h"

Feedback* allocate_feedback(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(-1);

    return _allocate_feedback(game_state->game_width);
}

Feedback* _allocate_feedback(const size_t code_length) {
    Feedback* feedback = malloc(code_length * sizeof(FeedbackState));
    
    if (feedback == NULL) exit(-1);

    return feedback;
}

void free_feedback(Feedback* feedback) {
    free(feedback);
}

Code* allocate_code(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(-1);

    return _allocate_code(game_state->game_width);
}

Code* _allocate_code(const size_t code_length) {
    Code* code = malloc(code_length * sizeof(Colour));

    if (code == NULL) abort();
    
    return code;
}

void free_code(Code* code) {
    free(code);
}

Guess* allocate_guess(GameState* const game_state) {
    if (game_state->game_width == NULL) abort();

    return _allocate_guess(game_state->game_width);
}

Guess* _allocate_guess(size_t code_length) {
    Guess* guess = malloc(sizeof(Guess));

    if (guess == NULL) abort();

    guess->code = _allocate_code(code_length);
    guess->feedback = _allocate_feedback(code_length);

    return guess;
}

void free_guess(Guess* guess) {
    free_code(guess->code);
    free_feedback(guess->feedback);

    free(guess);
}