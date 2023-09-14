#include "datatypes.h"

inline void* _allocate_heap(size_t type_size, size_t type_amount) {
    void* ptr = malloc(type_size * type_amount);

    if (ptr == NULL) exit(EXIT_FAILURE);

    return ptr;
}

Feedback* allocate_feedback(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(EXIT_FAILURE);

    return ALLOC_HEAP(Feedback, game_state->game_width);
}

void free_feedback(Feedback* feedback) {
    free(feedback);
}

Code* allocate_code(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(EXIT_FAILURE);

    return ALLOC_HEAP(Code, game_state->game_width);
}

void free_code(Code* code) {
    free(code);
}

Guess* allocate_guess(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(EXIT_FAILURE);

    Code* code = ALLOC_HEAP(Code, game_state->game_width);
    Feedback* feedback = ALLOC_HEAP(Feedback, game_state->game_width);
    Guess* guess = ALLOC_HEAP(Guess, 1);

    guess->code = code;
    guess->feedback = feedback;

    return guess;
}

void free_guess(Guess* guess) {
    free_code(guess->code);
    free_feedback(guess->feedback);

    free(guess);
}

GameState* allocate_game_state() {
    GameState* game_state = malloc(sizeof(GameState));

    if (game_state == NULL) exit(EXIT_FAILURE);

    return game_state;
}