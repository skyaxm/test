#include<stdio.h>
#define rv(x) \
    (int)(\
    (((int)(x)&0x000000FF)<<24)|\
    (((int)(x)&0x0000FF00)<<8)|\
    (((int)(x)&0x00FF0000)>>8)|\
    (((int)(x)&0xFF000000)>>24))

int main()
{
    int a = 0xABCDEFDC;
    int b = rv(a);
    printf("%p\n", b);
    return 0;
}
