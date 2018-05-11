#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
    // create the socket
    int network_socket;
    // socket first is the domain, then the seocnd is the connet socket
    // last one is protacol 0 is default -- DCP
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify a address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET; // family of the server_address
    server_address.sin_port = htons(9002);//specify the port htons will convert the input to the port number that the complier will know
    server_address.sin_addr.s_addr = INADDR_ANY;//connect to 0.0.0.0

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    // cast to sockaddr, pass a pointer in it, last one is the size of the function
    // connect return a interger 0 is okay -1 is wrong

    //check if the connection is right
    if(connection_status == -1){
      printf("there was a error, something went wrong with the connection");
    }

    // receivt the data bac from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0); // 0 is the flag

    // print out the data we receive
    printf("The server send the data: %s\n", server_response);

    // close the connection_status
    close(network_socket);

    return 0;
}
