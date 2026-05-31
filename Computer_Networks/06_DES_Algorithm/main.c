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

    //applying fiestel loop

    for(int round=0; round<16; round++)
{
    int fOutput[32];
    int newL[32];
    int newR[32];

    /*
    F(R,Ki)
    */

    feistelFunction( R,roundKeys[round], fOutput );

    /*
    Li = Ri-1
    */

    for(int i=0;i<32;i++)  newL[i] = R[i];
    
    /*
    Ri = Li-1 XOR F(Ri-1,Ki)
    */

    for(int i=0;i<32;i++) newR[i] = L[i] ^ fOutput[i];
    
    /*
    Update L,R
    */

    for(int i=0;i<32;i++)
    {
        L[i] = newL[i];
        R[i] = newR[i];
    }

    printf("\nRound %d Complete",round+1);
}

    int preOutput[64];

    for (int i=0;i<32; i++) preOutput[i]= R[i];
    for (int i=0;i<32;i++) preOutput[i+32]= L[i]; // To be noticed: R first and L second. This is DES's final swap

    //applying FP
    int cipherBits[64];

    permute(preOutput, cipherBits, FP, 64);

    //printing cipher text bits
    printf("\n Cipher text:\n");

    for(int i=0; i<64;i++) printf("%d", cipherBits[i]);

    printf("\n");

    //printing cipher text generation

    unsigned long long cipherValue;
    cipherValue= bitsToUint64(cipherBits);
    printf("\n CipherText Value: %llu\n", cipherValue);


    return 0;


}
