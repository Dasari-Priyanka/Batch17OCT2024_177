/*************************************************************************
*
*  FILE NAME    : server_prg.c
*
*  DESCRIPTION  : A simple multi-client TCP server that handles client
*                 connections using threads.
*
*  DATE      NAME    REFERENCE          REASON
*
*  17-DEC-24  Group3    Initial Creation.  Created server to manage client
*                      connections with socket programming.
*
*  Copyright 2024, Your Company (Holdings) Ltd
*
**************************************************************************/
/* NOTE: This program demonstrates a simple server-client interaction.
   Error handling is included, but for production code, additional
   optimizations and improvements should be made. */

/***************************************************************************
*                       STANDARD HEADER FILES
***************************************************************************/
#include <sys/socket.h>      /* For socket functionality */
#include <netinet/in.h>      /* For sockaddr_in structure */
#include <arpa/inet.h>       /* For inet_pton() and other inet functions */
#include <unistd.h>          /* For close() system call */
#include <stdio.h>           /* For standard input/output functions */
#include <stdlib.h>          /* For standard library functions */
#include <string.h>          /* For string manipulation functions */
#include <pthread.h>         /* For multi-threading functionality */
#include <client_handler.h>  /* Custom header for handling client logic */
#include <log_server_report.h>  /* Custom header for logging server activity */
#include <client_authentication.h>  /* Custom header for authenticating clients */
#include <active_session.h>  /* Custom header for managing active sessions */
#include <broadcast_handler.h>  /* Custom header for broadcasting messages */

/***************************************************************************
*                       MACROS
***************************************************************************/
#define PORT 8080               /* Port number for the server to listen on */
#define MAX_CLIENTS 10          /* Maximum number of clients that can connect */

/***************************************************************************
*                       GLOBAL VARIABLES
***************************************************************************/
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;  /* Mutex for thread safety */
int clients[MAX_CLIENTS];  /* Array to hold active client sockets */

/***************************************************************************
*       Function Name   : main
*       Description     : Entry point for the server program.
*                          Initializes the server, listens for incoming
*                          connections, and handles clients using threads.
*       Returns         : 0 on successful execution, EXIT_FAILURE on errors.
****************************************************************************/

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept and handle clients
    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_t tid;
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Thread creation failed");
        }
    }

    close(server_fd);
    return 0;
}


