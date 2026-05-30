// Phase 1: Testing IP permutation

#include <stdio.h>

#include "tables.h"
#include "permutations.h"

int main()
{
    printf("---Program started---\n");


    int input[64];
    int afterIP[64];
    int afterFP[64];

    /*
    Create test pattern

    1 2 3 ... 64
    */

    for(int i=0;i<64;i++)
    {
        input[i] = i + 1;
    }

    // Applying initial permutation
    permute(
        input,
        afterIP,
        IP,
        64
    );

    // Applying final permutation
    permute(
        afterIP,
        afterFP,
        FP,
        64
    );

    printf("Recovered data:\n");

    for(int i=0;i<64;i++)
    {
        printf("%d ", afterFP[i]);
    }

    printf("\n");

    return 0;
}