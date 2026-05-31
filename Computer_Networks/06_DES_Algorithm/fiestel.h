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
#endif