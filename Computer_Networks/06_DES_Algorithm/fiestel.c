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