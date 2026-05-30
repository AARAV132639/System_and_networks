#include <stdio.h>

#include "bit_utils.h"

/*
--------------------------------------------
- Convert 64-bit integer into 64 individual bits.
- DES works on bits, not integers

Example:

13 becomes 000...00001101
--------------------------------------------
*/

void uint64ToBits(
    unsigned long long value,
    int bits[64]
)
{
    for(int i=63;i>=0;i--)
    {
        bits[i] = value & 1;
        value >>= 1;
    }
}

/*
--------------------------------------------
Print bit array.
--------------------------------------------
*/

void printBits(
    int bits[],
    int n
)
{
    for(int i=0;i<n;i++)
    {
        printf("%d", bits[i]);
    }

    printf("\n");
}