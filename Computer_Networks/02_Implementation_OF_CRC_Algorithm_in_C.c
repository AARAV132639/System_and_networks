# include <stdio.h>
# include<string.h>

/*
1. Function: xorOperation()
2. Purpose: This performs modulo-2 division step used in CRC
*/

void xorOperation(char *dividend, char*divisor, int start, int divisorLen)
{
    for(int i=0; i<divisorLen;i++)
    {
        if(dividend[start+i]==divisor[i]) dividend[start+i] ='0';
        else dividend[start+i]='1';
    }
}

/*
- Function: crcSender()
- Purpose: simulates sender side CRC generation

- Steps:
        1. Take original data bits
        2. Take generator polynomial
        3. Append zeros(generator lenght-1)
        4. Perform modulo-2 division
        5. Exctract remainder
        6. Append remainder to original data
        7. Create final transmitter codeword
*/

void crcSender()
{
    char data[100];
    char generator[30];
    char dividend[150];
    char codeword[150];

    int dataLen, genLen;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator polynomial bits: ");
    scanf("%s", generator);

    dataLen= strlen(data);
    genLen= strlen(generator);

    //copying orignal data into dividend
    strcpy(dividend, data);

    //Appending zeroes equal to (generator length-1) because CRC remainder will occupy these bits
    for (int i=0; i<genLen-1;i++) strcat(dividend,"0");

    //Performing Modulo-2 division
    // Whenever leading bit is 1: XOR with generator

    for(int i=0; i<=strlen(dividend)- genLen; i++)
    {
        if(dividend[i]=='1')
        {
            xorOperation(dividend, generator, i, genLen);
        }
    }

    //Creating transmitted codeword--->
    strcpy(codeword, data);

    // appending CRC remainder
    for(int i= dataLen; i< dataLen+genLen-1;i++)
    {
        codeword[i]= dividend[i];
    }

    codeword[dataLen+genLen-1] = '\0';
    printf("\n CRC remainder:");
    for(int i= dataLen; i<dataLen+genLen-1;i++)
    {
        printf("%c", dividend[i]);
    }

    printf("\nTransmiter Codeword: %s\n", codeword);

}

/*
- Function: crcReciver()
- Purpose: Simulates receiver side CRC checking
- Steps:
        1. Take received codeword
        2. Take same generator
        3. Perform modulo-2 division
        4. Check remainder
        5. If remainder = all zeros----> No error
                else ----> error
*/

void crcReceiver()
{
    char received[150];
    char generator[30];

    int genLen;
    int error=0;

    printf("Enter received codeword: ");
    scanf("%s", received);

    printf("Enter generator polynomial bits:");
    scanf("%s", generator);

    genLen= strlen(generator);

    //Performing modulo-2 division on received data

    for(int i=0; i<=strlen(received)-genLen; i++)
    {
        if(received[i]=='1') xorOperation(received, generator, i, genLen);

    }

    //Checking final remainder bits
    // If any bit=1 then error exists

    for(int i=strlen(received)-genLen; i<strlen(received);i++)
    {
        if(received[i]=='1')
        {
            error =1;
            break;
        }
    }

        if(error)
            printf("\n Error detected in received data. \n");
        else printf("\n No error deteced. \n");
    


}

/*
Main function

- Lets user choose:
    1. Sender simulation
    2. Reciver Simulation
    3. Exit
*/

int main()
{
    int choice;

    do{
        printf("\n========== CRC ERROR DETECTION ==========\n");
        printf("1. Sender (Generate CRC)\n");
        printf("2. Receiver (Check CRC)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                crcSender();
                break;

            case 2:
                crcReceiver();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);

    return 0;
}
    
/*
## Sample Input and output:

1. Sender:
Enter data bits: 1101011011
Enter generator polynomial bits: 10011
CRC Remainder: 1110
Transmitted Codeword: 11010110111110

2. Reciver:
Enter received codeword: 11010110111110
Enter generator polynomial bits: 10011
No error detected.

Received: 11010100111110
Error detected in received data.
*/
