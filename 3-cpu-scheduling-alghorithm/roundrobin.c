#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

void roundRobin(struct Process p[], int n, int quantum) {
    int currentTime = 0, completed = 0;
    
    while (completed != n) {
        bool progress = false;
        
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= currentTime) {
                progress = true;
                int execTime = (p[i].remaining > quantum) ? quantum : p[i].remaining;
                
                p[i].remaining -= execTime;
                currentTime += execTime;
                
                if (p[i].remaining == 0) {
                    p[i].completion = currentTime;
                    p[i].turnaround = p[i].completion - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    completed++;
                }
            }
        }
        
        if (!progress) currentTime++;
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 5}, {2, 1, 3}, {3, 2, 8}, {4, 3, 6}
    };
    int n = sizeof(processes)/sizeof(processes[0]);
    int quantum = 2;
    
    // Initialize remaining time
    for (int i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }
    
    roundRobin(processes, n, quantum);
    
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].turnaround, processes[i].waiting);
    }
    
    return 0;
}
