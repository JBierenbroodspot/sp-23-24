#include "include/datatypes.h"

Feedback* _allocate_feedback(const size_t code_length) {
    Feedback* feedback = malloc(code_length * sizeof(FeedbackState));
    
    if (feedback == NULL) exit(-1);

    return feedback;
}

Code* _allocate_code(const size_t code_length) {
    Code* code = malloc(code_length * sizeof(Colour));

    if (code == NULL) exit(-1);
    
    return code;
}

Guess* _allocate_guess(size_t code_length) {
    Guess* guess = malloc(sizeof(Guess));

    if (guess == NULL) exit(-1);

    guess->code = _allocate_code(code_length);
    guess->feedback = _allocate_feedback(code_length);

    return guess;
}