#define _GNU_SOURCE
#include <sys/mman.h>
#include "custom_string.h"
#include <errno.h>

/*
 * @brief: Append to a string
 * @param dest: the string you want to append to
 * @param destsize: length of the dest string
 * @param source: the string that is to be appended
 * @param sourcesize: the size of the string you want to append
 * */
void append(char* dest, size_t destsize, char* source, size_t sourcesize)
{
    memcpy((dest + destsize), source, (sourcesize * sizeof(char)));
}

String* create_string(char* data, size_t len)
{
    // Allocte the string on the heap
    char* temp = malloc(len * sizeof(char));
    memcpy(temp, data, len * sizeof(char));
    // Create a stack allocated
    String* str = malloc(sizeof(String));

    str->data = temp;
    str->capacity = len;
    str->size = len;

    return str;
}

void expand(String* string, size_t len)
{
    if ((string->size + len) > string->capacity) { 
        // Triple the string's capacity
        string->capacity *= 3;
        
        // Let's say a huge string was appended to a small one
        // make sure that the capacity is indeed enough to hold it.
        if (string->capacity < (string->size + len))
            string->capacity += len;

        // Reallocate the string
        string->data = realloc(string->data,
            string->capacity * sizeof(char));
    }        
}

void push_back(String* string, char* data, size_t len)
{
    expand(string, len);
    // Append the data to the string
    append(string->data, string->size, data, len);
    // Update the length of the string
    string->size += len;
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
    memset(string->data, 0, string->size * sizeof(char));
    // Make the string make no memory but don't deallocate it
    string->data = realloc(string->data, 0);
    // Set the capacity and size to zero to reflect the changes
    string->size = string->capacity = 0;
}

void reserve_string(String* string, size_t length)
{
    // Increase the capacity and realloc the string.
    string->capacity += length;
    string->data = realloc(string->data, string->capacity * sizeof(char));
}

void erase_string(String* string, size_t start, size_t end)
{
    size_t len = (string->size - end);
    memmove(string->data + (start - 1), string->data + end, len * sizeof(char));
    // FIX ME

    printf("FIX ME! LINE 80 CUSTOM_STRING.C\n");
    exit(1);

    // memset(string->data + string->size, 0, 0);
}

void shrink_to_fit_string(String* string)
{
    // Equate the capaciy and the size and reallocate it
    string->capacity = string->size;
    string->data = realloc(string->data, string->capacity * sizeof(char));
}
