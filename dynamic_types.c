#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
    tag_bool,
    tag_int,
    tag_float,
} tags;

// Struct for dynamic data types
struct dynamic
{
    tags tag;

    // union is used to allocate memory for different objects inside it that are not used simoultaneously
    union
    {
        bool b;
        int i;
        float f;
    } value;
};

int main()
{
    struct dynamic d;

    // Here we chose what to address
    d.tag = tag_int;
    d.value.i = 42;

    switch (d.tag)
    {
    case tag_bool:
        printf("Bool: %d\n", d.value.b);
        break;
    case tag_int:
        printf("Int: %d\n", d.value.i); // this will be printed
        break;
    case tag_float:
        printf("Float: %f\n", d.value.f);
    }

    return 0;
}