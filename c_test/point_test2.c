#include<stdio.h>

int main()
{
    int a[5]={1,2,3,4,5};
    printf("sizeof(int)=%ld sizeof(a)=%ld\n", sizeof(int), sizeof(a));

    int *p = a;
    //printf("*p++: %d\n", *p++); //1
    //printf("*(p++): %d\n", *(p++)); //1
    printf("*++p: %d\n", *++p); //2


    printf("a=%p\n", a);
    printf("&a[1]=%p\n", &a[1]);
    printf("&a[2]=%p\n", &a[2]);
    printf("a+2=%p\n", a+2);
    printf("*(a+2)=%d\n", *(a+2));

    printf("&a+1=%p\n", &a+1);
    printf("&a+2=%p\n", &a+2);
    return 0;
}
