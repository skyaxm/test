#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp = fopen("test.txt", "r");
    int a = fgetc(fp);
    printf("a: %d\n", a);
    return 0;
}
