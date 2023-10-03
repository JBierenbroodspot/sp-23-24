#include "datatypes.h"

const char *feedback_state_to_string(FeedbackState fbs)
{
    switch (fbs)
    {
    case 0:
        return "INCORRECT";
    case 1:
        return "ALMOST";
    case 2:
        return "CORRECT";
    default:
        return "UNKNOWN";
    }
}