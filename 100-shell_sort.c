#include "sort.h"

/**
 * shell_sort - a function that sort an array using shell sort
 * algortithm, using the knuth sequence
 * @array: The array that we wanna sort
 * @size: the size of the array
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, temp;

	for (gap = size/2; gap > 0; gap /= 2)
	{
		for(i = gap; i < size; i += 1)
		{
			int temp = arr[i];
			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];	
			}
			arr[j] = temp;
		}
	}
	return (0);
}

