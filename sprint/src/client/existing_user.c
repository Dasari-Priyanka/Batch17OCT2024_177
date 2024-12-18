// existing_user.c
#include <stdio.h>
#include <string.h>
#include <client_authentication.h>  // Ensure this header is included

// Authenticate an existing user by calling authenticate_user
int authenticate_existing_user(const char *username, const char *password) {
    return authenticate_user(username, password);  // Use the function from client_authentication.c
}

