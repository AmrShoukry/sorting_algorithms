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
 * merge - Prints an array of integers
 *
 * @arr: The array to be sorted
 * @org_size: Real Number of elements in @array
 * @size: Current Number of elements in divided @array
 * @low: starting position
 * @dir: up or down (increasing or decreasing)
 * @r: whether it's recursive or not
 */

void merge(int *arr, size_t org_size, size_t size, size_t low, int dir, int r)
{
	size_t i;
	char *arrow;

	if (size < 2)
		return;

	if (dir == 1)
		arrow = "UP";
	else
		arrow = "DOWN";

	for (i = low; i < low + size / 2; i++)
		if ((dir == (arr[i] > arr[i + size / 2])))
			swap(&arr[i], &arr[i + size / 2]);

	merge(arr, org_size, size / 2, low, dir, 1);
	merge(arr, org_size, size / 2, low + size / 2, dir, 1);


	if (r == 0)
	{
		printf("Result [%li/%li] (%s)\n", size, org_size, arrow);
		print_array(arr + low, size);
	}

}

/**
 * divide - Prints an array of integers
 *
 * @arr: The array to be sorted
 * @org_size: Real Number of elements in @array
 * @size: Current Number of elements in divided @array
 * @low_index: starting position
 * @dir: up or down (increasing or decreasing)
 */


void divide(int *arr, size_t org_size, size_t size, size_t low_index, int dir)
{
	char *arrow;

	if (size < 2)
		return;

	if (dir == 1)
		arrow = "UP";
	else
		arrow = "DOWN";

	printf("Merging [%li/%li] (%s):\n", size, org_size, arrow);
	print_array(arr + low_index, size);

	divide(arr, org_size, size / 2, low_index, 1);
	divide(arr, org_size, size / 2, low_index + size / 2, 0);
	merge(arr, org_size, size, low_index, dir, 0);
}

/**
 * bitonic_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void bitonic_sort(int *array, size_t size)
{
	divide(array, size, size, 0, 1);
}
