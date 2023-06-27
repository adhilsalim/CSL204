#include <stdio.h>

typedef struct
{
    int AT;  // Arrival Time
    int BT;  // Burst Time
    int TAT; // Turnaround Time
    int CT;  // Completion Time
    int PID; // Process ID
    int WT;  // Waiting Time
} Process;

void calculateTimes(int n, Process processes[])
{
    int completion = processes[0].AT + processes[0].BT;

    processes[0].CT = completion;
    processes[0].TAT = processes[0].CT - processes[0].AT;
    processes[0].WT = processes[0].TAT - processes[0].BT;

    for (int i = 1; i < n; i++)
    {
        if (completion < processes[i].AT)
            completion = processes[i].AT;

        completion += processes[i].BT;
        processes[i].CT = completion;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BT;
    }
}

void printGanttChart(int n, Process processes[])
{
    printf("\nGantt Chart:\n");
    printf("-----------\n");

    for (int i = 0; i < n; i++)
    {
        printf("| P%d ", processes[i].PID);
    }
    printf("|\n");

    printf("%d", processes[0].AT);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < processes[i - 1].BT; j++)
            printf(" ");
        printf("%d", processes[i].AT);
    }

    printf("\n\n");
}

int main()
{
    int n;
    float avgTurnaroundTime = 0, avgWaitingTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i);
        printf("Arrival time: ");
        scanf("%d", &processes[i].AT);
        printf("Burst time: ");
        scanf("%d", &processes[i].BT);
        processes[i].PID = i;
    }

    calculateTimes(n, processes);

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].PID, processes[i].AT, processes[i].BT, processes[i].TAT,
               processes[i].WT);
        avgTurnaroundTime += processes[i].TAT;
        avgWaitingTime += processes[i].WT;
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);

    printGanttChart(n, processes);

    return 0;
}
