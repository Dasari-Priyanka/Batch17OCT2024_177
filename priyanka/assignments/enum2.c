#include <stdio.h>
#include <string.h>

// Define a typedef structure for the Putty server configuration
typedef struct {
    char hostname[100];       // Server hostname or IP address
    int port;                 // Port number for connection
    int timeout;              // Connection timeout in seconds
    char username[50];        // Username for authentication
    char password[50];        // Password for authentication
    char encryption[20];      // Type of encryption (e.g., AES, Blowfish)
    int keepAliveInterval;    // Keep-alive interval in seconds
} PuttyConfig;

// Function to display the configuration
void displayConfig(PuttyConfig config) {
    printf("Putty Server Configuration:\n");
    printf("Hostname: %s\n", config.hostname);
    printf("Port: %d\n", config.port);
    printf("Timeout: %d seconds\n", config.timeout);
    printf("Username: %s\n", config.username);
    printf("Password: %s\n", config.password);  // In a real-world app, do not print passwords
    printf("Encryption: %s\n", config.encryption);
    printf("Keep-Alive Interval: %d seconds\n", config.keepAliveInterval);
}

int main() {
    // Declare and initialize a structure variable with user-defined values
    PuttyConfig config = {
        "192.168.1.10",  // Hostname (example IP address)
        22,              // Port (default SSH port)
        30,              // Timeout (30 seconds)
        "admin",         // Username
        "admin123",      // Password
        "AES",           // Encryption (example: AES)
        60               // Keep-Alive Interval (60 seconds)
    };

    // Display the configuration
    displayConfig(config);

    return 0;
}

