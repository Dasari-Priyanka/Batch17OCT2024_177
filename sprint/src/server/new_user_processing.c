#include <stdio.h>              /* For standard input/output functions */
#include <string.h>             /* For string manipulation functions */
#include <gslist_util.h>        /* Custom header for checking existing users */
#include <add_to_reg_user_file.h>  /* Custom header for adding user to file */
int process_new_user(const char *username, const char *password);  /* Function to process new user registration */

int process_new_user(const char *username, const char *password) {
    if (is_user_exist(username)) {
        printf("User already exists!\n");
        return 0;
    }

    if (add_to_reg_user_file(username, password) == 0) {
        printf("User registered successfully.\n");
        return 1;
    } else {
        printf("Registration failed.\n");
        return -1;
    }
}

