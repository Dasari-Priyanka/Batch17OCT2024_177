#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if the domain is valid (.com or .edu)
int isValidDomain(char input[]) {
    // Find the last dot in the email string
    char *dot = strrchr(input, '.');
    
    if (dot == NULL) {
        return 0;  // No domain found
    }

    // Check if the domain is ".com" or ".edu"
    if (strcmp(dot, ".com") == 0 || strcmp(dot, ".edu") == 0) {
        return 1;
    }

    return 0;  // Invalid domain
}

// Function to extract the username from the email string
char *getuser(char input[]) {
    static char username[81];  // Static array to store the username
    char *at = strchr(input, '@');  // Find the '@' symbol
    
    if (at == NULL || at == input) {
        return NULL;  // No '@' found or empty username
    }
    
    // Copy the part before '@' to username
    strncpy(username, input, at - input);
    username[at - input] = '\0';  // Null-terminate the username
    
    return username;
}

// Function to extract the hostname from the email string
char *gethost(char input[]) {
    static char host[81];  // Static array to store the host
    char *at = strchr(input, '@');  // Find the '@' symbol
    char *dot = strchr(at + 1, '.');  // Find the first dot after '@'
    
    if (at == NULL || dot == NULL || dot == at + 1) {
        return NULL;  // Invalid input, no host part or empty host
    }
    
    // Copy the part between '@' and the first dot to host
    strncpy(host, at + 1, dot - (at + 1));
    host[dot - (at + 1)] = '\0';  // Null-terminate the host
    
    return host;
}

// Function to extract the domain from the email string
char *getdomain(char input[]) {
    static char domain[81];  // Static array to store the domain
    char *dot = strrchr(input, '.');  // Find the last dot in the string
    
    if (dot == NULL || !isValidDomain(input)) {
        return NULL;  // Invalid domain or no dot found
    }
    
    // Copy the part after the last dot to domain
    strcpy(domain, dot);  // Copy domain like ".com" or ".edu"
    
    return domain;
}

int main() {
    char email[81];
    
    // Get email input from user
    printf("Enter an email ID (max 80 characters): ");
    fgets(email, sizeof(email), stdin);
    
    // Remove newline character from input if present
    email[strcspn(email, "\n")] = '\0';
    
    // Extract username, host, and domain
    char *username = getuser(email);
    char *host = gethost(email);
    char *domain = getdomain(email);
    
    // Display results
    if (username != NULL) {
        printf("Username: %s\n", username);
    } else {
        printf("Invalid username\n");
    }

    if (host != NULL) {
        printf("Host: %s\n", host);
    } else {
        printf("Invalid host\n");
    }

    if (domain != NULL) {
        printf("Domain: %s\n", domain);
    } else {
        printf("Invalid domain\n");
    }
    
    return 0;
}

