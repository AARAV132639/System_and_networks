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