#include "datatypes.h"

#include <gtest/gtest.h>

#include <stdlib.h>

TEST(test__allocate_feedback, handles_happy_values) {
    size_t input_values[3] = {1, 5, 10};
    size_t feedback_size = sizeof(Feedback);

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

    for (auto &input_value : input_values) {
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