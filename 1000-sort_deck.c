#include "deck.h"


/**
 * string_length - Prints an array of integers
 *
 * @value: The text value that will be converted into an integer
 *
 * Return: The length of the string
 */


int string_length(const char *value)
{
	int i = 0;
	int counter = 0;

	while (value[i] != '\0')
	{
		counter++;
		i++;
	}

	return (counter);
}


/**
 * string_to_int - Prints an array of integers
 *
 * @value: The text value that will be converted into an integer
 *
 * Return: the integer value
 */

int string_to_int(const char *value)
{
	int i;
	int length;
	int sum = 0;

	if (value[0] == 65)
		return (0);

	if (value[0] == 75)
		return (20030803);

	length = string_length(value);

	for (i = 0; i < length; i++)
		sum += value[i];

	return (sum);
}

/**
 * insertion_sort_list - Prints an array of integers
 *
 * @list: The linkedlist to be sorted
 */

void insertion_sort_list(deck_node_t **list)
{
	deck_node_t *head = *list;
	deck_node_t *node = *list;
	deck_node_t *temp;
	int prev_val;
	int current_val;
	int prev_k;
	int cur_k;

	while (node != NULL)
	{
		temp = node->next;
		while (node->prev != NULL)
		{
			prev_val = string_to_int(node->prev->card->value);
			current_val = string_to_int(node->card->value);
			prev_k = node->prev->card->kind;
			cur_k = node->card->kind;

			if ((prev_k > cur_k) || (prev_k == cur_k && prev_val > current_val))
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
			}
			else
				break;
		}
		node = temp;
	}
	*list = head;
}




/**
 * sort_deck - Prints an array of integers
 *
 * @deck: The 52 cards
 */


void sort_deck(deck_node_t **deck)
{
	insertion_sort_list(deck);
}
