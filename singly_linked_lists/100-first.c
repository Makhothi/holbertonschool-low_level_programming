#include <stdio.h>

/**
 * bmain - function executed before main
 * Return: no return.
 */

void __attribute__ ((constructor)) bmain()
{
    printf("(A tortoise, having pretty good sense of a hare's nature, challenges one to a race.)\n");
    return (0);
}
