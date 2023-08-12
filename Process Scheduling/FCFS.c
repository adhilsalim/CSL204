/*

FIRST COME FIRST SERVE SCHEDULING ALGORITHM

Arrival time: the time at which the process arrives in the ready queue.
Completion time: the time at which process completes its execution.
Burst time: the time required by a process for CPU execution.
Turn around time: time difference between completion time and arrival time.

TAT = CT - AT
WT = TAT - BT

*/

#include <stdio.h>

typedef struct
{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int PID;
} Process;

void main()
{
    int total_processes;

    printf("Enter the number of process: ");
    scanf("%d", &total_processes);

    // creating an array of processes
    Process p[total_processes];

    // getting process details
    for (int i = 0; i < total_processes; i++)
    {
        printf("Enter the the PID for process %d: ", i + 1);
        scanf("%d", &p[i].PID);

        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].AT);

        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].BT);

        printf("\n");
    }

    // sorting the processes according to their arrival time

    for (int i = 0; i < total_processes - 1; i++)
    {
        for (int j = 0; j < total_processes - i - 1; j++)
        {
            if (p[j].AT > p[j + 1].AT)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}