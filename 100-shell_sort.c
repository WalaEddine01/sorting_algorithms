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
	size_t gap, i, j;
	int temp;

	for (gap = size/2; gap > 0; gap /= 2)
	{
		for(i = gap; i < size; i += 1)
		{
			temp = array[i];
			
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];	
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

