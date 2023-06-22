#include "sort.h"

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
	int temp;

	for (i = 0; i < size; i++)
	{
		swaps = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				
				swaps++;

				print_array(array, size);
			}
		}

		if (swaps == 0)
			break;
	}
}
