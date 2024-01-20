#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed
void *myFunction(void *arg) {
    int i = 0;
    while (i < 5) {
        // Your code here
        printf("Executing...\n");

        // Introduce a delay using usleep
        usleep(1000000); 
        i++; // 1 second
    }
    exit(0);
    return NULL;
}

int main() {
    pthread_t tid;

    // Create a thread for myFunction
    if (pthread_create(&tid, NULL, myFunction, NULL)) 
    {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }
    pthread_join(tid, NULL);
    // Main thread can continue doing other tasks or simply sleep
    while (1) {
        printf("Main thread doing something else...\n");
        sleep(2);
    }

    return 0;
}
