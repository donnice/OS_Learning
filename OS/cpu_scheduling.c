#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5

void *runner(void *param);

int main(int argc, char *argv[])
{
    int i, policy;
    pthread_t tid[NUM_THREADS];
    pthread_attr_t attr;

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* first inquire on the current scope */
    if(pthread_attr_getschedpolicy(&attr, &policy) != 0)
        fprintf(stderr, "Unable to get scheduling policy\n");
    else {
        if(policy == SCHED_OTHER)
            printf("PTHREAD_SCHED_OTHER");
        else if(policy == SCHED_RR)
            printf("PTHREAD_SCHED_RR\n");
        else if(policy == SCHED_FIFO)
            printf("PTHREAD_SCHED_FIFO\n");
    }

    /* set the scheduling policy - FIFO, RR or OTHER */
    if(pthread_attr_setschedpolicy(&attr, SCHED_FIFO) != 0)
        fprintf(stderr, "Unable to set policy!");

    /* create the threads */
    for(i = 0; i < NUM_THREADS; i++)
        pthread_create(&tid[i], &attr, runner, NULL);

    /* now join on each thread */
    for(i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);
}

void *runner(void *param) {
    printf("Xiao xiao\n");

    pthread_exit(0);
}