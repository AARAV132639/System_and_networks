#include "tables.h"
#include "permutations.h"
# include "fiestel.h"

//Expand 32 bits into 48 bits

void expandR(
    int R[32],
    int expanded[48]
)
{
    permute(
        R,
        expanded,
        E,
        48
    );
}

/*
---> Applying XOR logic

0^0=0
1^1=0
1^0=1
0^1=1
*/

void xor48(
    int a[48],
    int b[48],
    int result[48]
)
{
    for(int i=0;i<48;i++) result[i]= a[i]^b[i];
}

void testS1( int input6[6], int output4[4])
{
    int row; int col;

    row= input6[0]*2+input6[5];

    col= input6[1]*8+input6[2]*4+input6[3]*2+input6[4];

    int value= S1[row][col];

    for(int i=3; i>=0;i--) 
    {
        output4[i]= value%2;
        value/=2;
    }
}

void sBoxLookup ( int input6[6], int sbox[4][16], int output4[4])
{
    int row; int col;

    row= input6[0]*2+ input6[5];

    col= input6[1]*8 + input6[2]*4+ input6[3]*2+ input6[4];

    int value= sbox[row][col];

    for(int i=3; i>=0; i--) 
    {
        output4[i]= value%2;
        value/=2;
    }
}

void sBoxSubstitution(
    int input48[48],
    int output32[32]
)
{
    int block[6];
    int result[4];

    int outIndex = 0;

    for(int s=0;s<8;s++)
    {
        for(int i=0;i<6;i++)
        {
            block[i] =
                input48[s*6 + i];
        }

        /*
        Apply S1,S2,S3...
        */

        
            switch(s)
{
    case 0:
        sBoxLookup(block,S1,result);
        break;

    case 1:
        sBoxLookup(block,S2,result);
        break;

    case 2:
        sBoxLookup(block,S3,result);
        break;

    case 3:
        sBoxLookup(block,S4,result);
        break;

    case 4:
        sBoxLookup(block,S5,result);
        break;

    case 5:
        sBoxLookup(block,S6,result);
        break;

    case 6:
        sBoxLookup(block,S7,result);
        break;

    case 7:
        sBoxLookup(block,S8,result);
        break;
}
        

        for(int i=0;i<4;i++)
        {
            output32[outIndex++] =
                result[i];
        }
    }
}

void pPermutation(
    int input32[32],
    int output32[32]
)
{
    permute(
        input32,
        output32,
        P,
        32
    );
}

