#include <stdio.h>            /* For standard input/output functions */
#include <stdarg.h>           /* For handling variable arguments in functions */
#define LOG_FILE "server_log.txt"  /* The log file where messages will be recorded */
void log_server_report(const char *level, const char *message, ...);  /* Logs a message to the server log file */

void log_server_report(const char *level, const char *message, ...) {
    /*Open the log file in append mode; if it cannot be opened, print an error message.*/
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Unable to open log file");  /* Print error message if log file cannot be opened */
        return;  /* Exit the function if file open fails */
    }

    va_list args;  /* Declare a variable to hold the arguments for the message */
    va_start(args, message);  /* Initialize the va_list with the first argument after 'message' */

    fprintf(log_file, "[%s] ", level);

    /* Use vfprintf to handle the formatted message with the optional arguments. */
    vfprintf(log_file, message, args);

    /*Add a newline at the end of the log message for better formatting.*/
    fprintf(log_file, "\n");

    va_end(args);  /* Clean up the va_list */

    fclose(log_file);  /* Close the log file after writing the message */
}

