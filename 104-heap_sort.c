#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    
    *a = *b;
    *b = temp;
}

/**
 * heapify - Heapify the array
 * @array: Array to heapify
 * @n: Size of the heap
 * @i: Index of the current node
 */
void heapify(int *array, size_t n, size_t i, size_t size) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, n, largest, size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size) {
    int i;

	if (size == 0)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}

