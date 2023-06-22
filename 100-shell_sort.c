#include "sort.h"

/**
 * swap - Prints an array of integers
 *
 * @num1: First Number
 * @num2: Second Number
 */

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


/**
 * shell_sort - Prints an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int pointer1;
	int pointer1_temp;
	int pointer2;
	int sizee = (int)size;

	while (gap < sizee)
		gap = gap * 3 + 1;

	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (pointer1 = 0; pointer1 < sizee; pointer1++)
		{
			pointer2 = pointer1 + gap;
			if (pointer2 < sizee && array[pointer1] > array[pointer2])
			{
				swap(&array[pointer1], &array[pointer2]);

				pointer1_temp = pointer1 - gap;
				while (pointer1_temp >= 0)
				{
					pointer2 -= gap;
					if (array[pointer1_temp] > array[pointer2])
					{
						swap(&array[pointer1_temp], &array[pointer2]);

						pointer1_temp -= gap;
					}
					else
						break;
				}
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
