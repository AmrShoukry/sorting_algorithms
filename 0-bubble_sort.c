#include "sort.h"

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
 * bubble_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t swaps;

	for (i = 0; i < size; i++)
	{
		swaps = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);

				swaps++;

				print_array(array, size);
			}
		}

		if (swaps == 0)
			break;
	}
}
