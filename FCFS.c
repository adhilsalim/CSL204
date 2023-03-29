/*
INCOMPLETE :(
*/

#include <stdio.h>
#include <stdbool.h>

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

void printGanttChart(process[], int);
void getProcessDetails(process[], int);
void sort(process[], int);
void print(process[], int);
void calculateCompletionTime(process[], int);
void calculateTurnAroundTime(process[], int);
void calculateWaitingTime(process[], int);
void calculateAverageWaitingTime(process[], int);
bool thisArrivalTimeFound(float, process[], int);
bool isTableBreak(int);

int tableBreaks[] = {0, 10, 25, 38, 56, 75, 90};

bool isTableBreak(int i)
{
    for (int j = 0; j < 7; j++)
    {
        if (i == tableBreaks[j])
        {
            return true;
        }
    }
    return false;
}

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
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+");
    printf("\n| Process | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time |");
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+\n");

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < 91; i++)
        {
            if (isTableBreak(i))
            {
                printf("+");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");

        // printf("\n+    %d   +      %d      +     %d     +        %d       +        %d        +      %d      +", p[i].processId, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
    }
}

void calculateCompletionTime(process p[], int n)
{
    p[0].completionTime = p[0].arrivalTime + p[0].burstTime;

    for (int i = 1; i < n; i++)
    {
        if (p[i].arrivalTime > p[i - 1].completionTime)
        {
            p[i].completionTime = p[i].arrivalTime + p[i].burstTime;
        }
        else
        {
            p[i].completionTime = p[i - 1].completionTime + p[i].burstTime;
        }
    }
}

void calculateTurnAroundTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
    }
}

void calculateWaitingTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
    }
}

void calculateAverageWaitingTime(process p[], int n)
{

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += p[i].waitingTime;
    }

    printf("\nAverage waiting time = %.2f\n", sum / n);
}

bool thisArrivalTimeFound(float time, process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("\nPT: %f\n TT: %f", (float)p[i].arrivalTime, time);

        if ((float)p[i].arrivalTime == time)
        {
            printf("|P%d", p[i].processId);
            return true;
        }
    }
    return false;
}

/*
    // Calculate the total time required for all processes
    for (i = 0; i < n; i++) {
        total_time += p[i].burstTime;
    }

    printf("+");
    for (i = 0; i < total_time; i++) {
        printf("-");
    }
    printf("+\n");

    // Print the process numbers and their respective bursts
    printf("|");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p[i].burstTime; j++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");

    // Print the timeline and completion times
    printf("0");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p[i].burstTime; j++) {
            printf(" ");
        }
        printf("%d", p[i].completionTime);
        prev_completion_time = p[i].completionTime;
    }
    printf("\n");

    printf("+");
    for (i = 0; i < total_time; i++) {
        printf("-");
    }
    printf("+\n");
}*/

void printGanttChart(process p[], int n)
{
    printf("\nGantt Chart\n");

    for (int i = 0; i < p[n - 1].completionTime * 7; i++)
    {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i <= p[n - 1].completionTime * 7; i++)
    {
        // printf("\n%f\n", (float)i / 5);
        if (!thisArrivalTimeFound((float)i / 3, p, n))
        {
            printf(" ");
        }
    }

    printf("|\n");
    for (int i = 0; i < p[n - 1].completionTime * 7; i++)
    {
        printf("-");
    }
}

void main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d", &n);

    process p[n];

    getProcessDetails(p, n);
    sort(p, n);

    calculateCompletionTime(p, n);
    calculateTurnAroundTime(p, n);
    calculateWaitingTime(p, n);
    calculateAverageWaitingTime(p, n);

    print(p, n);
    printGanttChart(p, n);
}