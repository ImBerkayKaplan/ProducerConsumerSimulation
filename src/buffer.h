#include <pthread.h>
#include <semaphore.h>

#ifndef BUFFER_H_   /* Include guard */
#define BUFFER_H_

typedef int buffer_item;
#define BUFFER_SIZE 5
int arrayIndexInsert;
int arrayIndexRemove;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
pthread_attr_t attr;

int insert_item(buffer_item item);
int remove_item(buffer_item *item);

#endif
