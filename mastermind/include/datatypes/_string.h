/**
 * @file _string.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains definitions and functions to manipulate strings.
 * @version 0.1
 * @date 2023-10-02
 *
 * TODO: Add license
 *
 */
#pragma once

/**
 * @brief A linked list for strings.
 */
typedef struct StringedList
{
    const char *value;
    const struct StringedList *next;
} StringedList;

/**
 * @brief Prints out the values of `StringedList`s until `next` points to
 * `NULL`.
 *
 * @param sl A `StringedList` to print.
 */
void print_sl(const StringedList *sl);