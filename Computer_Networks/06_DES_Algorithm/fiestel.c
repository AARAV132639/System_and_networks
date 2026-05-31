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