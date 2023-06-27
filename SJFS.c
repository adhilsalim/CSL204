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

void bubbleSort(Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].BT > processes[j + 1].BT)
            {
                // Swap the processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(Process processes[], int n)
{
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i].WT = currentTime;
        currentTime += processes[i].BT;
        processes[i].TAT = processes[i].WT + processes[i].BT;
        processes[i].CT = processes[i].TAT;
    }
}

void displayProcesses(Process processes[], int n)
{
    printf("PID\tAT\tBT\tTAT\tCT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].PID, processes[i].AT, processes[i].BT,
               processes[i].TAT, processes[i].CT, processes[i].WT);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter the Burst Time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i].AT = 0;
        processes[i].PID = i + 1;
        printf("Process %d: ", processes[i].PID);
        scanf("%d", &processes[i].BT);
    }

    // Sort the processes based on Burst Time
    bubbleSort(processes, n);

    // Calculate turnaround time, completion time, and waiting time for each process
    calculateTimes(processes, n);

    // Display the process details
    displayProcesses(processes, n);

    return 0;
}
