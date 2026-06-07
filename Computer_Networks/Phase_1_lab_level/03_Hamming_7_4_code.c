// Implementation of Hamming (7,4) code to limit the noise.

#include <stdio.h>

/*

1. Funtion: calculateParity()

2. Purpose: Calculates parity bit value

3. Parity rule: Even parity is used

    - If number of 1s is odd:
        - parity bit =1
    
    - else, parity bit =0

*/

int calculateParity(int a, int b, int c) {return a^b^c;}

/*

1. Function: main()

2. Purpose:
            1. Take 4-bit data
            2. Generate Hamming(7,4) code
            3. Simulate receiver code
            4. Detect error position
            5. Correct single-bit error

*/

int main()
{
    int data[4];
    int hamming[8];

    //Hamming[0] unused. Using positions 1 to 7

    printf("Enter 4 data bits:\n");

    for(int i=0;i<4;i++) scanf("%d",&data[i]);

    /*
    1. Step1---> Place the data bits in non-parity positions
        e.g.: 3,5,6,7
    */

    hamming[3]= data[0];
    hamming[5]= data[1];
    hamming[6]= data[2];
    hamming[7]= data[3];

    /*
    2. Step 2----> calculate parity bits

        - P1 covers: 1,3,5,7
        - P2 covers: 2,3,6,7
        - P4 covers: 4,5,6,7
    */

    hamming[1]= calculateParity(hamming[3],hamming[5],hamming[7]);

    hamming[2]= calculateParity(hamming[3], hamming[6], hamming[7]);

    hamming[4]= calculateParity(hamming[5], hamming[6], hamming[7]);

    //Step 3---> displaying generated hamming code
    printf("\nGenerated Hamming Code\n");

    for(int i=1;i<=7;i++) printf("%d", hamming[i]);

    printf("\n");

    /*
    4. Step4---> Simulating transmission error

    Receiver recieves 7 bits. User can manually introduce error
    */

    int recieved[8];

    printf("\n Enter recieved 7-bit code:\n");

    for(int i=1; i<=7;i++) scanf("%d",&recieved[i]);

    // Step5: Recalculate parity at reciever side. These are called syndrome bits

    int p1, p2,p4;

    p1= recieved[1]^recieved[3]^recieved[5]^recieved[7];
    p2= recieved[2]^recieved[3]^recieved[6]^recieved[7];
    
    p4= recieved[4]^recieved[5]^recieved[6]^recieved[7];

    /*
    6. Step 6---> determine Error

        - Binary: p4 p2 p1
        - Example: 101=5, Error at position 5
    */
   int errorPosition = p4*4+p2*2+p1;

   // Step 7---> Detect & Correct the error

   if(errorPosition==0) printf("\n No error detected.\n");
   else printf("\n Error detected at position: %d\n", errorPosition);

   //Flip the erroneous bit
   recieved[errorPosition]= !recieved[errorPosition];

   printf("Correted Code: \n");

   for(int i=1;i<=7;i++) printf("%d", recieved[i]);

   printf(" \n");

   return 0;
   
    
}

/*

# Sample Run--->
                1. Input: Data bits--> 1011
                2. Generated Code----> 0110011
                3. Introduce error---> 0110111
                
                //Reciever Output:
                4. Error detected at position: 5
                5. Corrected Code------------> 0110011

- What makes Hamming Code different from CRc?
- Ans: CRC only detects errors while Hamming detects and corrects it to

*/