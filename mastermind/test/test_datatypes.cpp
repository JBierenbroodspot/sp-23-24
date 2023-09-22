/**
 * This fix is required to be able to use headers that have been compiled using
 * a plain C compile inside a C++ file.
 *
 * Source: https://stackoverflow.com/a/18879053/21104520
 */
extern "C"
{
#include "datatypes.h"
#include <stdlib.h>
}

#include <string>
#include <array>

#include <gtest/gtest.h>

const std::array<FeedbackState, 10> kFeedbackStates[3] = {
    {INCORRECT},
    {ALMOST, INCORRECT, INCORRECT, INCORRECT},
    {CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT,
     INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT}};

const std::array<Colour, 10> kColours[3] = {
    {0},
    {0, 0, 1, 5},
    {0, 0, 0, 1, 2, 3, 6, 1, 0, 1}};

const Guess kGuesses[3] = {
    {.code = (Code *)kColours[0][0], .feedback = (Feedback *)kFeedbackStates[0][0]},
    {.code = (Code *)kColours[1][0], .feedback = (Feedback *)kFeedbackStates[1][0]},
    {.code = (Code *)kColours[2][0], .feedback = (Feedback *)kFeedbackStates[2][0]}};

TEST(test_feedback_state_to_string, handles_happy_path)
{
    const size_t num_inputs = 4;
    const char *expected_values[num_inputs] = {
        "INCORRECT", "ALMOST", "CORRECT", "UNKNOWN"};

    for (auto i = 0; i < num_inputs; i++)
    {
        const char *result = feedback_state_to_string((FeedbackState)i),
                   *expected_value = expected_values[i];

        EXPECT_STREQ(result, expected_value);
    }
}

TEST(test_feedback_to_string, handles_happy_path)
{
    const size_t num_inputs = 3;
    const Feedback input_values[num_inputs] = {
        (Feedback)&kFeedbackStates[0][0],
        (Feedback)&kFeedbackStates[1][0],
        (Feedback)&kFeedbackStates[2][0]};

    const char *expected_values[num_inputs] = {
        "{ INCORRECT }",
        "{ ALMOST, INCORRECT, INCORRECT, INCORRECT }",
        "{ CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT }"};

    for (size_t i = 0; i < num_inputs; i++)
    {
        const char *result = feedback_to_string(&input_values[i], kFeedbackStates[i].size()),
                   *expected = expected_values[i];

        EXPECT_STREQ(result, expected);
    }
}

TEST(test_code_to_string, handles_happy_path)
{
    const size_t num_inputs = 3;
    const Code input_values[num_inputs] = {
        (Code)&kColours[0][0],
        (Code)&kColours[1][0],
        (Code)&kColours[2][0]};

    const char *expected_values[num_inputs] = {
        "{ 0 }",
        "{ 0, 0, 1, 5 }",
        "{ 0, 0, 0, 1, 2, 3, 6, 1, 0, 1 }"};

    for (size_t i = 0; i < num_inputs; i++)
    {
        const char *result = code_to_string(&input_values[i], kFeedbackStates[i].size()),
                   *expected = expected_values[i];

        EXPECT_STREQ(result, expected);
    }
}

TEST(test_guess_to_string, hanndles_happy_path)
{
    const size_t num_inputs = 3;
    const Guess input_values[num_inputs] = {
        kGuesses[0],
        kGuesses[1],
        kGuesses[2]};

    const char *expected_values[num_inputs] = {
        "{ code = { 0 }, feedback = { INCORRECT } }",
        "{ code = { 0, 0, 1, 5 }, feedback = { ALMOST, INCORRECT, INCORRECT, INCORRECT } }",
        "{ code = { 0, 0, 0, 1, 2, 3, 6, 1, 0, 1 }, feedback = { CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT } }"};

    for (size_t i = 0; i < num_inputs; i++)
    {
        const char *result = guess_to_string(&input_values[i], kFeedbackStates[i].size()),
                   *expected = expected_values[i];

        EXPECT_STREQ(result, expected);
    }
}

TEST(test_guess_to_string, handles_guess_without_feedback)
{
    Guess input_value = kGuesses[1];
    input_value.feedback = nullptr;

    const char *result = guess_to_string(&input_value, 4),
               *expected = "{ code = { 0, 0, 1, 5 } }";

    EXPECT_STREQ(result, expected);
}

TEST(test_feedback_equals, handles_happy_path)
{
    FeedbackState compare[3][10] = {
        {INCORRECT},
        {CORRECT, ALMOST, INCORRECT, INCORRECT},
        {CORRECT, CORRECT, ALMOST, ALMOST, INCORRECT,
         INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT}};

    const std::pair<Feedback, bool> compare_with[6] = {
        std::make_pair<FeedbackState[1], bool>(
            {INCORRECT}, true),
        std::make_pair<FeedbackState[1], bool>(
            {CORRECT}, false),
        std::make_pair<FeedbackState[4], bool>(
            {CORRECT, ALMOST, INCORRECT, INCORRECT}, true),
        std::make_pair<FeedbackState[4], bool>(
            {CORRECT, INCORRECT, INCORRECT, INCORRECT}, false),
        std::make_pair<FeedbackState[10], bool>(
            {CORRECT, CORRECT, ALMOST, ALMOST, INCORRECT,
             INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT},
            true),
        std::make_pair<FeedbackState[10], bool>(
            {CORRECT, CORRECT, ALMOST, INCORRECT, INCORRECT,
             INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT},
            false)};

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = i * 2; j < i * 2 + 2; j++)
        {
            size_t compare_size = sizeof(compare_with[j].first);
            Feedback input_one = compare[i];
            Feedback input_two = compare_with[j].first;

            bool result = feedback_equals(
                &input_one,
                &input_two,
                compare_size);
            EXPECT_EQ(result, compare_with[j].second) << i << ", " << j;
        }
    }
}

// TEST(test__allocate_feedback, handles_happy_values)
// {
//     size_t input_values[3] = {1, 5, 10};
//     size_t feedback_size = sizeof(FeedbackState);

//     for (auto &input_value : input_values)
//     {
//         Feedback *feedback = allocate_feedback(input_value);

//         size_t result = sizeof(*feedback);
//         size_t expected_value = input_value * feedback_size;

//         EXPECT_EQ(result, expected_value)
//             << "Allocated size " << result
//             << " did not match expected size " << expected_value
//             << ".";

//         free(feedback);
//     }
// }

// TEST(test__allocate_code, handles_happy_values)
// {
//     size_t input_values[3] = {1, 5, 10};
//     size_t colour_size = sizeof(Colour);

//     for (const auto input_value : input_values)
//     {
//         Code *code = _allocate_code(input_value);

//         size_t result = sizeof(*code);
//         size_t expected_value = input_value * colour_size;

//         EXPECT_EQ(result, expected_value)
//             << "Allocated size " << result
//             << " did not match expected size " << expected_value
//             << ".";

//         free(code);
//     }
// }

// TEST(test__allocate_guess, handles_happy_values)
// {
//     size_t input_values[3] = {1, 5, 10};

//     for (auto &input_value : input_values)
//     {
//         Colour mock_code[input_value] = {};
//         FeedbackState mock_feedback[input_value] = {};

//         Guess *guess = _allocate_guess(input_value);

//         size_t result = sizeof(*guess);
//         size_t expected_value = sizeof(*mock_code) + sizeof(*mock_feedback);

//         EXPECT_EQ(result, expected_value)
//             << "Allocated size " << result
//             << " did not match expected size " << expected_value
//             << ".";

//         free(guess);
//     }
// }