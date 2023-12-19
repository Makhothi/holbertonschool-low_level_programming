#include "shells.h"

char **env;
/**
 * main - Shell, interactive or non interactive
 * @argc: argument count
 * @argv: argument vector
 * @envp: environmental variable
 * Return: 1 if command fails
 */

int main(int argc, char **argv, char **envp)
{
int i = 0;
char **args = NULL;
env = envp;
if (argc == 1)
{
user_console(envp);
}
if (argc > 1)
{
args = malloc(argc * sizeof(char *));
while (i < (argc - 1))
{
args[i] = argv[i + 1];
i++;
}
execve(args[0], args, envp);
printf("./shell: No such file or directory\n");
}
free(args);
return (0);
}
