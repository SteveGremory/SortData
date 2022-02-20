#include <stdio.h>
#include <time.h>
#include "quicksort.h"
#include "custom_string.h"
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    wchar_t* data = L"Обичам да правя секс с мъже.";
    int size = wcslen(data);

    String* str = create_string(data, size);
    
    for (int i = 0; i < 10000000; i++)
        push_back(str, data, size); 
   
    FILE* fp = fopen("hello.txt", "w+");
    fprintf(fp, "%ls\n", str->data);
    
    clean_string(str);
    return 0;
}
