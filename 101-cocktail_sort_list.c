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
 * cocktail_sort_list - Prints an array of integers
 *
 * @list: The linkedlist to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node = *list;
	int direction = 1;
	int swaps;

	while (node != NULL)
	{
		if (direction == 1)
		{
			if (node->next == NULL)
			{
				direction = -1;

				if (swaps == 0)
					break;
				swaps = 0;
			}
			else
			{
				if (node->n > node->next->n)
				{
					swaps++;
					swap_adjacent(list, node, node->next);
					print_list(*list);
				}
				else
					node = node->next;
			}

		}
		if (direction == -1)
		{
			if (node->prev == NULL)
			{
				direction = 1;

				if (swaps == 0)
					break;
				swaps = 0;
			}

			else
			{
				if (node->n < node->prev->n)
				{
					swaps++;
					swap_adjacent(list, node->prev, node);
					print_list(*list);
				}
				else
					node = node->prev;
			}
		}
	}
	
}
