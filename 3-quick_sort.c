#include "sort.h"

/**
 * swap - a function for swap the element of the array
 * @a: element 1
 * @b: element 2
 * Return: nothing.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * l_part - a function that check and devide the array
 * @array: an array
 * @low: low value
 * @top: hight value
 * Return: new posiotn
 */
int l_part(int *array, int low, int top)
{
	int pivot = array[top];
	int i = low - 1, j;

	for (j = low; j <= top - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[top]);
	return (i + 1);
}

/**
 * quick_sort_recurs - a function for the recursive part
 * @array: the array
 * @size: the size of the array
 * @low: the low elemnt
 * @top: the hight element
 * Return: Nothing.
 */
void quick_sort_recurs(int *array, size_t size, int low, int top)
{
	if (low < top)
	{
		int partition_index = l_part(array, low, top);


		quick_sort_recurs(array, size, low, partition_index - 1);
		quick_sort_recurs(array, size, partition_index + 1, top);

		print_array(array, size);

	}
}

/**
 * quick_sort - a quiq sort function
 * @array: an array
 * @size: the size of an array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return;
	}
	quick_sort_recurs(array, size, 0, size - 1);
}

