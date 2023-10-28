#include "sort.h"

/**
 * swap - a function that swaps two integers
 * @a: the first integer
 * @b: the second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * siftDown - a function that performs the
 * sift-down operation in the heap sort algorithm.
 * @array: array to sort
 * @start: start index for sift-down
 * @end: end index for sift-down
 * @size: the size of the array
 * Return: Nothing.
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swapIdx = root;

		if (array[swapIdx] < array[child])
		{
			swapIdx = child;
		}

		if (child + 1 <= end && array[swapIdx] < array[child + 1])
		{
			swapIdx = child + 1;
		}

		if (swapIdx == root)
		{
			return;
		}
		else
		{
			swap(&array[root], &array[swapIdx]);
			print_array(array, size);
			root = swapIdx;
		}
	}
}

/**
 * heap_sort - a function that sorts an array of
 * integers in ascending
 * order using the Heap sort algorithm
 * @array: an array to sort
 * @size: the size of the array
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int start, end;

	if (size == 0)
	{
		return;
	}

	for (start = (size - 2) / 2; start >= 0; start--)
	{
		siftDown(array, start, size - 1, size);
	}

	for (end = size - 1; end > 0; end--)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		siftDown(array, 0, end - 1, size);
	}
}

