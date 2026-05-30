// Phase 1: Testing IP permutation

#include <stdio.h>

#include "tables.h"
#include "permutations.h"

int main()
{
    printf("---Program started---\n");

    
    int input[64];
    int output[64];

    /*
    Create test pattern

    1 2 3 ... 64
    */

    for(int i=0;i<64;i++)
    {
        input[i] = i + 1;
    }

    permute(
        input,
        output,
        IP,
        64
    );

    printf("After Initial Permutation:\n");

    for(int i=0;i<64;i++)
    {
        printf("%d ", output[i]);
    }

    printf("\n");

    return 0;
}