#ifndef SHELLS_H
#define SHELLS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
extern char *fullpath;
extern char *buffer;
extern char *split[32];
extern char **env;
int print_env();
char **tokenize();
char **user_console(char **envp);
char **pathfinder(char *command);
#endif
