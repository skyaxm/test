#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int ret = remove("/root/log");
    printf("ret: %d\n", ret);
    return 0;
}
