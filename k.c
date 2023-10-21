#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a = 2 + 2, i = 0;
    int *array = malloc(a * sizeof(int));

    for ( i = 0; i < a; i++)
    {
        array[i] = i;
    }

    int k = 0;

    printf("%d \n", k);
    for ( i = 0; i < a; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
