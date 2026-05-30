/*
- Listener program 

1. Create a socket
2. Bind it to a port
3. Listen for incoming connections
4. Accept client connection
5. Receive message
6. Display message
7. Close connection
*/

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>

#include<sys/socket.h>
#include<netinet/in.h>

#define PORT 8080

int main()
{
    // Step 1: Create Server socket
    int server_fd;
    server_fd = socket(AF_INET, SOCK_STREAM,0);

    if(server_fd<0)
    {
        printf("Socket creation failed/n");
        return 1;
    }

    // Step 2: Configure server address

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr= INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Step 3: Bind Socket to port

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)
    {
        printf("Bind failed\n");
        return 1;
    }

    //step 4: Listen for connections
    listen(server_fd,5);

    printf("Server listening on port %d..\n", PORT);

    //Step 5: Accept client connection
    int client_socket;

    client_socket = accept(server_fd, NULL, NULL);
    printf("Client connection.\n");

    //step 6: Receive message
    char buffer [1024];

    recv(client_socket,
        buffer,
        sizeof(buffer),
        0);
    
        printf("Message from client:%s\n",buffer);
    
    // Step 7: close sockets
    close(client_socket);
    close(server_fd);

    return 0;
}