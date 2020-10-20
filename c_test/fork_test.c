#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int fork_child()
{
    int pid = fork();
    if(pid == -1) {
        printf("fork() failed\n");
        return 1;
    }
    if(pid != 0) {
        return 0;
    }

}

int main()
{
    int ret = fork_child();
    if(ret == 1) {
        printf("call the fork_child() failed\n");
    }
    printf("call the fork_child completed\n");
    while(1) {};
    return 0;
}
