#include "sort.h"
#include <stdio.h>

/**
 * swap - a function that swaps two integers
 * @a:  the first integer
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
 * heapify - a function heapify the array
 * @array: an array to heapify
 * @n: the size of the heap
 * @i: the index of the current node
 * @size: the size of the array.
 * Return: Nothing.
 */
void heapify(int *array, size_t n, size_t i, size_t size)
{
	size_t larg = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[larg])
	{
		larg = left;
	}
	if (right < n && array[right] > array[larg])
	{
		larg = right;
	}
	if (larg != i)
	{
		swap(&array[i], &array[larg]);
		print_array(array, size);
		heapify(array, n, larg, size);
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
	int x;

	if (size == 0)
		return;

	for (x = size / 2 - 1; x >= 0; x--)
	{
		heapify(array, size, x, size);
	}
	for (x = size - 1; x > 0; x--)
	{
		swap(&array[0], &array[x]);
		print_array(array, size);
		heapify(array, x, 0, size);
	}
}

