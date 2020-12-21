#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *a = malloc(sizeof(int));
    *a = 1;

    int *b = malloc(sizeof(int));
    *b = 2;

    free(a);

    int *c = malloc(sizeof(int));
    *c = 3;

    printf("%d, %d, %d\n", *a, *b, *c);
}
