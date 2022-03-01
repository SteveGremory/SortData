#define _LARGEFILE64_SOURCE     /* See feature_test_macros(7) */
#include <sys/types.h>
#include <unistd.h>
#define _FILE_OFFSET_BITS  64
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    int fd = open("hello.txt", O_RDONLY);
    size_t size = lseek(fd, 0, SEEK_END);
    printf("Size: %ld", size);
    char* addr = mmap(NULL, size, PROT_READ,
        MAP_PRIVATE, fd, 0);
 
    int fd_write = open("hello_write.txt", O_RDWR | O_CREAT);
    
    lseek(fd_write, size-1, SEEK_SET);
    
    write(fd_write, "", 1);
    char *map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd_write, 0);
    
    memcpy(map, addr, size);
    munmap(addr, size);
    close(fd);
    
    msync(map, size, MS_SYNC);
     
    munmap(map, size);
    close(fd_write);
    
    return 0;
}

