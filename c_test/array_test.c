#include<stdio.h>

int main()
{
    int a[3];
    //a = {1, 2, 3};//error

    int b[3]={1, 2, 3};
    //a = b; //error

    int *p = b;
    printf("int b[3]: %p\n", b);
    printf("int *p = %p\n", p);

    return 0;
}
