1. main.c
- User interaction
- Read plain text---> DES encrypt---> Print ciphertext---> DES decrypt---> Print plaintext

2. tables.h
- contains all DES tables
- Initial Permutation(IP)
- Final permutation(FP)
- Expansion Table(E)
- P Permutation
- PC-1
- PC-2
- Shift schedule
- 8 S-boxes

3. permuations.c
- Generic permuation functions

4. key_schedule.c: handles all key generation
- Generate 16 round keys

- PC1---> 56 bits---> Split---> C0+D0---> Left Shifts---> PC2---> Generate Ki

5. Feistel.c
- DES round function
- Heart of DES
- Implements F(R,K)
- Expansion---> 48 bits|| XOR round key---> S-box substitution---> P permutation
- This is where DES gets its security.

6. des.c
- completes DES encryption/decryption
- Initial Permutation---> Split: L0 R0---> 16 Fiestel rounds---> Swap----> Final permutation
- This file orchestrates everything


