#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int turnaround;
    int waiting;
    bool completed;
};

void prioritySchedule(struct Process p[], int n) {
    int currentTime = 0, completed = 0;
    
    while (completed != n) {
        int highest = -1;
        int maxPriority = -1;
        
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival <= currentTime && 
                p[i].priority > maxPriority) {
                maxPriority = p[i].priority;
                highest = i;
            }
        }
        
        if (highest == -1) {
            currentTime++;
            continue;
        }
        
        p[highest].completion = currentTime + p[highest].burst;
        p[highest].turnaround = p[highest].completion - p[highest].arrival;
        p[highest].waiting = p[highest].turnaround - p[highest].burst;
        p[highest].completed = true;
        currentTime = p[highest].completion;
        completed++;
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 4, 2}, {2, 1, 3, 3}, {3, 2, 7, 1}, {4, 3, 5, 4}
    };
    int n = sizeof(processes)/sizeof(processes[0]);
    
    prioritySchedule(processes, n);
    
    printf("PID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].priority, processes[i].completion, 
               processes[i].turnaround, processes[i].waiting);
    }
    
    return 0;
}
