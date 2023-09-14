#include "datatypes.h"

inline void* _allocate_heap(size_t type_size, size_t type_amount) {
    void* ptr = malloc(type_size * type_amount);

    if (ptr == NULL) exit(EXIT_FAILURE);

    return ptr;
}

Feedback* allocate_feedback(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(-1);

    return _allocate_feedback(game_state->game_width);
}

void free_feedback(Feedback* feedback) {
    free(feedback);
}

Code* allocate_code(GameState* const game_state) {
    if (game_state->game_width == NULL) exit(-1);

    return _allocate_code(game_state->game_width);
}

void free_code(Code* code) {
    free(code);
}

Guess* allocate_guess(GameState* const game_state) {
    if (game_state->game_width == NULL) abort();

    return _allocate_guess(game_state->game_width);
}

void free_guess(Guess* guess) {
    free_code(guess->code);
    free_feedback(guess->feedback);

    free(guess);
}