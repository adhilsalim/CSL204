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

bool isTableDataField(int i)
{
    for (int j = 0; j < 6; j++)
    {
        if (i == tableDataFields[j])
        {
            return true;
        }
    }
    return false;
}

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
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n|                                  PROCESS DETAILS                                        |");
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+");
    printf("\n| Process | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time |");
    printf("\n+---------+--------------+------------+-----------------+------------------+--------------+\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %7d | %12d | %10d | %15d | %16d | %12d |\n", p[i].processId, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
        printf("+---------+--------------+------------+-----------------+------------------+--------------+\n");
    }
    printf("\n|                                                                                         |");
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n| AVERAGE TURN AROUND TIME:                                                               |");
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n| AVERAGE WAITING TIME    :                                                               |");
    printf("\n+-----------------------------------------------------------------------------------------+");
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

void printGanttChart(process p[], int n)
{
    printf("\n\nGantt Chart\n");

    int totalCompletionTime = p[n - 1].completionTime;

    for (int i = 0, j = 0; i <= totalCompletionTime; i++)
    {
        if (isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else if (isCompletionTime(p, n, i) && !isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else
        {
            printf("----");
        }
    }

    printf("\n");

    for (int i = 0, j = 0; i <= totalCompletionTime; i++)
    {
        if (isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else if (isCompletionTime(p, n, i) && !isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else
        {
            printf("    ");
        }
    }

    printf("\n");

    for (int i = 0, j = 0; i <= totalCompletionTime; i++)
    {
        if (isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else if (isCompletionTime(p, n, i) && !isArrivalTime(p, n, i))
        {
            printf("+");
        }
        else
        {
            printf("----");
        }
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