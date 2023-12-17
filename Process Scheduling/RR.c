#include <stdio.h>

typedef struct
{
    int AT;
    int BT;
    int RT;
    int CT;
    int TAT;
    int WT;
    int PID;
} Process;

void main()
{

    int total_process;
    printf("Enter the number of processes: ");
    scanf("%d", &total_process);

    Process P[total_process];

    // assuming arrival time is 0
    printf("enter the process details: \n");
    for (int i = 0; i < total_process; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &P[i].BT);
        P[i].AT = 0;
        P[i].RT = P[i].BT;
        P[i].PID = i + 1;
    }

    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int current_time = 0;
    int completed_process = 0;
    int current_process = 0;

    while (completed_process < total_process)
    {
        // check if the current process is completed or not based on the remaining time RT
        if (P[current_process].RT == 0)
        {
            current_process = (current_process + 1) % total_process;
        }
        else
        {
            // now we know that RT is not zero
            // check if the RT is less than time quantum or not
            if (P[current_process].RT <= time_quantum)
            {
                // this means that the process will be completed in this time quantum
                current_time += P[current_process].RT;
                P[current_process].RT = 0;

                // update the CT, TAT and WT
                P[current_process].CT = current_time;
                P[current_process].TAT = P[current_process].CT; // since AT is 0
                P[current_process].WT = P[current_process].TAT - P[current_process].BT;

                completed_process++;
            }
            else
            {
                // this means that the process will not be completed in this time quantum
                current_time += time_quantum;
                P[current_process].RT -= time_quantum;
            }

            current_process = (current_process + 1) % total_process;
        }
    }

    // print the details
    float total_TAT = 0;
    float total_WT = 0;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < total_process; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].PID, P[i].AT, P[i].BT, P[i].CT, P[i].TAT, P[i].WT);
        total_TAT += P[i].TAT;
        total_WT += P[i].WT;
    }

    printf("Average TAT: %f\n", total_TAT / total_process);
    printf("Average WT: %f\n", total_WT / total_process);
}