#pragma once

/**
 * @brief Defines different levels of correctness for when two Codes are
 * compared.
 */
typedef enum Feedback
{
    /**
     * A code has for any given Color no corresponding Color within another
     * Code.
     */
    INCORRECT = 0,
    /** A Color is present in both Codes but not the correct position. */
    ALMOST = 1,
    /** A Color is present in both Codes in the correct position. */
    CORRECT = 2
} Feedback;

/**
 * @brief Writes Feedback of `size` elements to buffer.
 *
 * @param buffer A string buffer with enough space to fit the result.
 * @param size The number of elements in the Feedback array.
 * @param feedback The Feedback array.
 * @return size_t The number of bytes written to buffer as done by snprintf().
 */
size_t sprintf_feedback(char *restrict buffer,
                        size_t size,
                        const Feedback feedback[size]);

/**
 * @brief Checks if two feedback arrays contain the same values, disregarding
 * order.
 *
 * @param size The number of Feedback values in both arrays.
 * @param lhs An array with `size` Feedback values.
 * @param rhs An array with `size` Feedback values.
 * @return true if both arrays contain the same elements;
 * @return false if not.
 */
bool feedback_equals(size_t size,
                     const Feedback lhs[size],
                     const Feedback rhs[size]);