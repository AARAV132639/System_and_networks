// Implementation of LZW compression on Input String

#include <stdio.h>
#include<string.h>

/*

1. Structure: Dictionary Entry

2. Stores:
            i. Pattern/String
            ii. Assigned Code
        
        E.g.---> AB: 256, ABA: 257

*/

struct Dictionary{
    char str[50];
    int code;
};

int main()
{
    //Step 1: Create a dictionary. First 256 entries reserved for ASCII
    struct Dictionary dict[1000];

    int dictsize= 256;

    for(int i=0;i<256;i++)
    {
        
        
            dict[i].str[0]= (char)i;
            dict[i].str[1]='\0';
            dict[i].code=i;
        
    }

    //Step 2: Read input String

    char input[100];
    printf("Enter String: ");
    scanf("%s", input);

    //Step 3: Start LZW compression
    char current[100];
    char next[100];

    current[0]= input[0];
    current[1]= '\0';

    printf("\n Compressed Codes:\n");

    for(int i=1; i<strlen(input);i++)
    {
        strcpy(next,current);

        int len= strlen(next);

        next[len]= input[i];
        next[len+1]='\0';

    //Checking whether current+next exists in dictionary
    int found=-1;

    for(int j=0;j<dictsize;j++)
    {
        if(strcmp(dict[j].str,next)==0) { found=j; break;}
    }

    //If found then extend the current string
    if(found!=-1) strcpy(current,next);
    
    /*
    if not found:
                1. Output code of current string
                2. Add new pattern
                3. Continue
    */
   else{

    for(int j=0;j<dictsize;j++)
    {
        if(strcmp(dict[j].str,current)==0)
        {
            printf("%d", dict[j].code);
            break;
        }
    }

    strcpy(dict[dictsize].str,next);
    dict[dictsize].code= dictsize;

    dictsize++;

    current[0]= input[i];
    current[1]='\0';
   }
}

// Step4: output last remaining code

for(int j=0;j<dictsize;j++)
{
    if(strcmp(dict[j].str,current)==0)
    {
        printf("%d", dict[j].code);
        break;
    }
}

printf("\n");
return 0;  

    
}

/*
Example run:

1. Input---> ABABABA
2. Output---> 65 66 256 258

*/