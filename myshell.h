// Jason Stuckless 100248154 - CRN 74025 - Operating Systems - Lab2 - Group 5
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

// Functions from utility.c used in myshell.c
int tokenize(char* str, char tokens[][1024]);
void cd(char* pwd, char* new_dir);
void dir(char* dir_path);
void echo(char tokens[][1024], int num);
void help();
void pause_shell();