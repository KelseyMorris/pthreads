#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int counter = 0;//counter set to start at 0

void *print_hello_world(void *tid)
{
    // This function prints the thread's identifier and then exits
    printf("Hello World. Greetings from thread %d\n",tid);
    printf("%d\n", counter);
    counter ++;
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int num_threads = 4;//Default values asked for
    int num_iterations = 10000;//Default values asked for

    if (argc > 2 )
    {
        int num_threads = argc;
    }

    if (argv[1] != NULL)
    {
        int num_iterations = atoi(argv[1]);
    }
    pthread_t threads[num_threads];
    int status, i, j;
    for (j = 0; j < num_iterations; j++)
    {
            for(i=0;i < num_threads; i++)
            {
            printf("Main here. Creating thread %d\n", i);
            status = pthread_create(&threads[i],NULL,print_hello_world, (void*)i);

            if (status != 0){
                printf("Oops. pthread_create returned error code %d\n", status);
                exit(-1);
            }
        }
    }
    exit(NULL);
}