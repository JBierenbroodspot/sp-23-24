#pragma once

/**
 * @brief Max amount of chars required for any FeedbackState.
 */
#define FBS_STR_MAX (size_t)sizeof("INCORRECT")

/**
 * @brief Defines different levels of correctness for when two Codes are
 * compared.
 */
typedef enum FeedbackState
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
} FeedbackState;

/**
 * An alias for a pointer to a FeedbackState. This pointer is mainly meant to
 * point at arrays.
 */
typedef FeedbackState *Feedback;

/**
 * @brief Converts a FeedbackState to its human-readable form.
 *
 * @param fbs a FeedbackState.
 * @return const char* A human-readable representation of the FeedbackState.
 */
const char *feedback_state_to_string(FeedbackState fbs);

/**
 * @brief Allocates memory for a new Feedback.
 *
 * @param size The number of elements in the allocated list.
 * @return Feedback* A newly allocated Feedback.
 */
inline Feedback *allocate_feedback(size_t size)
{
    return ALLOC_HEAP(Feedback, size);
}

/**
 * @brief Frees a Feedback from memory.
 *
 * @param feedback A pointer to the Feedback to be deleted.
 */
inline void free_feedback(Feedback *feedback) { free(feedback); }

const char *feedback_to_string(const Feedback *feedback, size_t size);

/**
 * @brief Compares two `Feedback`s for position-based equality.
 *
 * Iterates over two `Feedback`s and compares each position with each other.
 *
 * @param lhs Left-hand side `Feedback`.
 * @param rhs Right-hand side `Feedback`.
 * @return true if all values in the same position are equal;
 * @return false if not.
 */
bool feedback_equals(const Feedback *lhs, const Feedback *rhs, size_t size);