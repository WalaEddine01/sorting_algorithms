#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void bubble_sort2(int array[], size_t n)
{
    size_t i = 0;
    int a, e = n;
    bool swap = false;
    do {
        swap = false;
        
        for (i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                a = array[i];
                array[i] = array[i + 1];
                array[i + 1] = a;
                swap = true;
                print_array(array, e);
            }
        }
        n--;
    } while (swap == true);
}

void insertion(int array[], size_t n)
{
    size_t i = 1, j;
    int a;

    while (i < n)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            a = array[j];
            array[j] = array[j - 1];
            array[j - 1] = a;
            j--;
            print_array(array, n);
        }
        i++;
    }
}

void insertion2(int array[], size_t n)
{
    size_t i = 1, j;
    int a;

    while (i < n)
    {
        a = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > a)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = a;
        i++;
    }
}
void selection_sort(int *array, size_t size)
{
    
}
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    insertion(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}