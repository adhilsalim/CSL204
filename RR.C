/*
 * Round Robin Scheduling Algorithm
 */

#include <stdio.h>

typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    int completionTime;
} process;

void printGanttChart(process[], int);
void getProcessDetails(process[], int);
void sort(process[], int);
void print(process[], int);
void calculateCompletionTime(process[], int);
void calculateTurnAroundTime(process[], int);
void calculateWaitingTime(process[], int);
void calculateAverageWaitingTime(process[], int);
bool isTableBreak(int);
bool isTableDataField(int);
bool isArrivalTime(process[], int, int);
bool isCompletionTime(process[], int, int);

int tableBreaks[] = {0, 10, 25, 38, 56, 75, 90};
int tableDataFields[] = {5, 17, 32, 48, 66, 83};
int tempData[] = {0, 0, 0, 0, 0, 0};

// Ready Queue
int readyQueue[100];
int readyQueueFront = -1;
int readyQueueRear = -1;

// System Clock
int systemClock = 0;

void getProcessDetails(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the id of process %d: ", i + 1);
        scanf("%d", &p[i].processId);

        printf("Enter the arrival time of P%d: ", p[i].processId);
        scanf("%d", &p[i].arrivalTime);

        printf("Enter the burst time of P%d: ", p[i].processId);
        scanf("%d", &p[i].burstTime);
    }
}

void main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    process p[n];

    getProcessDetails(p, n);
}