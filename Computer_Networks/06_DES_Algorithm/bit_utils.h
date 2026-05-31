#ifndef BIT_UTILS_H
#define BIT_UTILS_H

void uint64ToBits(
    unsigned long long value,
    int bits[64]
);

void printBits(
    int bits[],
    int n
);

unsigned long long bitsToUint64(
    int bits[64]
);

#endif