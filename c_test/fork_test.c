#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<assert.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int global = 1;

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
    while(1){
        if(!global){
            sleep(3);
            continue;
        }else{
            if((pid = fork()) == 0){
                printf("execl the sshd\n");
                execl("./sshd_sim", "./sshd_sim", NULL);
                assert(0);
            }
            printf("\nsshd child end wait\n");
            int status;
            int retpid = waitpid(pid, &status, 0); // wait for child process to end
            if (retpid != pid) {
                if (retpid == -1) {
                    printf("errno(%d) [%s]\n", errno, strerror(errno));
                } else {
                    printf("pid != retpid (%d)\n", retpid);
                    if (WIFCONTINUED(status)) printf("WIFCONTINUED\n");
                    if (WIFEXITED(status)) printf("WIFEXITED\n");
                    if (WIFSIGNALED(status)) printf("WIFSIGNALED\n");
                    if (WIFSTOPPED(status)) printf("WIFSTOPPED\n");
                }
            }
            printf("\nsshd child have been destroyed\n");
        }
    }
}

int main()
{
    int ret = fork_child();
    if(ret == 1) {
        printf("call the fork_child() failed\n");
    }
    printf("call the fork_child completed\n");
    while(1) {
        sleep(30);
    };
    return 0;
}
