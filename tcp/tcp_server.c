#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
  char server_message[256] = "you have reach the server";
  // create a socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define address structure
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY; // any IP address on local machine

  // bind the socket to the specified IP and sin_port
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  listen(server_socket, 5);

  int client_socket;
  // accept connection
  client_socket = accept(server_socket, NULL, NULL);

  send(client_socket, server_message, sizeof(server_message), 0);

  // close the connection
  close(server_socket);
  return 0;
}
