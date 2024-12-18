#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
struct url {
    char *host;
    char *domain;
};
 
// Function to validate the URL (simple version)
int isValidURL(char *url) {
    // A simple check for "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        return 1;  // Valid URL
    }
    return 0;  // Invalid URL
}
 
// Function to extract the host name from the URL
char *gethost(char *url) {
    char *start = url;
    char *end;
    // Find the start of the host (skip "http://" or "https://")
    if (strncmp(start, "http://", 7) == 0) {
        start += 7;
    } else if (strncmp(start, "https://", 8) == 0) {
        start += 8;
    }
    // Find the end of the host name (where the first '/' or ':' appears)
    end = strchr(start, '/');
    if (end == NULL) {
        end = strchr(start, ':');
    }
    if (end == NULL) {
        end = start + strlen(start);  // No '/' or ':' found, take entire string
    }
    // Allocate memory for the host name and copy it
    int length = end - start;
    char *host = (char *)malloc((length + 1) * sizeof(char));
    if (host == NULL) {
        printf("Memory allocation failed for host.\n");
        exit(1);  // Exit if memory allocation fails
    }
    strncpy(host, start, length);
    host[length] = '\0';  // Null-terminate the string
    // Remove "www." if it's part of the host
    if (strncmp(host, "www.", 4) == 0) {
        memmove(host, host + 4, strlen(host) - 3);  // Shift the characters
    }
    // Now, only return the main part of the host (before the first dot)
    char *dot = strchr(host, '.');
    if (dot != NULL) {
        *dot = '\0';  // Null-terminate the string at the first dot
    }
    return host;
}
 
// Function to extract the domain name from the URL
char *getdomain(char *url) {
    char *start = url;
    char *end;
    // Find the start of the host (skip "http://" or "https://")
    if (strncmp(start, "http://", 7) == 0) {
        start += 7;
    } else if (strncmp(start, "https://", 8) == 0) {
        start += 8;
    }
    // Find the end of the host name (where the first '/' or ':' appears)
    end = strchr(start, '/');
    if (end == NULL) {
        end = strchr(start, ':');
    }
    if (end == NULL) {
        end = start + strlen(start);  // No '/' or ':' found, take entire string
    }
    // Extract the host (until the first '/')
    char *host = (char *)malloc((end - start + 1) * sizeof(char));
    if (host == NULL) {
        printf("Memory allocation failed for host.\n");
        exit(1);
    }
    strncpy(host, start, end - start);
    host[end - start] = '\0';  // Null-terminate the string
    // Extract the domain name (after the last dot '.')
    char *dot = strrchr(host, '.');
    if (dot == NULL) {
        free(host);  // Free host if no domain found
        return NULL;
    }
    // Allocate memory for the domain part
    char *domain = (char *)malloc(strlen(dot + 1) + 1);
    if (domain == NULL) {
        printf("Memory allocation failed for domain.\n");
        exit(1);
    }
    strcpy(domain, dot + 1);  // Copy everything after the dot
    free(host);  // Free the host memory as it's no longer needed
    return domain;
}
 
// Function to display the structure contents
void display(struct url *obj) {
    if (obj != NULL) {
        printf("Host: %s\n", obj->host);
        printf("Domain: %s\n", obj->domain);
    }
}
 
// Function to free the allocated memory
void free_memory(struct url *obj) {
    if (obj != NULL) {
        if (obj->host != NULL) {
            free(obj->host);
        }
        if (obj->domain != NULL) {
            free(obj->domain);
        }
    }
}
 
// Main function
int main() {
    char url[256];  // Buffer for the URL
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0';  // Remove newline character
    // Validate the URL
    if (!isValidURL(url)) {
        printf("Invalid URL format.\n");
        return 1;  // Exit if URL is not valid
    }
    // Allocate memory for the URL structure
    struct url *url_obj = (struct url *)malloc(sizeof(struct url));
    if (url_obj == NULL) {
        printf("Memory allocation failed for url structure.\n");
        return 1;
    }
    // Extract the host and domain
    url_obj->host = gethost(url);
    url_obj->domain = getdomain(url);
    // Display the structure contents
    display(url_obj);
    // Free the allocated memory
    free_memory(url_obj);
    free(url_obj);
    return 0;
}
