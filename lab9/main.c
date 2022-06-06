#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>

int main(){
	const int is = 1;
	char msg[256];
	int read_bytes = 0;

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr, client;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &is, sizeof(int)); 
	bind(sock, (struct sockaddr*)&addr, sizeof(addr));
	listen(sock, 1337);
	int clientLen = sizeof(client);
	sock = accept(sock, (struct sockaddr*)&client, &clientLen);
	for (;;){
		memset(msg, 0, 256);
		read_bytes = recv(sock, msg, 256, 0);
		send(sock, msg, read_bytes, 0);
	}	
}
