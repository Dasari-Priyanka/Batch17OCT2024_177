#include <string.h>

// Encrypt function (shifts each character by 1)
void encrypt(const char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + 1; // Shift each character by 1
    }
    output[strlen(input)] = '\0'; // Null-terminate the output
}

// Decrypt function (reverses the encryption, shifting each character back by 1)
void decrypt(const char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] - 1; // Shift each character back by 1
    }
    output[strlen(input)] = '\0'; // Null-terminate the output
}

