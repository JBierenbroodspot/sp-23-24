/**
 * @file game.h
 * @author Jimmy Bierenbroodspot (jim12.brood@gmail.com)
 * @brief Contains functions and definitions to run an entire game of
 * Mastermind. Note: There's no interaction with IO in this unit.
 * @version 0.1
 * @date 2023-10-11
 *
 * TODO: Add license
 *
 */
#pragma once

#include "datatypes.h"

/**
 * @brief Takes an array of integers, validates it, converts it to a code array
 * and stores it into a code array record.
 *
 * @param game_width The number of elements in all arrays.
 * @param max_value The maximum value of each Code.
 * @param duplicates_allowed Whether a code array may contain duplicate values.
 * @param input_arr An array of integers.
 * @param code_record A pointer to a code array.
 * @return true if the input validated as a code array and copied successfully;
 * @return false if the input failed to validate as a code array.
 */
bool init_secret_code(size_t game_width,
                      unsigned max_value,
                      bool duplicates_allowed,
                      int input_arr[game_width],
                      Code code_record[restrict game_width]);

/**
 * @brief Copies a code array into another.
 *
 * @param size The number of elements in both arrays.
 * @param source A code array.
 * @param dest A code array.
 */
void store_code(size_t size,
                const Code source[restrict size],
                Code dest[restrict size]);
