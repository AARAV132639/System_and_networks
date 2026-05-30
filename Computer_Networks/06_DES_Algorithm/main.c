// Phase 1: Testing IP permutation

#include <stdio.h>

#include "tables.h"
#include "permutations.h"
#include "bit_utils.h"

int main()
{
    unsigned long long plaintext;

    int bits[64];
    int afterIP[64];

    int L[32];
    int R[32];

    printf("Enter plaintext:");
    scanf("%llu",&plaintext);

    // convert plain texts into 64 bits
    uint64ToBits(
        plaintext,
        bits
    );
    printf("\n Original Bits:\n");
    printBits(bits,64);

    //Apply initial permutation

    permute(
        bits,
        afterIP,
        IP,
        64
    );

    printf("\n After IP:\n");
    printBits(afterIP, 64);

    //Split into L0 and R0

    for(int i=0;i<32;i++) L[i]= afterIP[i];

    for(int i=0;i<32;i++) R[i]= afterIP[i+32];

    printf("\n L0:\n");
    printBits(L,32);

    printf("\n R0:\n");
    printBits(R,32);

    return 0;


}
