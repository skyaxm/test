#include<stdio.h>

int main()
{
    int a[3][2] = {(1,1), (2, 3), (4,5)};

    int i, j;
    for(i = 0; i<3; i++){
        for(j = 0; j<2; j++){
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}
