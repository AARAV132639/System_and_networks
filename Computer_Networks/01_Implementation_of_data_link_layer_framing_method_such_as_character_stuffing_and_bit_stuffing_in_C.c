# include <stdio.h>
#include<string.h>

# define FLAG 'F'
# define ESC 'E'

void characterStuffing()
{
    char data[100], stuffed[200], destuffed[100];

    int i,j=0,k=0;

    printf("Enter data for character stuffing:");
    scanf("%s",data);

    stuffed[j++]= FLAG;

    for(i=0;data[i]!='\0';i++)
    {
        if(data[i]==FLAG||data[i]==ESC)
        {
            stuffed[j++] = ESC;
        }
        stuffed[j++]= data[i];
    }

    stuffed[j++] = FLAG;
    stuffed[j]= '\0';

    printf("Stuffed Frame: %s\n",stuffed);

    for(i=1; stuffed[i]!=FLAG;i++)
    {
        if(stuffed[i]==ESC) i++;
        destuffed[k++] = stuffed[i];
    }

    destuffed[k] = '\0';

    printf("Destuffed Data: %s\n", destuffed);

    }

void bitStuffing()
{
    char data[100], stuffed[200], destuffed[100];
    int i,j=0,k=0, count=0;

    printf("Enter binary data for Bit Stuffing:");
    scanf("%s", data);

    for(i=0; data[i]!='\0';i++)
    {
        stuffed[j++]= data[i];

        if(data[i]=='1')
        {
            count++;
            if(count==5)
            {
                stuffed[j++] = '0';
                count=0;
            }
        }
        else count=0;
    }

    stuffed[j]='\0';
    printf("Stuffed Bits: %s\n", stuffed);

    count=0;

    for(i=0; stuffed[i]!='\0'; i++)
    {
        destuffed[k++] = stuffed[i];

        if(stuffed[i]=='1')
        {
            count++;

            if(count==5) 
            {
                i++;
                count=0;
            }

            else count=0;
        }
    }

    destuffed[k] ='\0';
    printf("Destuffed Bits: %s\n", destuffed);

}

int main()
{
    int choice;

    do{
        printf("\n---Data Link Lyaer Framing---\n");
        printf("1. Character Stuffing\n");
        printf("2. Bit Stuffing\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                characterStuffing();
                break;
            
            case 2:
                bitStuffing();
                break;
            
            case 3: 
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice!\n");
        }
        
    }while(choice!=3);

    return 0;
}