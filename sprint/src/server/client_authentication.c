#include <stdio.h>                /* For standard input/output functions */
#include <string.h>               /* For string manipulation functions */
#include <client_authentication.h> /* Custom header for authentication logic */
#include <common_crypto.h>        /* Custom header for cryptographic operations */
#define REGISTER_FILE "registered_users.txt"  /* File that stores registered user credentials */
int authenticate_user(const char *username, const char *password);  /* Function to authenticate a user */

int authenticate_user(const char *username, const char *password) {
    // Open the registration file for reading.
    FILE *file = fopen(REGISTER_FILE, "r");
    if (!file) {
        perror("Unable to open registration file");  /* Print error if file cannot be opened */
        return -1;  /* Return -1 if file opening fails */
    }

    char stored_username[128], stored_password[128];
    char encrypted_password[128];

    // Encrypt the provided password to compare with the stored encrypted password.
    encrypt(password, encrypted_password);

    // Loop through the registration file to check for matching credentials.
    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        // Compare the provided username and encrypted password with stored ones.
        if (strcmp(stored_username, username) == 0 && strcmp(stored_password, encrypted_password) == 0) {
            fclose(file);  /* Close the file after successful authentication */
            return 1;  /* Authentication successful */
        }
    }

    fclose(file);  /* Close the file if authentication fails */
    return 0;  /* Authentication failed */
}

