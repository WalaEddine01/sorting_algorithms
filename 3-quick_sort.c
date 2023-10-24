#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order using
 * the quick sort algorithm
 * @array: the array that we have to sort
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
/**
 * quick_sort_recursive - helper function of quick_sort function
 * @array: the array that we have to sort
 * @left: The leftmost index of the array
 * @right: The rightmost index of the array
 * @size: the size of the array
 * Return: void
 */
void quick_sort_recursive(int *array, int left, int right, int size)
{
	int i, j, tmp;
	int pivot, a = 0;

	if (left >= right)
		return;
	pivot = array[right];
	i = left - 1;
	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			a = 1;
		}
	}

	if (a == 1)
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		a = 0;
		print_array(array, size);
	}

	quick_sort_recursive(array, left, i, size);
	quick_sort_recursive(array, i + 2, right, size);
}
