#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13};
    int array2[] = {};
    int array3[] = {2};
    int array4[] = {3, 3, 2};

    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    printf("-------\n");
    n = sizeof(array2) / sizeof(array2[0]);
    print_array(array2, n);
    printf("\n");
    selection_sort(array2, n);
    printf("\n");
    print_array(array2, n);
printf("-------\n");
    n = sizeof(array3) / sizeof(array3[0]);
    print_array(array3, n);
    printf("\n");
    selection_sort(array3, n);
    printf("\n");
    print_array(array3, n);
printf("-------\n");
    n = sizeof(array4) / sizeof(array4[0]);
    print_array(array4, n);
    printf("\n");
    selection_sort(array4, n);
    printf("\n");
    print_array(array4, n);
    return (0);
}
