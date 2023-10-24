#include "sort.h"

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

