#include "sort.h"

void bitonic_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    size_t i, j;
    for (i = 2; i <= size; i *= 2) {
        for (j = 0; j < size; j += i) {
            size_t start = j;
            size_t mid = j + i / 2;
            size_t end = j + i;
            size_t k;

            printf("Merging [%zu/%zu] (UP):\n", i, size);

            for (k = start; k < end / 2; k++) {
                printf("%d, ", array[k]);
            }

            printf("\n");

            for (k = end / 2; k < end; k++) {
                printf("%d", array[k]);
                if (k != end - 1) {
                    printf(", ");
                }
            }

            printf("\n\n");

            for (k = start; k < mid; k++) {
                if (array[k] > array[k + i / 2]) {
                    int temp = array[k];
                    array[k] = array[k + i / 2];
                    array[k + i / 2] = temp;
                }
            }
        }
    }
}
