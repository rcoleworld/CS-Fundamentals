#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 

#define NUM_THREADS 10

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

void *print_test(void *vargp);
int i = 0;
int main() {
    pthread_t *thread_group = malloc(sizeof(pthread_t) * NUM_THREADS);

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_group[i], NULL, print_test, NULL);
    }
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_group[i], NULL);
    }
}

void *print_test(void *vargp){
    for(;;) {
        pthread_mutex_lock(&mutex); 
        if(i >= 100){
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        ++i;

        printf("%d\n", i);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
