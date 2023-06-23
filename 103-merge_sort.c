#include "sort.h"

/**
 * get_middle_value - Prints an array of integers
 *
 * @low: low index
 * @high: high index
 *
 * Return: middle value
 */


int get_middle_value(int low, int high)
{
	int middle;

	if ((low + high) % 2 == 0)
		middle = (low + high) / 2 - 1;
	else
		middle = (low + high) / 2;

	return (middle);
}

/**
 * merge - Prints an array of integers
 *
 * @array: The array to be sorted
 * @copy_array: A copy of the original array
 * @low: low index
 * @middle: middle index
 * @high: high index
 */

void merge(int *array, int *copy_array, int low, int middle, int high)
{
	int counter = 0;
	int i = low;
	int j = middle + 1;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy_array + i, middle - low + 1);
	printf("[right]: ");
	print_array(copy_array + j, high - middle);

	while (i <= middle && j <= high)
	{
		if (array[i] > array[j])
			copy_array[counter++] = array[j++];

		if (array[i] <= array[j])
			copy_array[counter++] = array[i++];
	}

	while (i <= middle)
		copy_array[counter++] = array[i++];

	while (j <= high)
		copy_array[counter++] = array[j++];

	for (i = low; i <= high; i++)
		array[i] = copy_array[i - low];

	printf("[done]: ");
	print_array(copy_array, high - low + 1);
}

/**
 * divide - Prints an array of integers
 *
 * @array: The array to be sorted
 * @copy_array: A copy of the original array
 * @low: low index
 * @high: high index
 */

void divide(int *array, int *copy_array, int low, int high)
{
	int middle;

	if (low >= high)
		return;

	middle = get_middle_value(low, high);

	divide(array, copy_array, low, middle);
	divide(array, copy_array, middle + 1, high);

	merge(array, copy_array, low, middle, high);
}



/**
 * merge_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy_array = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		copy_array[i] = array[i];

	divide(array, copy_array, 0, size - 1);

	free(copy_array);
}
