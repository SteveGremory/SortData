#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <string.h>
#include <uchar.h>

typedef struct {
    size_t capacity;
    size_t size;
    char* data;
} String;

void expand(String* string, size_t len);

/*
 * @brief: Create a string and return it.
 * @param data: the data to be stored.
 * @param len: length of the string being stored.
 * */
String* create_string(char* data, size_t len);

/*
 * @brief: Append a string to another one.
 * @param string: the string you want to append to.
 * @param data: data you want to append.
 * @param len: the length of the data you want to append.
 * */
void push_back(String* string, char* data, size_t len);

/*
 * @brief: Deallocates the array. Don't forget to call this after using the object.
 * @param string: The string structure you want to delete
 * */
void delete_string(String* string);

/*
 * @brief: Cleans the string.
 * @param string: The string you want to clear
 * */
void clean_string(String* string);

/*
 * @brief: increase the capacity of the string
 * @param string: the string you want to manipulate
 * @param length: the length that you want to reserve
 * */
void reserve_string(String* string, size_t length);

/*
 * @brief: Erase the characters from element position start to position end
 * @param string: the string you want to manipulate
 * @param start: starting element from which you wanna start erasing
 * @param end: the index of the element at which you want to stop erasing
 * */
void erase_string(String* string, size_t start, size_t end);

/*
 * @brief: reduce the capacity of the string to fit its size.
 * @param string: the string you want to manipulate.
 * */
void shrink_to_fit_string(String* string);
