#include<stdio.h>

double area(double r)
{
    return AERA(r);
}

void def()
{
    #define PI 3.1415926
    #define AERA(r) r*r*PI
}


int main()
{
    double r = area(5);
    printf("PI = %f\n", PI);
    printf("d = 5; a = %f\n", r);

    return 0;
}
