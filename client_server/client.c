#include <sys/types.h>        
#include <sys/socket.h>
#include <stdio.h>
#include<arpa/inet.h>



int main(int argc, char const *argv[])
{
	
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server;



	if(client_socket == -1)
	{
		printf("Could not create socket\n");
	}

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8000);

	
	if(connect(client_socket, (struct sockaddr *) &server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("connected");


	char buffer[10];

	ssize_t recieved = recv(client_socket,buffer,10,0);
	printf("%s\n",buffer);

	return 0;
}