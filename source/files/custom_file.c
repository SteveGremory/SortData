#define _LARGEFILE64_SOURCE 
#define _FILE_OFFSET_BITS  64

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

#include "custom_file.h"

File* open_file(char* filename, int mode)
{
    File* file = malloc(sizeof(File));
    
    int file_mode;
    // TODO: Please remember to fix this.
    // I bet this is the worst way to do this
    // but idc rn just need it to work
    switch (mode)
    {
        // For normal files
        case READ:
            file_mode = O_RDONLY;
            break; 
        case WRITE:
            file_mode = O_RDWR;
            break;
        case BOTH:
            file_mode = O_RDWR;
            break;

        // For large files
        case (READ | LARGEFILE):
            file_mode = O_RDONLY | O_LARGEFILE;
            break; 
        case (WRITE | LARGEFILE):
            file_mode = O_RDWR | O_LARGEFILE;
            break;
        case (BOTH | LARGEFILE):
            file_mode = O_RDWR | O_LARGEFILE;
            break;
        default:
            printf("Please enter a valid Mode.\n");
            exit(false);
            break;
    }

    file->fp = open(filename, file_mode, 0644);
    size_t size = lseek(file->fp, 0, SEEK_END);

    file->contents = NULL;
    file->size = size + 1;
    file->line = 0;
    
    return file;
}

void read_file(File* file) {
    file->contents = mmap(NULL, file->size, PROT_READ,
            MAP_SHARED, file->fp, 0);
    file->line = 1;
}

void write_file(File *file, char* data, size_t length)
{
    file->size = length;
    file->line = length;
    
    lseek(file->fp, file->size, SEEK_SET);
    write(file->fp, "", 1);

    file->contents = mmap(NULL, file->size, PROT_WRITE,
            MAP_SHARED, file->fp, 0);

    memcpy(file->contents, data, length);
    msync(file->contents, length, MS_SYNC);
}

void cleanup_file(File *file)
{
    munmap(file->contents, file->size);
    file->contents = NULL;
    close(file->fp);
    free(file);
}

void seek_file(File* file, size_t line)
{
    file->line = line;
    lseek(file->fp, file->line, SEEK_SET);
}

String* get_string(File* file)
{ 
    char* data = malloc(file->size * sizeof(char));
    memcpy(data, file->contents, file->size);
    
    String* string = malloc(sizeof(String));
    
    string->capacity = file->size;
    string->size = file->size;
    string->data = data;
    return string;
}

char* get_array(File* file)
{
    return file->contents;
}

