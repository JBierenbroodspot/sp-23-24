/**
 * This fix is required to be able to use headers that have been compiled using
 * a plain C compile inside a C++ file.
 * 
 * Source: https://stackoverflow.com/a/18879053/21104520
 */
extern "C" {
    #include "datatypes.h"
    #include <stdlib.h>
}

#include <gtest/gtest.h>

TEST(test__allocate_feedback, handles_happy_values) {
    size_t input_values[3] = {1, 5, 10};
    size_t feedback_size = sizeof(FeedbackState);

    for (auto &input_value : input_values) {
        Feedback* feedback = _allocate_feedback(input_value);
        
        size_t result = sizeof(*feedback);
        size_t expected_value = input_value * feedback_size;

        EXPECT_EQ(result, expected_value)
            << "Allocated size " << result 
            << " did not match expected size " << expected_value 
            << ".";

        free(feedback);
    }
}

TEST(test__allocate_code, handles_happy_values) {
    size_t input_values[3] = {1, 5, 10};
    size_t colour_size = sizeof(Colour);

    for (const auto input_value : input_values) {
        Code* code = _allocate_code(input_value);

        size_t result = sizeof(*code);
        size_t expected_value = input_value * colour_size;

        EXPECT_EQ(result, expected_value) 
            << "Allocated size " << result 
            << " did not match expected size " << expected_value 
            << ".";

        free(code);
    }
}

TEST(test__allocate_guess, handles_happy_values) {
    size_t input_values[3] = {1, 5, 10};

    for (auto &input_value : input_values) {
        Colour mock_code[input_value] = {};
        FeedbackState mock_feedback[input_value] = {};

        Guess* guess = _allocate_guess(input_value);

        size_t result = sizeof(*guess);
        size_t expected_value = sizeof(*mock_code) + sizeof(*mock_feedback);

        EXPECT_EQ(result, expected_value) 
            << "Allocated size " << result 
            << " did not match expected size " << expected_value 
            << ".";

        free(guess);
    }
}