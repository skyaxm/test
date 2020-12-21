#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char str[] = "hello the world more efficient";
    char *start = str;
    char *pstr[10];
    int i = 0;
    int n = 5;
    int m = n;
    char buf[16];
    while(n--){
        sscanf(start, "%s", buf);
        int len = strlen(buf);
        char *ptmp = (char*)malloc(32);
        strcpy(ptmp, buf);
        pstr[i] = ptmp;
        printf("pstr[%d]: %s\n", i, pstr[i]);
        start += len+1;
        i++;
    }
    int j = 0;
    while(m--){
        free(pstr[j++]);
    }
    return 0;
}
