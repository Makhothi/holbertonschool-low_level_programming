#include "lists.h"

/**
 * print_dlistint - Prints integers from doubly linked list
 * @h: Pointer to head of list
 *
 * Return: Number of nodes printed
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t numelem = 0;
	const dlistint_t *temp;

	temp = h;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		numelem++;
	}

	return (numelem);
}
