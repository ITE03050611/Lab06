#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>//inet_addr
int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[2000];
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not creat socket");
	}
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	if(connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	puts("Connected");
	message = "GET / HTTP/1.1\r\n\r\n";
	if(send(socket_desc , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");
	if(recv(socket_desc, server_reply , 2000 , 0)<0)
	{
		puts("recv failed");
	}
	puts ("Reply received\n");
	puts (server_reply);
	return 0;
}
