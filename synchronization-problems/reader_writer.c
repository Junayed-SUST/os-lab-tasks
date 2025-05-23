#include <stdio.h>
#include <pthread.h>

int shared_data = 0;
int readers_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;

void *reader(void *arg) {
    int id = *(int *)arg;
    
    pthread_mutex_lock(&mutex);
    readers_count++;
    if (readers_count == 1) {
        pthread_mutex_lock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    
    printf("Reader %d reads: %d\n", id, shared_data);
    
    pthread_mutex_lock(&mutex);
    readers_count--;
    if (readers_count == 0) {
        pthread_mutex_unlock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    
    pthread_mutex_lock(&wrt);
    shared_data++;
    printf("Writer %d writes: %d\n", id, shared_data);
    pthread_mutex_unlock(&wrt);
    
    return NULL;
}

int main() {
    pthread_t readers[3], writers[2];
    int ids[5] = {1, 2, 3, 1, 2};
    
    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, &ids[i+3]);
    }
    
    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }
    
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }
    
    return 0;
}
