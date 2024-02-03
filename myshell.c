// Jason Stuckless 100248154 - CRN 74025 - Operating Systems - Lab2 - Group 5
#include "myshell.h"

int main (int argc, char *argv[]) {
    // Initialize arrays and variables
    char pwd[1024] = {0};
    char myshell[1024] = {0};
    char buffer[1024] = {0};
    char tokens[32][1024] = {0};
    char command[1024] = {0};
    int num_tokens = 0;

    // For using batch file
    FILE* fp = NULL;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Batch file cannot be opened.\n");
            return EXIT_FAILURE;
        }
    } else { // If not using batch file
        fp = stdin;
    }

    // Obtain environment variables
    getcwd(pwd, 1024);
    strcpy(myshell, getenv("SHELL"));

    // Welcome message
    printf("\n*** Simple Shell *** (type 'help' for available commmands)\n\n %s$ ", pwd);

    // Running loop
    while (fgets(buffer, 1024, fp)) {
        // Separate batch or input into tokens
        int i = 0;
        while (buffer[i] != '\n'){
            i++;
        }
        buffer[i] = '\0';
        num_tokens = tokenize(buffer, tokens);
        strcpy(command, tokens[0]);

        // If statement to cover all read commands
        if (strcmp(command, "cd") == 0) { // Change directory
            cd(pwd, tokens[1]);
        } else if (strcmp(command, "clr") == 0) { // Clear screen
            system("clear");
        } else if (strcmp(command, "dir") == 0) { // List directory
            dir(tokens[1]);
        } else if (strcmp(command, "environ") == 0) { // List environment strings
            printf("CWD: %s\nShell: %s\n", pwd, myshell);
        } else if (strcmp(command, "echo") == 0) { // Display text in terminal
            echo(tokens, num_tokens);
        } else if (strcmp(command, "help") == 0) { // Displays help menu
            help();
        } else if (strcmp(command, "pause") == 0) { // Pause the shell
            pause_shell();
        } else if (strcmp(command, "quit") == 0) { // Quit the shell
            return EXIT_SUCCESS;
        } else { // Invalid command
            printf("Invalid command, type 'help' for list of valid commands in readme file.");
        }

        // Print directory before command line
        printf("%s$ ", pwd);
    }
    return EXIT_SUCCESS;
}