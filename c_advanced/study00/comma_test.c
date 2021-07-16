#include<stdio.h>

int main()
{
    int a1, b=2, c=7, d=5;

    a1 = (++b, c--, d+3);
    printf("a1 = %d\n", a1);

    a1 =  ++b, c--, d+3;
    printf("a1 = %d\n", a1);

    return 0;
}
