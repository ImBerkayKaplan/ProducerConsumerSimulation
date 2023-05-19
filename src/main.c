#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include "buffer.h"

void *producer(void *param) {

    buffer_item rand;
    int id = *((int *) param);
    printf("\nProducer: %u, thread id = %lu", id, (unsigned long) pthread_self());
    printf("\nSeed for Producer %u: %lu\n", id, (unsigned long) pthread_self());
    while (1) {

        // Sleep for a random period of time
	unsigned int *seed = (unsigned int *) pthread_self();
	unsigned int sleepTime = rand_r(seed)%5 + 1;
	printf("\nProducer %u sleeps for %u", id, sleepTime);
        sleep(sleepTime);
        
        // Generate a random number
        rand = rand_r(seed);
        
	// Locking the mutex and decrementing empty by one
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);

	// Report error condition and perform the critical section
        insert_item((buffer_item) rand);
	printf("\n--->Producer %u produced item %u", id, rand);
	
	// Unlocking the mutex and incrementing full by one
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	
    }
}

void *consumer(void *param) {
    buffer_item rand;
    int id = *((int *) param);
    printf("\nConsumer: %u, thread id = %lu", id, (unsigned long) pthread_self());
    printf("\nSeed for Consumer %u: %lu\n", id, (unsigned long) pthread_self());
    while (1) {
	
	/* Sleep for a random period of time */
	unsigned int *seed = (unsigned int *) pthread_self();
	unsigned int sleepTime = rand_r(seed)%5 + 1;
	printf("\nConsumer %u sleeps for %u", id, sleepTime);
	sleep(sleepTime);

	// Locking the mutex and decrementing full by one
	sem_wait(&full);
	pthread_mutex_lock(&mutex);

	// Report error condition
        remove_item(&rand);
	printf("\n<---Consumer %u consumed item %u", id, rand);

	// Unlocking the mutex and incrementing empty by one
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
    }
}

//-----------------------------------------Main--------------------------------------------------

int main(int argc, char *argv[]){

    // Error checking for the number of arguments
    if(argc != 4){
	fprintf(stderr, "Please enter 3 arguments in total.\nThe first positive integer argument is the number of seconds the cycle should continue.\nThe second positive integer argument is the number of producers.\nThe third positive integer argument is the number of consumers.\nProgram is exiting.\n");
	exit(0);
    }

    /* 1. Get command line arguments argv[1], argv[2], argv[3] */
    int sleepInSec = atoi(argv[1]);
    int numOfProd = atoi(argv[2]);
    int numOfCons = atoi(argv[3]);

    /* 2. Initialize buffer, mutex, semaphores, and other global vars */
    arrayIndexRemove = 0;
    arrayIndexInsert = 0;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_attr_init(&attr);

    /* 3. Create producer thread(s) */
    pthread_t Pthread[numOfProd];
    int PthreadID[numOfProd];
    int i;
    for (i = 0; i < numOfProd;i++) {
        PthreadID[i] = i;
        pthread_create(&Pthread[i],&attr,producer, &PthreadID[i]);
    }

    /* 4. Create consumer thread(s) */
    pthread_t Cthread[numOfCons];
    int CthreadID[numOfCons];
    int j;
    for (j = 0; j < numOfCons;j++) {
        CthreadID[j] = j;
        pthread_create(&Cthread[j],&attr,consumer, &CthreadID[j]);
    }

    /* 5. Sleep */
    sleep (sleepInSec);

    /* 6. Release resources, e.g. destroy mutex and semaphores */
    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    /* 7. Exit */
    exit(0);
}