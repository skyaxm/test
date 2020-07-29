#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
    int ret = system(NULL);
    printf("ret: %d\n", ret);
    if(WIFEXITED(ret)) {
        int code = WEXITSTATUS(ret);
        perror("code");
        printf("code: %d\n", code);
    }else{
        perror("");
        printf("not exited\n");
    }
    return 0;
}
