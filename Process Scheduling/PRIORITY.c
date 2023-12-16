/*

PRIORITY SCHEDULING ALGORITHM

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
    int PR;
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

        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &p[i].PR);

        printf("\n");
    }

    // sorting the processes according to their arrival time, priority & burst time

    for (int i = 0; i < total_processes - 1; i++)
    {
        for (int j = 0; j < total_processes - i - 1; j++)
        {
            /*
            1. if arrival time of jth process is greater than j+1th process
            2. if arrival time is same and priority of jth process is greater than j+1th process
            3. if arrival time and priority is same and burst time of jth process is greater than j+1th process
            */
            if ((p[j].AT > p[j + 1].AT) || (p[j].AT == p[j + 1].AT && p[j].PR > p[j + 1].PR) || (p[j].AT == p[j + 1].AT && p[j].PR == p[j + 1].PR && p[j].BT > p[j + 1].BT))
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // calculating the CT, TAT, WT for each process
    p[0].CT = p[0].AT + p[0].BT;
    p[0].TAT = p[0].CT - p[0].AT;
    p[0].WT = p[0].TAT - p[0].BT;

    int current_time = p[0].CT;

    for (int i = 1; i < total_processes; i++)
    {
        if (p[i].AT > current_time)
        {
            current_time = p[i].AT;
        }

        p[i].CT = current_time + p[i].BT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;

        current_time = p[i].CT;
    }
    // sorting the processes according to PID before printing

    for (int i = 0; i < total_processes - 1; i++)
    {
        for (int j = 0; j < total_processes - i - 1; j++)
        {
            if (p[j].PID > p[j + 1].PID)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // printing the TAT and WT for each process
    // also calculating the average TAT and WT
    float total_TAT = 0;
    float total_WT = 0;

    // print the process details
    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\t\n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", p[i].PID, p[i].AT, p[i].BT, p[i].PR, p[i].CT, p[i].WT, p[i].TAT);
        total_WT += p[i].WT;
        total_TAT += p[i].TAT;
    }

    // printing the average TAT and WT
    printf("Average turn around time: %2.f\n", total_TAT / total_processes);
    printf("Average waiting time: %2.f\n", total_WT / total_processes);
}