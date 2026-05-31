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
#endif