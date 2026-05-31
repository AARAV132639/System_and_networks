// Phase 1: Testing IP permutation

#include <stdio.h>

#include "tables.h"
#include "permutations.h"
#include "bit_utils.h"
#include "key_schedule.h"
#include "fiestel.h"
#include "des.h"

int main()
{
    unsigned long long plaintext;
    unsigned long long key;

    int bits[64];
    int keybits[64];
    
    int roundKeys[16][48];

    int cipherBits[64];
    int recoveredBits[64];

    printf("enter plaintext:");
    scanf("%llu", &plaintext);

    printf("enter key:");
    scanf("%llu", &key);

    //Convert plaintext and key to bits

    uint64ToBits(plaintext, bits);

    uint64ToBits(key, keybits);

    //Generating K1-k16
    generateRoundKeys(keybits, roundKeys);

    //encrypt
    DES(bits, roundKeys, cipherBits, 0);

    printf("\n ciphertext Bits:\n");
    for(int i=0;i<64;i++) printf("%d", cipherBits[i]);

    //Ciphertext as Integer
    unsigned long long cipherValue;
    cipherValue= bitsToUint64(cipherBits);

    printf("\n Ciphertext Value: %llu\n", cipherValue);

    //Decrypt
    DES(cipherBits, roundKeys, recoveredBits, 1);

    printf("\n Recovered Plaintext Bits:\n");

    for(int i=0; i<64;i++) printf("%d", recoveredBits[i]);

    printf("\n");

    //Sanity check
    unsigned long long recoveredValue = bitsToUint64(recoveredBits);

printf("\nRecovered Value: %llu\n", recoveredValue);

printf("Original Value : %llu\n", plaintext);

    //verify recovery
    unsigned long long originalValue = bitsToUint64(bits);



if(originalValue == recoveredValue)
{
    printf("\nSUCCESS: Plaintext recovered correctly.\n" );
}
else
{
    printf("\nERROR: Recovery failed.\n");
}
    

    return 0;
}
