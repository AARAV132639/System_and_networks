#ifndef TABLES_H
#define TABLES_H


// Just a declaration. Tells the compiler: "These exist somewhere else."
extern int IP[64];
extern int FP[64];
extern int PC1[56];
extern int PC2[48];
extern int SHIFTS[16];

#endif



/*

1. What is this table?
- Suppose input bits are 1 2 3 4 5 6...64
- After IP: 58 50 42...
- output[1]= input[58]
- Its just reordering of bits

2. Why FP tables exists?
-IP shuffles bit
- FP unshuffles them
- Basically they are inverses
- FP(IP(x)) =x

3. What is PC-1?
- Permuted choice
- PC-1 means 64 bits---> 56 bits
- Removes parity bits and rearranges remaining bits

4. What is PC-2?
- 56 bits---> 48 bits
- Selects bits used in round key
*/