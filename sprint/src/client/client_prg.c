/*************************************************************************
*
*  FILE NAME    : client_prg.c
*
*  DESCRIPTION  : Client-side program for user registration, login, and communication
*
*  DATE      NAME    REFERENCE          REASON
*
*  17-DEC-24  Group3   Custom code     Initial Creation.
*
*  Copyright 2024, Developer Inc
*
**************************************************************************/

/***************************************************************************
*                       STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <get_login_details.h>
#include <client_authentication.h>
#include <log_client_report.h>

/***************************************************************************
*                       MACROS
***************************************************************************/
#define SERVER_ADDR "127.0.0.1"  /* Server IP address */
#define PORT 8080  /* Port number */

/***************************************************************************
*                       FUNCTION PROTOTYPES
***************************************************************************/
void display_menu(void);
void register_user(void);
int login_user(void);
void handle_communication(int sock);

/****************************************************************************
*       Function Name   : display_menu
*       Description     : Displays the main menu to the user
*       Returns         : Nothing
****************************************************************************/
void display_menu() {
    /* Displaying menu options */
    printf("\nMenu:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

/****************************************************************************
*       Function Name   : register_user
*       Description     : Handles the user registration process
*       Returns         : Nothing
****************************************************************************/
void register_user() {
    char username[128], password[128];

    /* Get login details from the user */
    get_login_details(username, password);

    /* Register the user (this should save the user data to a file) */
    if (register_new_user(username, password)) {
        printf("Registration successful!\n");
    } else {
        printf("Registration failed. Please try again.\n");
    }
}

/****************************************************************************
*       Function Name   : login_user
*       Description     : Handles the login process for existing users
*       Returns         : Returns 1 if authentication is successful, 0 otherwise
****************************************************************************/
int login_user() {
    char username[128], password[128];

    /* Get login details from the user */
    get_login_details(username, password);

    /* Authenticate the user */
    if (authenticate_user(username, password)) {
        printf("User authenticated\n");
        return 1;  /* Success */
    } else {
        printf("Authentication failed\n");
        return 0;  /* Failure */
    }
}

/****************************************************************************
*       Function Name   : handle_communication
*       Description     : Handles sending and receiving messages between the client and server
*       Returns         : Nothing
****************************************************************************/
void handle_communication(int sock) {
    char message[1024];
    while (1) {
        /* Ask the user to enter a message */
        printf("Enter message to send: ");
        fgets(message, sizeof(message), stdin);

        /* If the message is "exit", break the loop */
        if (strncmp(message, "exit", 4) == 0) {
            break;
        }

        /* Send message to the server */
        send_message(sock, message);

        /* Handle receiving messages from the server */
        handle_received_message(sock);
    }
}

/****************************************************************************
*       Function Name   : main
*       Description     : Main function to handle menu options and user actions
*       Returns         : Success or Failure
****************************************************************************/
int main() {
    int sock;
    struct sockaddr_in server_addr;
    int user_authenticated = 0;

    /* Display menu and process user input */
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        getchar();  /* To consume the newline character after entering the choice */

        switch (choice) {
            case 1:
                /* Register a new user */
                register_user();
                break;
            case 2:
                /* Try to log in */
                user_authenticated = login_user();
                if (user_authenticated) {
                    /* Proceed if login is successful */
                    /* Create socket and connect to the server */
                    sock = socket(AF_INET, SOCK_STREAM, 0);
                    if (sock == -1) {
                        perror("Socket creation failed");
                        exit(EXIT_FAILURE);
                    }

                    server_addr.sin_family = AF_INET;
                    server_addr.sin_port = htons(PORT);
                    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

                    /* Establish connection with the server */
                    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                        perror("Connection failed");
                        close(sock);
                        exit(EXIT_FAILURE);
                    }

                    /* Send login details to the server */
                    send_message(sock, "Login successful");

                    /* Handle communication (send and receive messages) */
                    handle_communication(sock);

                    close(sock);  /* Close the connection when done */
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);  /* Exit the program */
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

