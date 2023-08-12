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

    Process p[total_processes];

    for (int i = 0; i < total_processes; i++)
    {
        p[i].PID = i + 1;

        printf("Enter the arrival time for process %d: ", p[i].PID);
        scanf("%d", &p[i].AT);

        printf("Enter the burst time for process %d: ", p[i].PID);
        scanf("%d", &p[i].BT);

        p[i].RT = p[i].BT;
        p[i].done = false;
    }

    int clock_time = 0;
    int completed_processes = 0;

    while (completed_processes < total_processes)
    {
        int shortest_index = -1;
        int shortest_time = 9999; // A high value to find the minimum

        for (int i = 0; i < total_processes; i++)
        {
            if (!p[i].done && p[i].AT <= clock_time && p[i].RT < shortest_time)
            {
                shortest_index = i;
                shortest_time = p[i].RT;
            }
        }

        if (shortest_index == -1)
        {
            clock_time++;
            continue;
        }

        p[shortest_index].RT--;

        if (p[shortest_index].RT == 0)
        {
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
