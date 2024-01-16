#include "sort.h"

/**
 * swap_nodes - Function that swap two nodes
 *
 * @head: double pointer to the head of a doubly linked list.
 * @node: pointer to the current node
 * @next_node: current next node
 *
 * Return: Nothing.
 */

void swap_nodes(listint_t **head, listint_t *node, listint_t *next_node)
{
	listint_t *prev_node = NULL;

	prev_node = node->prev;
	prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
	node->prev = prev_node->prev;
	node->prev = prev_node->prev;
	if (prev_node->prev == NULL)
		*head = node;
	prev_node->prev = node;
	node->next = prev_node;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: double pointer to a doubly linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next_node = NULL, *prev_node = NULL;

	if (list == NULL || *list == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		next_node = node->next;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			prev_node = node->prev;
			prev_node->next = node->next;
			if (node->next != NULL)
				node->next->prev = node->prev;
			node->next = prev_node;
			node->prev = prev_node->prev;
			prev_node->prev = node;
			if (node->prev == NULL)
				*list = node;
			else
				node->prev->next = node;
			print_list(*list);
		}
		node = next_node;
	}
}
