#include <errno.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

int main()
{
    printf("Configuring local address...\n");

    // Define hints for getaddrinfo to configure the socket address.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // Use IPv4
    hints.ai_socktype = SOCK_STREAM; // Use TCP
    hints.ai_flags = AI_PASSIVE;     // Use local address

    struct addrinfo *bind_address;

    // Get address information for binding.
    if (getaddrinfo(NULL, "8080", &hints, &bind_address) != 0) {
        fprintf(stderr, "getaddrinfo() failed. (%d)\n", errno);
        return 1;
    }

    printf("Creating socket...\n");
    // Create a socket based on address information.
    int socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);

    if (socket_listen < 0) {
        fprintf(stderr, "socket() failed. (%d)\n", errno);
        return 1;
    }

    printf("Binding socket to local address...\n");
    // Bind the socket to a local address.
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed. (%d)\n", errno);
        return 1;
    }
    freeaddrinfo(bind_address);

    printf("Listening...\n");
    // Start listening on the socket.
    if (listen(socket_listen, 10) < 0) {
        fprintf(stderr, "listen() failed. (%d)\n", errno);
        return 1;
    }

    printf("Waiting for connection...\n");
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);

    // Accept incoming connection.
    int socket_client = accept(socket_listen, (struct sockaddr *)&client_address, &client_len);

    if (socket_client < 0) {
        fprintf(stderr, "accept() failed. (%d)\n", errno);
        return 1;
    }

    printf("Client is connected...\n");
    char address_buffer[100];

    // Get the client's address in a human-readable format.
    getnameinfo((struct sockaddr *)&client_address, client_len, address_buffer, sizeof(address_buffer), 0, 0, NI_NUMERICHOST);
    printf("Client Address: %s\n", address_buffer);

    printf("Reading request...\n");
    char request[1024];

    // Receive data from the client.
    int bytes_received = recv(socket_client, request, sizeof(request), 0);
    printf("Received %d bytes.\n", bytes_received);

    printf("Sending response...\n");
    const char *response = "HTTP/1.1 200 OK\r\n"
                           "Connection: close\r\n"
                           "Content-Type: text/plain\r\n\r\n"
                           "Local time: ";

    // Send the response to the client.
    int bytes_sent = send(socket_client, response, strlen(response), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

    time_t timer;
    time(&timer);
    char *time_msg = ctime(&timer);
    bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
    printf("Send %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

    printf("Closing connection...\n");
    close(socket_client);

    printf("Closing listening socket...\n");
    close(socket_listen);

    return 0;
}
