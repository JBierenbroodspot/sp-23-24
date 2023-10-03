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

TEST(test_print_sl, handles_happy_path)
{
    const StringedList sl1 = {.value = " }", .next = NULL};
    const StringedList sl2 = {.value = "RED", .next = &sl1};
    const StringedList sl3 = {.value = "BLUE, ", .next = &sl2};
    const StringedList sl4 = {.value = "{ ", .next = &sl3};
    const std::string expected = "{ BLUE, RED }";

    testing::internal::CaptureStdout();
    print_sl(&sl4);
    const std::string result = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, result);
}

TEST(test_code_to_string, handles_happy_path)
{
    Color c1 = 1,
          c2[4] = {1, 1, 3, 4},
          c3[10] = {1, 3, 4, 1, 1, 5, 10, 1, 1, 0};

    const Code input1 = &c1,
               input2 = &c2[0],
               input3 = &c3[0];

    const char *expected1 = "{ 1 }",
               *expected2 = "{ 1, 1, 3, 4 }",
               *expected3 = "{ 1, 3, 4, 1, 1, 5, 10, 1, 1, 0 }";

    const char *result1 = code_to_string(&input1, 1),
               *result2 = code_to_string(&input2, 4),
               *result3 = code_to_string(&input3, 10);

    EXPECT_STREQ(expected1, result1);
    EXPECT_STREQ(expected2, result2);
    EXPECT_STREQ(expected3, result3);
}

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
    FeedbackState fbs1 = INCORRECT,
                  fbs2[4] = {INCORRECT, INCORRECT, INCORRECT, INCORRECT},
                  fbs3[10] = {
                      CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT,
                      INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT};

    const Feedback input1 = &fbs1,
                   input2 = &fbs2[0],
                   input3 = &fbs3[0];

    const char *expected1 = "{ INCORRECT }",
               *expected2 = "{ INCORRECT, INCORRECT, INCORRECT, INCORRECT }",
               *expected3 = "{ CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT }";

    const char *result1 = feedback_to_string(&input1, 1),
               *result2 = feedback_to_string(&input2, 4),
               *result3 = feedback_to_string(&input3, 10);

    EXPECT_STREQ(expected1, result1);
    EXPECT_STREQ(expected2, result2);
    EXPECT_STREQ(expected3, result3);
}

TEST(test_guess_to_string, handles_happy_path)
{
    Color c1 = 1,
          c2[4] = {1, 1, 3, 4},
          c3[10] = {1, 3, 4, 1, 1, 5, 10, 1, 1, 0};

    FeedbackState fbs1 = INCORRECT,
                  fbs2[4] = {INCORRECT, INCORRECT, INCORRECT, INCORRECT},
                  fbs3[10] = {
                      CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT,
                      INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT};

    Code code1 = &c1,
         code2 = &c2[0],
         code3 = &c3[0];

    Feedback feedback1 = &fbs1,
             feedback2 = &fbs2[0],
             feedback3 = &fbs3[0];

    const Guess input1 = {.code = &code1, .feedback = &feedback1},
                input2 = {.code = &code2, .feedback = &feedback2},
                input3 = {.code = &code3, .feedback = &feedback3};

    const char *expected1 = "{ code = { 1 }, feedback = { INCORRECT } }",
               *expected2 = "{ code = { 1, 1, 3, 4 }, feedback = { INCORRECT, INCORRECT, INCORRECT, INCORRECT } }",
               *expected3 = "{ code = { 1, 3, 4, 1, 1, 5, 10, 1, 1, 0 }, feedback = { CORRECT, ALMOST, ALMOST, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT, INCORRECT } }";

    const char *result1 = guess_to_string(&input1, 1),
               *result2 = guess_to_string(&input2, 4),
               *result3 = guess_to_string(&input3, 10);

    EXPECT_STREQ(expected1, result1);
    EXPECT_STREQ(expected2, result2);
    EXPECT_STREQ(expected3, result3);
}

TEST(test_guess_to_string, handles_empty_feedback)
{
    Color color[4] = {1, 1, 3, 4};
    Code code = &color[0];
    const Guess input = {.code = &code};
    const char *expected = "{ code = { 1, 1, 3, 4 }, feedback = {} }",
               *result = guess_to_string(&input, 4);

    EXPECT_STREQ(expected, result);
}