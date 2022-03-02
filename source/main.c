#include "custom_string.h"
#include "files/custom_file.h"

int main()
{

    File* file = open_file("main.mkv", BOTH | LARGEFILE);
    read_file(file);

//    String* str = get_string(file);

    File* writing = open_file("hello.mkv", BOTH | LARGEFILE);
    write_file(writing, file->contents, file->size); 

    cleanup_file(file); 
    cleanup_file(writing);
//    delete_string(str);
    return 0;
}

