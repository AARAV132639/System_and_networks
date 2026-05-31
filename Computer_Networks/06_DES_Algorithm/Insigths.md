## Phase 1

1. Why "clear && gcc main.c permutations.c -o main && ./main" worked?

- clear: wipes the terminal screen completely
- &&: AND ONLY THEN operator
- gcc main.c permutations.c -o main: Re-compiles both files into a brand-new executable
- ./main: executes the freshly created main file

!! Secret culptrit---> Terminal buffering
- **printf** doesn't always send text straight to the screen immediately rather it stores it in a temporary memory warehouse called *buffer*
- The buffer dumps its next to the screen when it hits a newline character \n
- During ./main previously the program may have finished so quickly that the VS code terminal closed the stream before the buffer could flus
- Chaining the commands changes how the shell process manages the standard output stream, forcing your terminal to display the text instantly.

## Phase 2
- Added FP table
- DES Later performs: 64-bit plaintext--->IP--->16 Fiestal rounds---> FP---> cipher text
- FP(IP(x))=x

## Phase 3: Bit representation and splitting
1. Goal--->
            1. 64-bit Plaintext
            2. Convert to bit array
            3. Apply IP
            4. Split into: L0 (32 bits) R0(32 bits)
            - This is exactly what DES does before Round 1

2. Why split into L and R?
    - Because DES is a Feistal cipher
    - Every round operates on Li and Ri
    - Round transformation is: Li = R_i-1
    - R_i= L_i-1 ^ F(R_i-1, K_i)
    - Thus before starting Rounds we need L0 and R0

## Phase 4: Key Scheduling

1. Workflow:
            - Enter plaintext
            - Enter key
            - Convert plain text--->bits
            - Convert key---> bits
            - Generate K1-K16
            - Print K1
            - Apply IP
            - Split L0/R0

2. updated table.h in which used the keyword *extern* to tell the files that this exists somewhere else
3. Linker error means global variables have been defined multiple places

## Phase 4A: Expansion Table

1. clear && gcc main.c permutations.c bit_utils.c fiestel.c key_schedule.c tables.c -o  main && ./main

2. Flow inside main():
                    - read plaintext
                    - read key
                    - convert plaintext--->bits
                    - convert key--->bits
                    - generate roundkeys
                    - Apply IP
                    - Split into L0 R0
                    - Expand R0 ---> expandedR(48 bits)
                    - print expandedR

3. The right half R0 containts 32 bits, Round key K1 has 48 bits
4. To XOR them sizes must match. Thus DES expands 32 bits to 48 bits using Expansion table
5. What does E do?----> It performs expansion of duplicates boundary bits
    E.g. ABCDEFGH----> HABCDEDEFGHI.... hence some bits appear twice
6. Next step ExpandedR^K1

## Phase 4B: XOR expanded R with Round Key

- For first time Data---> Key mixing
- This is actual encryption work
- Before this we were only re arranging bits but now secret key affects data

- Next step: Currently ---> 48 bits. DES cannot continue with 48 bits. It must shrink back to 32 bits
- This is done by *8 S-boxes*

- Process: 48 bits---> split into 8 groups [6 bits each]---> S1 S2 S3....----> 32 bits
- S-boxes are most important part of DES security. Almost all DES resistance to attacks comes from them.

- Next step: Add S1-S8 tables and convert 48 bits back to 32 bits