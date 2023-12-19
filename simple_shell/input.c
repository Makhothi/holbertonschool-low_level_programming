#include "shells.h"

char *buffer;
char *split[32];
/**
 * tokenize - takes user input and splits it into tokens
 * Return: pointer to array of strings or NULL  if no input was passed
 */
char **tokenize()
{
char *tok = NULL;
int i, input = 0;
size_t bufsize = 32;
i = 0;
buffer = NULL;
input = getline(&buffer, &bufsize, stdin);
if (input == EOF)
{
if (isatty(STDIN_FILENO) != 0)
printf("\n");
free(buffer);
exit(0);
}
tok = strtok(buffer, " \n");
if (tok == NULL)
return (NULL);
if (strcmp(tok, "exit") == 0)
{
free(buffer);
exit(0);
}
if (strcmp(tok, "env") == 0)
{
print_env();
return (NULL);
}
split[i++] = tok;
while (tok != NULL && i < 32)
{
tok = strtok(NULL, " \n");
split[i++] = tok;
}
split[i - 1] = NULL;
return (split);
}
