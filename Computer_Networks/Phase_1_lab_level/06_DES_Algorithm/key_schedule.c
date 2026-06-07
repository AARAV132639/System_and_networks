#include<stdio.h>

#include "tables.h"
#include "permutations.h"
#include "key_schedule.h"

/*
- Left Circular Shift
- Example: 1011
- shift 1
- 0111
*/

void leftShift(
    int arr[],
    int size,
    int shifts
)
{
    while(shifts--)
    {
        int first= arr[0];

        for(int i=0;i<size-1;i++) arr[i]=arr[i+1];

        arr[size-1]= first;
    }
}

void generateRoundKeys(
    int key64[],
    int roundKeys[16][48]
)
{
    int key56[56];

    //Apply PC-1

    permute(
        key64,
        key56,
        PC1,
        56
    );

    int C[28]; int D[28];

    //Split Key
    for(int i=0;i<28;i++)
    {
        C[i]= key56[i];
        D[i]= key56[i+28];

    }

    //Generate K1- K16
    for(int round=0; round<16; round++)
    {
        leftShift(
            C,
            28,
            SHIFTS[round]
        );

        leftShift(
            D,
            28,
            SHIFTS[round]
        );

        int CD[56];

        for(int i=0; i<28;i++)
        {
            CD[i]= C[i];
            CD[i+28]= D[i];
        }

        permute(
            CD,
            roundKeys[round],
            PC2,
            48
        );
    }
}

/*
1. Why we need this?
- Every DES round changes: Ci Di using circular shifts
- Without shifting all round keys identical. DES becomes weak

2. For any gives key :64 bits|| We can now generate: K1 K2 K3....K16 exactly as DES require
*/