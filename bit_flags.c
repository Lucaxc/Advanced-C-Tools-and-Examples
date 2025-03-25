#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* -----------------------------------------------------------------------------------------
This exercise explains the usage of bit flag for stack optimization when creating functions
We have two ways to create a bitflag.
------------------------------------------------------------------------------------------*/

/* %%%%%%%%%%%%%%%%%%%%%%%%%%
Example 1: in this case all the flags will be in an unsigned integer. Actually we set each
bit to a specific flag.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

typedef unsigned int t_flag; // this occupies 32 bits in terms of memory allocation
// typedef char t_flag; //this occupies only 8 bits in terms of memory allocation

#define FLAG_1 1
#define FLAG_2 1 << 1
#define FLAG_3 1 << 2

// Function example to apply flags with bitwise operations
int foo(int x, t_flag flags)
{
    printf("Flag: %d\n", flags);
    if (flags & FLAG_1)
    {
        x += 10;
    }
    else if (flags & FLAG_2)
    {
        x += 20;
    }
    else if (flags & FLAG_3)
    {
        x += 30;
    }

    return x;
}

int main()
{
    printf("Increment by 10 from %d to %d\n", 1, foo(1, FLAG_1));
    printf("Increment by 20 from %d to %d\n", 1, foo(1, FLAG_2));
    printf("Increment by 30 from %d to %d\n", 1, foo(1, FLAG_3 | FLAG_1));

    return 0;
}

/*
Uncomment the following code and comment the previous section for Example 2
*/

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Example 2: the other possibility is to use enumeration, avoiding macros
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

/*
typedef enum
{
    FLAG_A = 1,
    FLAG_B = 1 << 1,
    FLAG_C = 1 << 2
} t_flag1;

int foo(int x, t_flag1 flags)
{
    if (flags & FLAG_A)
    {
        x += 10;
    }
    else if (flags & FLAG_B)
    {
        x += 20;
    }
    else if (flags & FLAG_C)
    {
        x += 30;
    }

    return x;
}

int main()
{
    printf("Increment by 10 from %d to %d\n", 1, foo(1, FLAG_A));
    printf("Increment by 20 from %d to %d\n", 1, foo(1, FLAG_B));
    printf("Increment by 30 from %d to %d\n", 1, foo(1, FLAG_C));

    return 0;
}
*/
