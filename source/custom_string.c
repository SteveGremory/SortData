#include "custom_string.h"

#include <string.h>
#include <stdio.h>
#include <wchar.h>

void append(wchar_t* dest, int destsize, wchar_t* source, int sourcesize)
{
    memcpy(dest + (destsize), source, ( sourcesize * sizeof(wchar_t) ) );
}

String* create_string(wchar_t* data, size_t len)
{
    // Allocte the string on the heap
    wchar_t* temp = malloc(len * sizeof(wchar_t));
    memcpy(temp, data, len * sizeof(wchar_t));
    // Create a stack allocated 
    String* str = malloc(sizeof(String));
    
    str->data = temp;
    str->capacity = len;
    str->size = len;
    
    return str;
}

void push_back(String* string, wchar_t* data, size_t len)
{
    if ((string->size + len) > string->capacity) {
        // Double the capacity of the string
        string->capacity *= 2;
        // Reallocate the string
        string->data = realloc(string->data,
                string->capacity * sizeof(wchar_t)); 
        // Append the data to the string
        append(string->data, string->size, data, len); 
        // Update the length of the string
        string->size += len;
    } else {
        // Append the data to the string
        append(string->data, string->size, data, len); 
        // Update the length of the string
        string->size += len;
    }
}
