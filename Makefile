server socket:server.c socket.c
	gcc -o server server.c
	gcc -o socket socket.c
server.o socket.o:server.c socket.c
	gcc -c server.c
	gcc -c socket.c
clean:
	rm*.o server socket
