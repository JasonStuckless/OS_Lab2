// Jason Stuckless 100248154 - CRN 74025 - Operating Systems - Lab2 - Group 5
#include "myshell.h"

int tokenize (char* str, char tokens[][1024]) {
    // Initialize delimiter, counter, and token
    int count = 0;
    char *token = strtok(str, " ");
    // Iterate through tokens while increasing counter
    while (token) {
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void cd (char* pwd, char* new_dir) {
    // Variable to check if new directory entered is valid
    int check = chdir(new_dir);
    // Check for directory argument
    if (strcmp(new_dir, "") != 0) {
        // If new directory is valid
        if (check == 0) {
            getcwd(pwd, 1024);
        } else {
            printf("%s does not exist.\n", new_dir);
        }
    } else {
        printf("%s\n", pwd);
    }
}

void dir (char* dir_path) {
    struct dirent *dir_ent;
    DIR *dir_read = NULL;
    // Open directory
    if (strcmp(dir_path, "") == 0) { // If no directory argument present
        dir_read = opendir(".");
    } else {
        dir_read = opendir(dir_path);
    }
    // Print directory contents
    while ((dir_ent = readdir(dir_read)) != NULL) {
        printf("%s\n", dir_ent->d_name);
    }
    // Close directory
    closedir(dir_read);
}

void echo (char tokens[][1024], int num) {
    for (int i = 1; i < num; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

void help () {
    // Open readme file
    FILE *fp;
    char c;
    fp = fopen("readme", "r");
    // Read and print readme file contents
    c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }
    // Close readme file
    fclose(fp);
    printf("\n");
}

void pause_shell () {
    // Display pause message and wait for enter to be pressed
    printf("\nShell paused. (Press ENTER to continue.)\n");
    char entry = (char)getchar();
    while (entry != '\n') {
        entry = (char)getchar();
    }
}