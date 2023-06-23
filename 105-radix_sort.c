#include "sort.h"

/**
 * pw - Get the math power of a number
 *
 * @number: The number to be powered
 * @exponent: The exponent that will be applied to the number
 *
 * Return: math.power
 */


int pw(int number, int exponent)
{
	int i = 0;
	int result = 1;

	while (i < exponent)
	{
		result = result * number;
		i++;
	}
	return (result);
}


/**
 * radix_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */


void radix_sort(int *array, size_t size)
{
	int max = array[0];
	int i, j, digits = 0;
	int sizee = (int) size;
	int *counting_arr, *sorted_arr;

	for (i = 0; i < sizee; i++)
		if (array[i] > max)
			max = array[i];

	while (max > 0)
	{
		max = max / 10;
		digits++;
	}

	sorted_arr = malloc(sizee * sizeof(int));
	counting_arr = malloc(10 * sizeof(int));

	for (j = 1; j <= digits; j++)
	{
		for (i = 0; i < 10; i++)
			counting_arr[i] = 0;

		for (i = 0; i < sizee; i++)
			counting_arr[array[i] % pw(10, j) / pw(10, j - 1)]++;

		for (i = 1; i < 10; i++)
			counting_arr[i] += counting_arr[i - 1];

		for (i = 9; i >= 0; i--)
			sorted_arr[--counting_arr[array[i] % pw(10, j) / pw(10, j - 1)]] = array[i];

		for (i = 0; i < sizee; i++)
			array[i] = sorted_arr[i];

		print_array(sorted_arr, size);
	}

	free(sorted_arr);
	free(counting_arr);
}
