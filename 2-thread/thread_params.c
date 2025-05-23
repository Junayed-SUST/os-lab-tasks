#include <stdio.h>
#include <pthread.h>

typedef struct {
    int value;
    char message[50];
} ThreadData;

void* thread_function(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    printf("Received value: %d\n", data->value);
    printf("Received message: %s\n", data->message);
    return NULL;
}

int main() {
    pthread_t thread_id;
    ThreadData data = {42, "Hello from main thread"};
    
    pthread_create(&thread_id, NULL, thread_function, &data);
    pthread_join(thread_id, NULL);
    
    return 0;
}
