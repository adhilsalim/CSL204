#include <stdio.h>

typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    ;
    int completionTime;
} process;

void getProcessDetails(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the id of process: ");
        scanf("%d", &p[i].processId);

        printf("Enter the arrival time of process: ");
        scanf("%d", &p[i].arrivalTime);

        printf("Enter the burst time of process: ");
        scanf("%d", &p[i].burstTime);
    }
}

void main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    process p[n];

    printf("Enter the process details: ");
    getProcessDetails(p, n);
}