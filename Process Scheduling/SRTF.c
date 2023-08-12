/*

SHORTEST REMAINING TIME FIRST SCHEDULING ALGORITHM

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
    int AT;
    int BT;
    int CBT; // copy of burst time
    int CT;
    int TAT;
    int WT;
    int PID;
    int DN; // done or finished
} Process;

void main()
{
    int total_processes;

    printf("Enter the number of process: ");
    scanf("%d", &total_processes);

    // creating an array of processes
    Process p[total_processes];
    Process ready_queue[total_processes];

    // getting process details
    for (int i = 0; i < total_processes; i++)
    {
        printf("Enter the the PID for process %d: ", i + 1);
        scanf("%d", &p[i].PID);

        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].AT);

        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].BT);

        p[i].DN = 0;        // initially no process is done
        p[i].CBT = p[i].BT; // copying the burst time to CBT
        printf("\n");
    }

    bool completed_all_process = false;
    int clock_time = 0;
    int total_process_RQ = 0;
    bool process_added = false;

    while (!completed_all_process)
    {
        printf("\nClock time: %d\n", clock_time); // for testing

        // add processes in ready queue based on their arrival time
        for (int i = 0; i < total_processes; i++)
        {
            // if any process arrives at clock time, add it to the ready queue
            if (p[i].AT == clock_time && p[i].DN == 0)
            {
                process_added = false;

                // before adding the process, check if it is already in the ready queue
                for (int j = 0; j < total_process_RQ; j++)
                {
                    if (ready_queue[j].PID == p[i].PID)
                    {
                        process_added = true;
                        break;
                    }
                }

                // if the process is not already in the ready queue, add it
                if (!process_added)
                {
                    ready_queue[total_process_RQ] = p[i];
                    total_process_RQ++;

                    printf("\nprocess %d added to ready queue\n", p[i].PID); // for testing
                }
            }
        }

        // find the process with the shortest burst time in the ready queue
        int pid_of_shortest_process = 0;

        for (int i = 0; i < total_process_RQ; i++)
        {
            if (ready_queue[i].BT < ready_queue[pid_of_shortest_process - 1].BT)
            {
                pid_of_shortest_process = i + 1;
            }
        }

        printf("\nProcess with PID %d has the shortest burst time\n", ready_queue[pid_of_shortest_process - 1].PID); // for testing

        // reduce the burst time of the process with the shortest burst time by 1
        if (ready_queue[pid_of_shortest_process - 1].BT > 0)
        {
            ready_queue[pid_of_shortest_process - 1].BT--;
            p[pid_of_shortest_process - 1].BT--;
        }

        printf("\nProcess with PID %d has burst time %d\n", ready_queue[pid_of_shortest_process - 1].PID, ready_queue[pid_of_shortest_process - 1].BT); // for testing

        if (ready_queue[pid_of_shortest_process - 1].BT == 0)
        {
            ready_queue[pid_of_shortest_process].DN = 1;
            p[pid_of_shortest_process].DN = 1;
        }

        printf("\nProcess with PID %d has done = %d\n", ready_queue[pid_of_shortest_process - 1].PID, ready_queue[pid_of_shortest_process - 1].DN); // for testing

        // increment the clock time
        clock_time++;

        // check if all the processes are done
        completed_all_process = true;

        for (int i = 0; i < total_processes; i++)
        {
            if (p[i].DN == 0)
            {
                completed_all_process = false;
                break;
            }

            printf("\nProcess with PID %d has done = %d\n", p[i].PID, p[i].DN); // for testing
        }
    }

    // calculating the CT, TAT, WT for each process
    p[0].CT = p[0].AT + p[0].CBT;
    p[0].TAT = p[0].CT - p[0].AT;
    p[0].WT = p[0].TAT - p[0].CBT;

    int current_time = p[0].CT;

    for (int i = 1; i < total_processes; i++)
    {
        if (p[i].AT > current_time)
        {
            current_time = p[i].AT;
        }

        p[i].CT = current_time + p[i].CBT;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].CBT;

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
    float avg_TAT = 0;
    float avg_WT = 0;

    for (int i = 0; i < total_processes; i++)
    {
        printf("Process %d:\n", p[i].PID);
        printf("Turn around time: %d\n", p[i].TAT);
        printf("Waiting time: %d\n", p[i].WT);
        printf("\n");

        avg_TAT += p[i].TAT;
        avg_WT += p[i].WT;
    }

    // printing the average TAT and WT
    printf("Average turn around time: %2.f\n", avg_TAT / total_processes);
    printf("Average waiting time: %2.f\n", avg_WT / total_processes);
}