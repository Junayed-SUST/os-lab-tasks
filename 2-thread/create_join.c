#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread is running!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    // Create thread
    if(pthread_create(&thread_id, NULL, thread_function, NULL)) {
        fprintf(stderr, "Thread creation failed\n");
        return 1;
    }
    
    // Wait for thread to finish
    if(pthread_join(thread_id, NULL)) {
        fprintf(stderr, "Thread join failed\n");
        return 2;
    }
    
    printf("Main thread completed\n");
    return 0;
}
