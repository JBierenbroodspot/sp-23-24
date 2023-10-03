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