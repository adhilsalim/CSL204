#include <stdio.h>
#include <stdbool.h>
typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
    int completionTime;
} process;

// function prototypes
void getProcessDetails(process[], int);
void sort(process[], int);

// calculation functions
void calculateCompletionTime(process[], int);
void calculateTurnAroundTime(process[], int);
void calculateWaitingTime(process[], int);

// utility functions
float getAverageWaitingTime(process[], int);
float getAverageTurnAroundTime(process[], int);

bool isArrivalTime(process[], int, int);
bool isCompletionTime(process[], int, int);

// printing functions
void printGanttChart(process[], int);
void print(process[], int);

// function to get the process details
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

// sorting the process according to arrival time
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

// calculating the completion time of each process
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

// calculating the turn around time of each process
void calculateTurnAroundTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
    }
}

// calculating the waiting time of each process
void calculateWaitingTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
    }
}

bool isArrivalTime(process p[], int n, int time)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrivalTime == time)
        {
            return true;
        }
    }
    return false;
}

bool isCompletionTime(process p[], int n, int time)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].completionTime == time)
        {
            return true;
        }
    }
    return false;
}

// calculating the average waiting time
float getAverageWaitingTime(process p[], int n)
{

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += p[i].waitingTime;
    }

    return (float)(sum / n);
}

// calculating the average turn around time
float getAverageTurnAroundTime(process p[], int n)
{

    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += p[i].turnAroundTime;
    }

    return sum / n;
}

void printGanttChart(process p[], int n)
{
    printf("\n\nGantt Chart\n");
}

// printing the process details
void print(process p[], int n)
{
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n|                                  PROCESS DETAILS                                        |");
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+");
    printf("\n| Process | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time |");
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %4d    | %7d      | %6d     | %8d        | %8d         | %6d       |\n", p[i].processId, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
        if (i < n - 1)
            printf("+---------+--------------+------------+-----------------+------------------+--------------+\n");
    }
    printf("+-----------------------------------------------------------------------------------------+");
    printf("\n| AVERAGE TURN AROUND TIME:  %2f                                                     |", getAverageTurnAroundTime(p, n));
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n| AVERAGE WAITING TIME    :  %2f                                                     |", getAverageWaitingTime(p, n));
    printf("\n+-----------------------------------------------------------------------------------------+");
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

    print(p, n);
    printGanttChart(p, n);
}