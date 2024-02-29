/*!
 * Author: James Carppe
 * Date: 29/02/2024
 * Version: 1.0.0
 *
 * @brief Defines & implements types to simplify file input & output.
 */

#include <stdio.h>
#include "files.h"

int get_lines_in_file(FILE* target) {
    // Count the lines
    int lines = 0;

    int current_character = '';
    while (current_character != EOF) {
        // Read the next character in the file
        current_character = fgetc(target);

        // If the character is a new line charcter, add 1 to lines
        if (current_character == '\n') lines++;
    }

    // Return lines
    return lines;
}

struct ReadOnly_File open_readonly_file(const char* file_path) {
    // Open the file
    FILE *file = fopen(file_path, "r");

    // Create result template
    ReadOnly_File result = {};

    // Check open success
    if (file == NULL) {
        // File didnt open

        // Return a blank struct
        result.pointer = NULL;
        result.lines   = 0;

        return result;
    }

    // File opened successfully

    // Get the lines in the file
    const int lines = get_lines_in_file(file);

    // Return a completed struct
    result.pointer = file;
    result.lines   = lines;

    return result;
}

struct ReadWrite_File open_readwrite_file(const char* file_path) {
    // Open the file
    FILE *file = fopen(file_path, "r+");

    // Create result template
    ReadWrite_File result = {};

    // Check open success
    if (file == NULL) {
        // File didnt open

        // Return a blank struct
        result.pointer = NULL;
        result.lines   = 0;

        return result;
    }

    // File opened successfully

    // Get the lines in the file
    const int lines = get_lines_in_file(file);

    // Return a completed struct
    result.pointer = file;
    result.lines   = lines;

    return result;
}
