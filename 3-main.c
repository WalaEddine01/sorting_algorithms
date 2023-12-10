#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int part(int *array, int hight, int low)
{

}
void q(int *array, int hight, int low)
{
    int p = part(array, hight, low);
    q(array,hight, p-1 );
    q(array, p+1, low);
}
void quick_sort2(int *array, size_t size)
{
    q(array, size - 1, 0);
}
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
