#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to the head of the list
* @str: string to be duplicated and stored in the new node
*
* Return: the address of the new element, or NULL if it failed
*/

list_t *add_node_end(list_t **head, const char *str)
{
list_t *stash_node;
list_t *current_tequila;

if (head == NULL || str == NULL)
return (NULL);

stash_node = malloc(sizeof(list_t));
if (stash_node == NULL)
return (NULL);

stash_node->str = strdup(str);
if (stash_node->str == NULL)
{
free(stash_node);
return (NULL);
}
stash_node->len = strlen(str);
stash_node->next = NULL;

if (*head == NULL)
{
*head = stash_node;
}
else
{
current_tequila = *head;
while (current_tequila->next != NULL)
{
current_tequila = current_tequila->next;
}
current_tequila->next = stash_node;
}
return (stash_node);
}
