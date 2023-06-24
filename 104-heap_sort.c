#include "sort.h"

/**
 * get_max - Prints an array of integers
 *
 * @num1: First number
 * @num2: Second number
 *
 * Return: a pointer to max_node
 */


int *get_max(int *num1, int *num2)
{
	int *max = num1;

	if (*num2 > *max)
		max = num2;

	return (max);
}

/**
 * swap - Prints an array of integers
 *
 * @num1: First number
 * @num2: Second number
 */

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



/**
 * heapify - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @initial_start: will the heapify be a bottom_up or a top_down approach
 * @counter: how many sorted elements
 */


void heapify(int *array, size_t size, int initial_start, int counter)
{
	int i;
	int *max;
	int sizee = (int) size;
	int temp;
	int temp2;

	for (i = initial_start; i >= 0; i--)
	{
		temp = i;
		while (2 * i + 1 < sizee)
		{
			if (2 * i + 2 < sizee)
				max = get_max(&array[2 * i + 1], &array[2 * i + 2]);
			else
				max = &array[2 * i + 1];

			if (array[i] < *max)
			{
				if (*max == array[2 * i + 1])
					temp2 = 2 * i + 1;
				else
					temp2 = 2 * i + 2;
				swap(&array[i], max);
				print_array(array, size + counter);
				i = temp2;
			}
			else
				break;
		}
		i = temp;
	}
}


/**
 * heap_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void heap_sort(int *array, size_t size)
{
	int counter = 0;
	int sizee = (int) size;
	int i;

	heapify(array, size, size - 1, 0);

	for (i = 0; i < sizee - 1; i++)
	{
		swap(&array[0], &array[sizee - 1 - counter++]);
		print_array(array, size);
		heapify(array, size - counter, 0, counter);
	}
}
