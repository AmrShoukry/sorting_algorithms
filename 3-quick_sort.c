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
 * quick_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void quick_sort(int *array, size_t size)
{
	int low;
	int high;

	low = 0;
	high = size - 1;

	quick_sort_partition(array, size, low, high);
}


/**
 * quick_sort_partition - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @low: low index
 * @high: high index
 */


void quick_sort_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot, pointer1_value, fixed;
	size_t pointer1_index;
	size_t pointer2_index;
	size_t pivot_index;

	if (low >= high || high >= size)
		return;

	fixed = 0;
	pivot = array[high];
	pivot_index = high;
	pointer1_index = low;
	pointer2_index = low;

	for (pointer1_index = low; pointer1_index <= high; pointer1_index++)
	{
		pointer1_value = array[pointer1_index];

		if (pointer1_value > pivot && fixed == 0)
		{
			fixed = 1;
			pointer2_index = pointer1_index;
		}
		if (pointer1_value <= pivot && fixed == 1)
		{
			swap(&array[pointer1_index], &array[pointer2_index]);

			print_array(array, size);

			if (array[pointer2_index] == pivot)
				pivot_index = pointer2_index;

			pointer2_index++;
		}
	}
	quick_sort_partition(array, size, low, pivot_index - 1);
	quick_sort_partition(array, size, pivot_index + 1, high);
}
