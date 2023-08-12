#include <stdio.h>

typedef struct
{
    int AT;
    int BT;
    int RT; // Remaining Time
    int CT;
    int TAT;
    int WT;
    int PID;
} Process;

int main()
{
    int total_processes;
    int time_quantum;

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

        p[i].RT = p[i].BT; // Initialize the remaining time to burst time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int clock_time = 0;
    int completed_processes = 0;

    while (completed_processes < total_processes)
    {

        for (int i = 0; i < total_processes; i++)
        {
            // If the process is not completed and has arrived
            if (p[i].RT > 0)
            {
                // If the remaining time is less than or equal to the time quantum
                if (p[i].RT <= time_quantum)
                {
                    // remember there is no cpu idle time in RR
                    clock_time += p[i].RT;

                    p[i].RT = 0;
                    p[i].CT = clock_time;

                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;

                    completed_processes++;
                }
                else // If the remaining time is greater than the time quantum
                {
                    clock_time += time_quantum;
                    p[i].RT -= time_quantum;
                }
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    return 0;
}
