#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
};

void calculateTimes(struct Process p[], int n) {
    p[0].completion = p[0].arrival + p[0].burst;
    p[0].turnaround = p[0].completion - p[0].arrival;
    p[0].waiting = 0;

    for (int i = 1; i < n; i++) {
        p[i].completion = p[i-1].completion + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

void printResults(struct Process p[], int n) {
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].turnaround, p[i].waiting);
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 5}, {2, 1, 3}, {3, 2, 8}, {4, 3, 6}
    };
    int n = sizeof(processes)/sizeof(processes[0]);

    calculateTimes(processes, n);
    printResults(processes, n);
    
    return 0;
}
