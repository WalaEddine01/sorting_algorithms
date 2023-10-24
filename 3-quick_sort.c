#include "sort.h"
<<<<<<< HEAD

void swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

int lomuto_partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (low < high)
	{
        	partition_index = lomuto_partition(array, low, high);
		print_array(array, size);
		quick_sort_recursive(array, size, low, partition_index - 1);
		quick_sort_recursive(array, size, partition_index + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return;
	}
	quick_sort_recursive(array, size, 0, size - 1);
}

=======
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
	int pivot;

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
		}
	}

	tmp = array[i + 1];
	array[i + 1] = array[right];
	array[right] = tmp;

	print_array(array, size);

	quick_sort_recursive(array, left, i, size);
	quick_sort_recursive(array, i + 2, right, size);
}
>>>>>>> 22a5c1a65540a3721eb534a3e0f6c75cea08703c
