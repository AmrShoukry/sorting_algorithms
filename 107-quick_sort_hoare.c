#include "sort.h"


/**
 * swap - Prints an array of integers
 *
 * @num1: Number1
 * @num2: Number2
 */

void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



/**
 * partition - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: size of the array
 * @left: low index
 * @right: high index
 *
 * Return: pivot_index
 */

int partition(int *array, size_t size, int left, int right)
{
	int pivot_index = right;
	int pivot = array[pivot_index];
	int i = left;
	int j = right;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);

			if (pivot_index == i)
			{
				pivot_index = j;
				pivot = array[pivot_index];
				i++;
			}
			else if (pivot_index == j)
			{
				pivot_index = i;
				pivot = array[pivot_index];
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
		if (i == j)
			break;
	}
	return (pivot_index);
}




/**
 * quick_sort_Hoare - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: size of the array
 * @left: low index
 * @right: high index
 */

void quick_sort_Hoare(int *array, size_t size, int left, int right)
{
	int pivot_index;

	if (left >= right)
		return;

	pivot_index = partition(array, size, left, right);

	quick_sort_Hoare(array, size, left, pivot_index - 1);
	quick_sort_Hoare(array, size, pivot_index + 1, right);
}



/**
 * quick_sort_hoare - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_Hoare(array, size, 0, size - 1);
}
