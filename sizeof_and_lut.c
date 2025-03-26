#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

// Definition of typedef enumerator
enum foo
{
    foo2,
    foo3,
    foo4,
};

static int squares[] = {[foo3] = 9, [foo2] = 4, [foo4] = 16};

int main()
{
    int a = 1;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p_arr = arr;

    printf("Size of int in bytes: %d\n", sizeof(int));             // 4
    printf("Size of char in bytes: %d\n", sizeof(char));           // 1
    printf("Size of long int in bytes: %zu\n", sizeof(long long)); // 8 or 16 depends on the machine

    // Array length
    printf("Size of arr: %d\n", sizeof(arr) / sizeof(arr[1])); // return the number of elements '10'

    // Size of array converted in pointer
    printf("Size of pointer array in bytes: %d\n", sizeof(p_arr)); // returns the int dimension '4'

    // Printing the element of squares regardless the order of the element in the array
    printf("%d\n", squares[foo2]); // 4
    printf("%d\n", squares[foo3]); // 9
    printf("%d\n", squares[foo4]); // 16

    return 0;
}