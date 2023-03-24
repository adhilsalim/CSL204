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

void sort(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrivalTime > p[j + 1].arrivalTime)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void print(process p[], int n)
{
    printf("Process ID\tArrival Time\tBurst Time");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d", p[i].processId, p[i].arrivalTime, p[i].burstTime);
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
    sort(p, n);
    print(p, n);
}