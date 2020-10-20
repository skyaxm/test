#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ret = system("/dev/null > test.txt ");
    printf("ret: %d\n", ret);

    return 0;
}
