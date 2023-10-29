#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bitonic_merge(int *arr, size_t n, size_t step, int dir) {
    if (step > 1) {
        size_t k = n / 2;
        for (size_t i = 0; i < k; i++) {
            if ((arr[i] > arr[i + k]) == dir) {
                int temp = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = temp;
                printf("Merging [%lu/%lu] (%s):\n", step, n, dir == 1 ? "UP" : "DOWN");
                print_array(arr, n);
            }
        }
        bitonic_merge(arr, k, step / 2, dir);
        bitonic_merge(arr + k, k, step / 2, dir);
    }
}

void bitonic_sort(int *array, size_t size) {
    for (size_t step = 2; step <= size; step *= 2) {
        for (size_t j = step / 2; j > 0; j /= 2) {
            for (size_t i = 0; i < size; i++) {
                size_t k = i ^ j;
                if (k > i) {
                    if ((i & step) == 0 && array[i] > array[k]) {
                        int temp = array[i];
                        array[i] = array[k];
                        array[k] = temp;
                        printf("Merging [%lu/%lu] (%s):\n", step, size, (array[i] > array[k]) ? "UP" : "DOWN");
                        print_array(array, size);
                    }
                }
            }
            bitonic_merge(array, size, step, 1);
            bitonic_merge(array, size, step, 0);
        }
    }
}

