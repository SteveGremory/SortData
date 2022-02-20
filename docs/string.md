# String manipulation
## General API
    - Creation: Creates a string, returns the structure.
    ```c
    String* create_string(wchar_t* data, size_t len);
    ```
    - Append: Appends to a string, takes in the string structure you want to append to, the data you wanna append to and the length of the data you want to append.
    ```c
    void push_back(String* string, wchar_t* data, size_t len);
    ```
    - Delete: Deallocate the string, as it's allocated on the heap.
    ```c
    void delete_string(String* string);
    ```
    - Clean: Clean the string, sets the data to all zeroes and makes the length zero.
    ```c
    void clean_string(String* string);
    ```
    - Reserve: Reserve some capacity in the string to be filled in later.
    ```c
    void reserve_string(String* string, size_t length);
    ```
    - Erase: Remove elements at an index.
    ```c
    void erase_string(String* string, size_t start, size_t end);
    ```
    - Shrink to fit: Reduce the capacity of the string to fit it's size.
    ```c
    void shrink_to_fit_string(String* string);
    ```


