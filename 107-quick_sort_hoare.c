/**
 * swap - swaps two numbers
 * @one: the first int
 * @two: the second int
 */
void swap(int *one, int *two)
{
	int temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

/**
 * partition - partitions the array
 * @arr: the array
 * @low: the smallest index
 * @high: the highest index
 * Return: idx
 */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high - 1];
	int i = low - 1;
	int j = high + 1;

	while (1) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		swap(&arr[i], &arr[j]);
	}
}

/**
 * quickSort - the recursive call
 * @arr: the array
 * @low: the smallest index
 * @high: the highest index
 */
void quickSort(int arr[], int low, int high)
{
	int partitionIndex;

	if (low < high) {
		partitionIndex = partition(arr, low, high);

		quickSort(arr, low, partitionIndex);

		quickSort(arr, partitionIndex + 1, high);
	}
}

/**
 * printArray - prints the array
 * @arr: the array
 * @n: the size of the array
 */
void printArray(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		write(1, arr[i], 1);
	write(1, '\n', 1);
}
