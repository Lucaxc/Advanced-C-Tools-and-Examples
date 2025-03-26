#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

/* -----------------------------------------------------------------------------------------
This exercise explains what a void pointer is and its usage.
To recall, a pointer is a sort of 'container' that contains the address of a variable.
------------------------------------------------------------------------------------------*/

// Void function with void* data type as input
void custom_memset(void *data, uint8_t c, size_t n)
{
    uint8_t *data_as_bytes = (uint8_t *)data; // casting the void data type pointer into a uint8_t data pointer type

    for (size_t i = 0; i < n; i++)
    {
        data_as_bytes[i] = c; // placing '0' in the array
    }

    // return data;
}

int main()
{
    int a = 5;
    int *p; // normal pointer
    p = &a; // assigning to the pointer the address of the variable

    printf("Integer pointer content: %d\n\n", *p); // '*' is used to dereference the pointer, i.e. to access the value pointed by the pointer

    void *pointer = &a; // void pointer without any data type
    printf("Void pointer needs to be casted and dereferenced: %d\n\n", *(int *)p);

    // Example array
    int array[5] = {1, 2, 3, 4, 5};

    // Printing the array before custom_memset
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array[i]);
    }

    custom_memset(array, 0, sizeof(array));

    // Printing the array after custom_memset
    printf("\nArray with custom_memset applied:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}