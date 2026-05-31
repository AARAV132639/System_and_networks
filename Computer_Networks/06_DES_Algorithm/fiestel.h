#ifndef FEISTEL_H
#define FEISTEL_H

void expandR(
    int R[32],
    int expanded[48]
);

void xor48(
    int a[48],
    int b[48],
    int result[48]
);

//adding prototype of S1
void testS1(
    int input6[6],
    int output[4]
);

//adding generic function for S-boxes
void sBoxLookup(
    int input[64],
    int sbox[4][16],
    int output4[4]
);

void sBoxSubstitution(
    int input48[48],
    int output32[32]
);

void pPermutation(
    int input32[32],
    int output32[32]
);

//full fiestal function
void feistelFunction(
    int R[32],
    int roundKey[48],
    int output[32]
);

#endif