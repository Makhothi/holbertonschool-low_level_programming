#include "shells.h"

/**
 * user_console - launches user console for input
 * @envp: environmental variable
 * Return: array of tokens
 */

char **user_console(char **envp)
{
int status;
char **temp = NULL;
pid_t childcheck = 1;
while (1)
{
if (isatty(STDIN_FILENO))
printf("($) ");
temp = tokenize();
if (temp == NULL)
continue;
temp = pathfinder(split[0]);
if (temp != NULL)
{
childcheck = fork();
if (childcheck == 0)
{
execve(split[0], split, envp);
printf("./shell: No such file or directory\n");
exit(0);
}
wait(&status);
free(buffer);
free(fullpath);
}
}
return (split);
}
