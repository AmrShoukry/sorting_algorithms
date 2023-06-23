#include "sort.h"

/**
 * counting_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */


void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int i;
	int sizee = (int) size;
	int *counting_arr;
	int *sorted_arr;

	for (i = 0; i < sizee; i++)
		if (array[i] > max)
			max = array[i];

	sorted_arr = malloc(sizee * sizeof(int));
	counting_arr = malloc((max + 1) * sizeof(int));

	for (i = 0; i < max + 1; i++)
		counting_arr[i] = 0;

	for (i = 0; i < sizee; i++)
		counting_arr[array[i]]++;

	for (i = 1; i < max + 1; i++)
		counting_arr[i] += counting_arr[i - 1];

	print_array(counting_arr, max + 1);


	for (i = sizee - 1; i >= 0; i--)
		sorted_arr[--counting_arr[array[i]]] = array[i];

	for (i = 0; i < sizee; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(counting_arr);
}
