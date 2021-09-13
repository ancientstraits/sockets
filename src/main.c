#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CONNECTIONS 10

int main(int argc, char** argv) {
	int server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sock == -1) {
		fprintf(stderr, "Socket creation failed\n");
		return 1;
	}

	struct sockaddr_in server_address = {
		.sin_addr = {
			.s_addr = htonl(INADDR_LOOPBACK),
		},
		.sin_port = htons(PORT),
		.sin_family = AF_INET,
	};

	if (bind(server_sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		fprintf(stderr, "Bind creation failed\n");
		return 1;
	}

	if (listen(server_sock, MAX_CONNECTIONS) < 0) {
		fprintf(stderr, "Listening failed\n");
		return 1;
	}

	const char text[] =
		"HTTP/1.1 200 OK\r\n\r\n"
		"<h1>Hello!</h1>\n"
	;

	int client_sock;
	while (1) {
		client_sock = accept(server_sock, NULL, NULL);
		// char pt[8000];
		// recv(client_sock, &pt, 8000, 0);
		// printf("\n%s\n", pt);
		send(client_sock, text, sizeof(text), 0);
		sleep(1);
	}

	close(client_sock);
	close(server_sock);

	return 0;
}
