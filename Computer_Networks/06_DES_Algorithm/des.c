// applying the loop to decrypt. Uses key in reverse order

#include "tables.h"
#include "permutations.h"
#include "fiestel.h"
#include "des.h"

void DES(
    int inputBits[64],
    int roundKeys[16][48],
    int outputBits[64],
    int decrypt
)
{
    int afterIP[64];

    permute(
        inputBits,
        afterIP,
        IP,
        64
    );

    int L[32];
    int R[32];

    for(int i=0;i<32;i++)
    {
        L[i] = afterIP[i];
        R[i] = afterIP[i+32];
    }

    for(int round=0;
        round<16;
        round++)
    {
        int keyIndex;

        if(decrypt)
            keyIndex = 15 - round;
        else
            keyIndex = round;

        int fOutput[32];
        int newL[32];
        int newR[32];

        feistelFunction(
            R,
            roundKeys[keyIndex],
            fOutput
        );

        for(int i=0;i<32;i++)
        {
            newL[i] = R[i];
        }

        for(int i=0;i<32;i++)
        {
            newR[i] =
                L[i] ^ fOutput[i];
        }

        for(int i=0;i<32;i++)
        {
            L[i] = newL[i];
            R[i] = newR[i];
        }
    }

    int preOutput[64];

    for(int i=0;i<32;i++)
    {
        preOutput[i] = R[i];
        preOutput[i+32] = L[i];
    }

    permute(
        preOutput,
        outputBits,
        FP,
        64
    );
}