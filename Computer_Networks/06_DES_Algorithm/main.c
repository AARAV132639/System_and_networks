// Phase 1: Testing IP permutation

#include <stdio.h>

#include "tables.h"
#include "permutations.h"
#include "bit_utils.h"
#include "key_schedule.h"
#include "fiestel.h"

int main()
{
    unsigned long long plaintext;
    unsigned long long key;

    int bits[64];
    int keybits[64];
    int afterIP[64];

    int L[32];
    int R[32];

    int expandedR[48];

    printf("Enter plaintext:");
    scanf("%llu",&plaintext);

    printf("Enter key: ");
    scanf("%llu", &key);

    // convert plain texts into 64 bits
    uint64ToBits(
        plaintext,
        bits
    );
    printf("\n Original Bits:\n");
    printBits(bits,64);

    //Converting key to bits
    uint64ToBits(
        key,
        keybits
    );

    //Generating round key

    int roundKeys[16][48];

    generateRoundKeys(
        keybits,
        roundKeys
    );

    printf("\nK1:\n");

    for(int i=0;i<48;i++) printf("%d ", roundKeys[0][i]);
    printf("\n");

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

    //expanding bits
    int expanded[48];
    expandR(R, expandedR);

    printf("\n Expanded R:\n");
    
    for(int i=0;i<48;i++) printf("%d",expanded[i]);
    printf("\n");

    //applying XOR on expanded R
    int xorOutput[48];

    xor48( expandedR, roundKeys[0], xorOutput);
    printf("\n ExpandedR XOR K1:\n");
    
    for(int i=0;i<48;i++) printf("%d", xorOutput[i]);
    printf("\n");

   // testing complete pipelineint sboxOutput[32];
    int pOutput[32]; int sboxOutput[32]; 

    sBoxSubstitution(xorOutput,  sboxOutput );

    pPermutation(sboxOutput, pOutput);

    //printing

    printf("\nAfter S-Boxes:\n");

    for(int i=0;i<32;i++) printf("%d", sboxOutput[i]);

    printf("\n");

    printf("\nAfter P-Permutation:\n");

    for(int i=0;i<32;i++) printf("%d", pOutput[i]);


    printf("\n");

    return 0;


}
