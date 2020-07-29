#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pthread_mutex_t *pm_mutex = NULL;
    pthread_mutexattr_t mutex_shared_attr;
    int *p_shared = NULL;
    pid_t pid;

    pm_mutex = (pthread_mutex_t*)mmap(NULL, sizeof(pthread_mutex_t),
            PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    p_shared = (int*)mmap(NULL, sizeof(pthread_mutex_t),
            PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    *p_shared = 0;

    pthread_mutexattr_init(&mutex_shared_attr);
    pthread_mutexattr_setpshared(&mutex_shared_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(pm_mutex, &mutex_shared_attr);

    pid = fork();
    if(pid == 0) {
        pthread_mutex_lock(pm_mutex);
        int i;
        for(i = 0; i<5; ++i) {
            (*p_shared)++;
            sleep(1);
            printf("child process value is: %d\n", *p_shared);
        }
        pthread_mutex_unlock(pm_mutex);
        return 0;
    }else{
        sleep(1);
        int status, retpid;
        pthread_mutex_lock(pm_mutex);
        retpid = waitpid(pid, &status, 0); // wait for child process to end
        printf("retpid: %d\n", retpid);
        pthread_mutexattr_destroy(&mutex_shared_attr);
        pthread_mutex_destroy(pm_mutex);
        munmap(pm_mutex, sizeof(pthread_mutex_t));
        munmap(p_shared, sizeof(int));
        return 0;
    }
}
