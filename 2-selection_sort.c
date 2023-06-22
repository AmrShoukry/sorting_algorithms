#include "sort.h"

/**
 * selection_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */


void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t j_index;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				j_index = j;
				min = array[j];
			}
		}

		if (min != array[i])
		{
			array[i] = array[i] + array[j_index];
			array[j_index] = array[i] - array[j_index];
			array[i] = array[i] - array[j_index];

			print_array(array, size);
		}
	}

}
