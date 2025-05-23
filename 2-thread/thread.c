#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    printf("Thread running! Argument: %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t tid;
    int arg = 42;
    
    pthread_create(&tid, NULL, task, &arg);
    pthread_join(tid, NULL);
    
    printf("Main thread exiting\n");
    return 0;
}
