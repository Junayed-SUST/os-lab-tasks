#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    bool completed;
};

void sjf(struct Process p[], int n) {
    int currentTime = 0, completed = 0;
    
    while (completed != n) {
        int shortest = -1;
        int minBurst = 9999;
        
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival <= currentTime && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                shortest = i;
            }
        }
        
        if (shortest == -1) {
            currentTime++;
            continue;
        }
        
        p[shortest].completion = currentTime + p[shortest].burst;
        p[shortest].turnaround = p[shortest].completion - p[shortest].arrival;
        p[shortest].waiting = p[shortest].turnaround - p[shortest].burst;
        p[shortest].completed = true;
        currentTime = p[shortest].completion;
        completed++;
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 6}, {2, 2, 8}, {3, 5, 7}, {4, 1, 3}
    };
    int n = sizeof(processes)/sizeof(processes[0]);
    
    sjf(processes, n);
    
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].turnaround, processes[i].waiting);
    }
    
    return 0;
}
