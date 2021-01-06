#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void func(int a)
{
    static char *p1 = "hello!";
    printf("sizeof(*p1)=%ld sizeof(p1)=%ld\n", sizeof(*p1), sizeof(p1));
    const char *p2 = "hello!";
    printf("sizeof(*p2)=%ld sizeof(p2)=%ld\n", sizeof(*p2), sizeof(p2));
    char A1[8]="hello!!!";
    printf("sizeof(A1)=%ld sizeof(&A1[0])=%ld sizeof(&A1[1])=%ld\n",
            sizeof(A1), sizeof(&A1[0]), sizeof(&A1[1]));
    printf("A1=%p &A1[0]=%p &A1[1]=%p\n", A1, &A1[0], &A1[1]);
    const char A2[8]="hello!";
    printf("sizeof(A2)=%ld sizeof(&A2[0])=%ld sizeof(&A2[1])=%ld\n",
            sizeof(A2), sizeof(&A2[0]), sizeof(&A2[1]));
    volatile char *p3=&A1[7];
    printf("sizeof(*p3)=%ld sizeof(p3)=%ld\n", sizeof(*p3), sizeof(p3));
    *p3='\0';
    //A1[6]='a';
    printf("sizeof(A1)=%ld strlen(A1)=%ld\n", sizeof(A1), strlen(A1));
    printf("A1=%s\n", A1);
}

int main()
{
    func(1);
    return 0;
}
