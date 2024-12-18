#include <stdio.h>             /* For standard input/output functions */
#include <string.h>            /* For string manipulation functions */
#include <stdlib.h>            /* For standard library functions */
#include <unistd.h>            /* For system calls like close() */
#include <arpa/inet.h>         /* For functions like htons(), inet_addr(), sockaddr_in */
#include <sys/socket.h>        /* For socket-related functions */
int send_message(int socket, const char *message);    /* Sends a message through a socket */
int receive_message(int socket, char *buffer, size_t buffer_size); /* Receives a message from a socket */

int send_message(int socket, const char *message) {
    // Send the message to the socket. The length of the message is calculated using strlen().
    return send(socket, message, strlen(message), 0);
}
int receive_message(int socket, char *buffer, size_t buffer_size) {
    // Receive a message from the socket. The buffer will hold the received data.
    return recv(socket, buffer, buffer_size, 0);
}


