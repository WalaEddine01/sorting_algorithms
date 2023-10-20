#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array that we have to sort
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, a = 0, k = 0;
	int tmp = 0;

	for (i = 0; i < size - 1; i++)
	{
		a = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				a = 1;
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
					else
						printf("\n");
				}
			}
		}
		if (a == 0)
			break;
	}
}
