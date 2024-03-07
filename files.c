/*!
* @Author James Carppe
 * @Created 29/02/2024
 *
 * @Version 2.0.0
 * @LastUpdate 7/03/2024
 *
 * @brief Provides file opening functions for the C programming language.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "files.h"

// Counts the lines in a file
int get_file_line_count(FILE *self) {
    // Initialise a variable to hold the lines
    int lines = 0;

    // Loop over the file
    int current_character = ' ';
    while (current_character != EOF) {
        // Read the next character in the file
        current_character = fgetc(self);

        // If the character is a new line charcter, add 1 to lines
        if (current_character == '\n') lines++;
    }

    // Return lines
    return lines;
}

// Opens a simple file
struct File open_file(const char *file_path, const char *file_mode) {
    // Open the file and set it's structs values
    File file = {
        .pointer = fopen(file_path, file_mode),
        .mode = file_mode,
        .closed = false
    };

    // Check if the file pointer is NULL
    if (file.pointer == NULL) {
        file.closed = true;
    }

    // Return the file
    return file;
}

// Opens a complex file
struct Complex_File open_complex_file(const char *file_path, const char *file_mode) {
    // Open the file
    Complex_File complex_file = {
        .file = open_file(file_path, file_mode)
    };

    // Count the lines in the file
    FILE *copy_reference = (FILE *) complex_file.file.pointer;
    complex_file.lines = get_file_line_count(copy_reference);

    // Return the complex file
    return complex_file;
}

// Closes a simple file
void close_file(File *self) {
    // Close the file
    fclose((FILE *) self->pointer);

    // Set the closed attribute to true
    self->closed = true;

    // Set the pointer to be NULL
    self->pointer = NULL;
}

// Closes a complex file
void close_complex_file(Complex_File *self) {
    // Close the file
    fclose((FILE *) self->file.pointer);

    // Set the closed attribute to true
    self->file.closed = true;

    // Set lines to 0
    self->lines = 0;

    // Set the pointer to be NULL
    self->file.pointer = NULL;
}
