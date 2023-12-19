#include "shells.h"

/**
 * print_env - prints the environment
 * Return: zero
 */

int print_env()
{
int i = 0;
while (env[i])
{
printf("%s\n", env[i++]);
}
return (0);
}
