/*
- Client Program

1. Create socket
2. Specify server IP and port
3. Connect to server
4. Send Message
5. close socket
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<arpa/inet.h>

# define PORT 8080

int main()
{
    // Step 1: Create client socket
    int sock;

    sock= socket(AF_INET, SOCK_STREAM,0);

    if(sock<0)
    {
        printf("Socket creation failed\n");
        return 1;
    }

    // Step 2: Configure server address
    struct sockaddr_in server_addr;

    server_addr.sin_family= AF_INET;
    server_addr.sin_port= htons(PORT);

    inet_pton(AF_INET,
            "127.0.0.1",
            &server_addr.sin_addr);
    
    // Step 3: Connect to server
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
    {
        printf("Connection failed\n");
        return 1;
    }

    // Step 4: Send messages
    char message[]= "Hello from Talker(Client)!";

    send(sock,
         message,
         strlen(message)+1,
         0);
    printf("Message sent.\n");

    // Step 5: Close socket.
    close(sock);
    return 0;
}