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
			swap(&array[i], &array[j_index]);

			print_array(array, size);
		}
	}

}
