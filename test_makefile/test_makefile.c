#include<stdio.h>
#include<stdlib.h>

int main()
{
#ifdef DEBUG
    printf("this is debug mode\n");
#else
    printf("this is release mode\n");
#endif
    return 0;
}
