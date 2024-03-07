/*!
 * @Author James Carppe
 * @Created 29/02/2024
 *
 * @Version 2.0.0
 * @LastUpdate 7/03/2024
 *
 * @brief Provides file opening functions for the C programming language.
 */

#ifndef FILES_H
#define FILES_H

#endif //FILES_H

#define FILE_MODE_CHAR_LENGTH 3

/*!
 * @brief Defines the fundamental file type that will have functionality expanded upon.
 *
 * @field pointer   const FILE*   Base pointer for an opened file
 * @field mode      const char*   Mode that the file was opened in (r, r+, w, w+, etc)
 * @field closed    bool          A way to indicate that the file pointer is no longer valid
 */
typedef struct File {
    const FILE *pointer;
    const char *mode;
    bool closed;
} File;

/*!
 * @brief Expands upon the base File structure to add additional features.
 *
 * @field file      File    File struct, see File documentaion for more information.
 * @field lines     int     Represents the line count of the file.
 */
typedef struct Complex_File {
    File file;
    int lines;
} Complex_File;

/*!
 * @brief Opens a simple file.
 *
 * @param file_path string representing the path to the target file.
 * @param file_mode string representing which mode to open the file.
 * @return a File struct which contains a pointer to the opened file.
 */
struct File open_file(const char *file_path, const char *file_mode);

/*!
 * @brief Opens a complex file.
 *
 * @param file_path string representing the path to the target file.
 * @param file_mode string representing which mode to open the file.
 * @return a Complex_File struct which contains a pointer to the opened file.
 */
struct Complex_File open_complex_file(const char *file_path, const char *file_mode);

/*!
 * @brief Closes a simple file.
 *
 * @param self reference to a File struct.
 */
void close_file(File *self);

/*!
 * @brief Closes a complex file.
 *
 * @param self reference to a Complex_File struct.
 */
void close_complex_file(Complex_File *self);