#include "sort.h"

/**
 * swap_adjacent - Prints an array of integers
 *
 * @list: The linkedlist to be sorted
 * @n1: Previous Node
 * @n2: Current Node
 */

void swap_adjacent(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1 == NULL || n2 == NULL || n1 == n2 || n1->next != n2 || n2->prev != n1)
		return;

	if (n1->prev == NULL)
		*list = n2;

	n2->prev = n1->prev;
	if (n1->prev != NULL)
		n2->prev->next = n2;

	n1->next = n2->next;
	if (n2->next != NULL)
		n1->next->prev = n1;

	n1->prev = n2;
	n2->next = n1;
}


/**
 * apply - Prints an array of integers
 *
 * @direction: Forward or backward
 * @node: Current Node
 * @list: First Node
 * @swaps: number of switches
 *
 * Return: new_node
 */


listint_t *apply(int *direction, listint_t *node, listint_t **list, int *swaps)
{
	if (*direction == 1 && node->next == NULL)
	{
		*direction = -1;
		if (*swaps == 0)
			return (NULL);
		*swaps = 0;
	}

	else if (*direction == 1 && node->n > node->next->n)
	{
		(*swaps)++;
		swap_adjacent(list, node, node->next);
		print_list(*list);
	}

	else if (*direction == 1)
		node = node->next;

	if (*direction == -1 && node->prev == NULL)
	{
		*direction = 1;
		if (*swaps == 0)
			return (NULL);
		*swaps = 0;
	}

	else if (*direction == -1 && node->n < node->prev->n)
	{
		(*swaps)++;
		swap_adjacent(list, node->prev, node);
		print_list(*list);
	}

	else if (*direction == -1)
		node = node->prev;

	return (node);
}

/**
 * cocktail_sort_list - Prints an array of integers
 *
 * @list: The linkedlist to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node = *list;
	int direction = 1;
	int swaps = 0;

	while (node != NULL)
		node = apply(&direction, node, list, &swaps);

}
