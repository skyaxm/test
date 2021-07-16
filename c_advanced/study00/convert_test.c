#include<stdio.h>

int main()
{
    int a = 0x1FFFFFF3;
    printf("a = %d\n", a);

    short s = (short)a;
    printf("s = %d\n", s);

    int b = -5;
    unsigned int c = b;
    printf("c = %u\n", c);

    return 0;
}
