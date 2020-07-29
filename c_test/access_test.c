#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    int ret = access("/root/O-RAN/log/", F_OK);
    printf("ret: %d\n", ret);
    perror("ret");
    if(ret == -1) {
        mkdir("/root/O-RAN/log/", 0755);
    }
    return 0;
}
