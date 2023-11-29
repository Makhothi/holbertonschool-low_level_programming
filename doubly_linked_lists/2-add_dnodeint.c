#include "lists.h"

/**
* add_dnodeint - Adds a new node at the beggining of a dlistint_t list.
* @head: pointer to the pointer of the head of the list.
* @n: interger to be stored in the stash node.
*
* Return: address of the new element, or NULL if it failed.
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *lebo_node;

lebo_node = malloc(sizeof(dlistint_t));

if (lebo_node == NULL)
return (NULL);
lebo_node->n = n;
lebo_node->prev = NULL;
lebo_node->next = *head;

if (*head != NULL)
(*head)->prev = lebo_node;
*head = lebo_node;
return (lebo_node);
}
