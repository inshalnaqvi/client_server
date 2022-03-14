#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<arpa/inet.h>



int main(int argc, char const *argv[])
{
	int new_socket, C;
	int server_socket = socket(AF_INET, SOCK_STREAM,0);
	struct sockaddr_in server;


	if(server_socket == -1)
	{
		printf("Could not create socket for server\n");
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8000 );

	if( bind(server_socket,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
	    puts("bind failed");
	}
	puts("bind done");

	listen(server_socket,3);
	puts("Waiting for incoming connections");


	while(1)
	{

	C =  sizeof(struct sockaddr_in);
	new_socket = accept(server_socket, NULL, NULL);
    if (new_socket<0)
    {
        perror("accept failed");
    }

    puts("Connection accepted");

    send(new_socket,"hello",6,0);
	}

	return 0;
}
