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