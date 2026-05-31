#ifndef DES_H
#define DES_H

void DES(
    int inputBits[64],
    int roundKeys[16][48],
    int outputBits[64],
    int decrypt
);

#endif