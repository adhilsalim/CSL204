/*

SHORTEST REMAINING TIME SCHEDULING ALGORITHM

Arrival time: the time at which the process arrives in the ready queue.
Completion time: the time at which process completes its execution.
Burst time: the time required by a process for CPU execution.
Turn around time: time difference between completion time and arrival time.

TAT = CT - AT
WT = TAT - BT

*/

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int AT;    // Arrival Time
    int BT;    // Burst Time
    int RT;    // Remaining Time
    int CT;    // Completion Time
    int TAT;   // Turnaround Time
    int WT;    // Waiting Time
    int PID;   // Process ID
    bool done; // Flag to track if the process is done
} Process;

int main()
{
    int total_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    // Array of processes
    Process p[total_processes];

    // Input the data for each process
    for (int i = 0; i < total_processes; i++)
    {
        p[i].PID = i + 1;

        printf("Enter the arrival time for process %d: ", p[i].PID);
        scanf("%d", &p[i].AT);

        printf("Enter the burst time for process %d: ", p[i].PID);
        scanf("%d", &p[i].BT);

        printf("\n");

        p[i].RT = p[i].BT;
        p[i].done = false;
    }

    int clock_time = 0;
    int completed_processes = 0;

    while (completed_processes < total_processes)
    {
        int shortest_index = -1;
        int shortest_time = 9999; // A high value to find the minimum

        // Find the process with the shortest remaining time
        for (int i = 0; i < total_processes; i++)
        {
            if (!p[i].done && p[i].AT <= clock_time && p[i].RT < shortest_time)
            {
                shortest_index = i;
                shortest_time = p[i].RT;
            }
        }

        // If no process is found, increment the clock time
        if (shortest_index == -1)
        {
            clock_time++;
            continue; // Go to the next iteration of the loop
        }

        // Otherwise, decrement the remaining time of the process
        p[shortest_index].RT--;

        // If the remaining time is 0, the process is done
        if (p[shortest_index].RT == 0)
        {
            // completion time is the current time + 1
            // why 1? because the process is done at the end of the current time
            p[shortest_index].CT = clock_time + 1;

            p[shortest_index].TAT = p[shortest_index].CT - p[shortest_index].AT;
            p[shortest_index].WT = p[shortest_index].TAT - p[shortest_index].BT;

            p[shortest_index].done = true;

            completed_processes++;
        }

        clock_time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    return 0;
}
