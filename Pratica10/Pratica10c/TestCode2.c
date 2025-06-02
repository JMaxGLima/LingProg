#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal handler function
void handle_signal(int sig) {
    if (sig == SIGABRT) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);  
    }
}

int main() {
    // Register the signal handler for SIGABRT
    if (signal(SIGABRT, handle_signal) == SIG_ERR) {
        perror("Error setting up signal handler");
        return EXIT_FAILURE;
    }

    // Attempt to open the file 
    FILE *file = fopen("C:\\Users\\20191en20196\\Documents\\LingProg\\LingProg\\Pratica10\\example.txt", "r");
    if (file == NULL) {
        // Raise the SIGABRT signal
        raise(SIGABRT);
    }

    // Your code here

    fclose(file);
    return EXIT_SUCCESS;
}

