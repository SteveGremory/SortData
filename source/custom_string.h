#pragma once
#include <stdlib.h>

typedef struct {
    size_t capacity;
    size_t size;
    wchar_t* data;
} String;

/*
 * @brief: Create a string and return it.
 * @param data: the data to be stored.
 * @param len: length of the string being stored.
 * */
String* create_string(wchar_t* data, size_t len);
/*
 * @brief: Append a string to another one.
 * @param string: the string you want to append to.
 * @param data: data you want to append.
 * @param len: the length of the data you want to append.
 * */
void push_back(String* string, wchar_t* data, size_t len);

