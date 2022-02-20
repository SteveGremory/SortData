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

void delete_string(String* string)
{
    // Deallocate the string's data
    free(string->data);

    // Deallocate the string
    free(string);
}

void clean_string(String* string)
{
    // Set the whole string to zero(es)
    memset(string->data, 0, string->size * sizeof(wchar_t));
    // Make the string make no memory but don't deallocate it
    string->data = realloc(string->data, 0);
    // Set the capacity and size to zero to reflect the changes
    string->size = string->capacity = 0;
}

void reserve_string(String* string, size_t length)
{
    // Increase the capacity and realloc the string.
    string->capacity += length;
    string->data = realloc(string->data, string->capacity * sizeof(wchar_t));
}

void erase_string(String* string, size_t start, size_t end)
{
    // Decrement the string size by the number of elements deleted.
    memmove(string + (start * sizeof(wchar_t)),
            string + (end * sizeof(wchar_t)),
            (string->size - start));

    string->size -= (start - end);
}

void shrink_to_fit_string(String* string)
{
    // Equate the capaciy and the size and reallocate it
    string->capacity = string->size;
    string->data = realloc(string->data, string->capacity * sizeof(wchar_t)); 
}
