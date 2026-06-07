#include "permutations.h"

/*
-------------------------------------------------
Generic permutation function

input  -> source bits

output -> destination bits

table  -> permutation table

n      -> table size
-------------------------------------------------
*/

void permute(
    int input[],
    int output[],
    int table[],
    int n
)
{
    for(int i = 0; i < n; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

/*
1. Why -1? Because DES tables start from 1 2 3... while C array starts from 0 thus table[i]-1
*/