#include "sort.h"


/**
 * insertion_sort_list - Prints an array of integers
 *
 * @list: The linkedlist to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *node = *list;
	listint_t *temp;

	while (node != NULL)
	{
		temp = node->next;
		while (node->prev != NULL)
		{
			if (node->prev->n > node->n)
			{
				node->prev->next = node->next;
				if (node->next != NULL)
					node->next->prev = node->prev;

				node->next = node->prev;
				node->prev = node->next->prev;

				if (node->prev != NULL)
					node->prev->next = node;
				node->next->prev = node;

				if (node->prev == NULL)
					head = node;

				print_list(head);
			}
			else
				break;
		}
		node = temp;
	}
	*list = head;
}
