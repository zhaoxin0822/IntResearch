#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h> // convert net work server_address

int main(int argc, char *argv[]){ // specify the server we want to connect on

  char *address;
  char *protocol;
  address = argv[1];
  protocol = argv[2]; 

  int x = *protocol - '0';

  int client_socket;
  printf("the protocol is '%d'\n", protocol);
  printf("the protocol is '%d'\n", x);
  client_socket = socket(AF_INET, SOCK_STREAM, x);

  // specify a address
  struct sockaddr_in remote_address;
  remote_address.sin_family = AF_INET; // family of the server_address
  remote_address.sin_port = htons(80);//specify the port htons will convert the input to the port number that the complier will know
  inet_aton(address, &remote_address.sin_addr.s_addr);//convert string address tp address structure

  connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

  char request[] = "GET / HTTP/1.1\r\n\r\n";
  char response[4096];

  send(client_socket, request, sizeof(request), 0);
  recv(client_socket, &response, sizeof(response), 0);

  printf("response from the server: %s\n", response);
  close(client_socket);

  return 0;
}
