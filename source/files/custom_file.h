#pragma once

#include "strings/custom_string.h"

enum MODES {
    READ = 82,
    WRITE = 87,
    BOTH = 66,
    LARGEFILE = 76
};

typedef struct {
    int fp; // Low level file descriptor.
    size_t size; // Length of the file.
    size_t line; // The line it's currently on.
    int mode;
    char* contents; // The contents of the file.
                    // empty unless the read/write
                    // functions are called.
} File;

/*
 * @brief: Opens a file.
 * @param filename: the path (to) and name (of) the file that you want to open.
 * */
File* open_file(char* filename, int mode);

/*
 * @brief: Read the data of a file into memory.
 * @param file: the file you want to read into memory.
 * */
void read_file(File* file);

/*
 * @brief: Write provided data to a file.
 * @param file: the file you want to write to.
 * @param data: the data you want to write.
 * @param length: the length of the data that you want to write.
 * */
void write_file(File* file, char* data, size_t length);

/*
 * @brief: Get data at a specific line in a file.
 * @param file: the file you want to read the line from.
 * @param line: the line you want to read.
 * @returns: the data in that line.
 * */
char* getline_file(File* file, size_t line);

/*
 * @brief: Get the data of the file as a String.
 * @param file: the file who's data you wish to get.
 * @returns: returns the string struct.
 * */
String* get_string(File* file);

/*
 * @brief: Get the data of a file as a char* array.
 * @param file: the file who's data you wish to get. 
 * @returns: Returns the data as a char*
 * */
char* get_array(File* file);

/*
 * @brief: seek to a given line in the file.
 * @param line: the line you want to seek.
 * */
void seek_file(File* file, size_t line);

/*
 * @brief: Clean up the memory.
 * */
void cleanup_file(File* file);

