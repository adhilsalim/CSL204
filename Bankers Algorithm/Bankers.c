#include <stdio.h>

void main()
{

    int total_process, total_resources;

    // get total number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &total_process);

    // get total number of resources
    printf("Enter total number of resources: ");
    scanf("%d", &total_resources);

    // create allocation, max, need and available matrix
    int allocation[total_process][total_resources], max[total_process][total_resources], need[total_process][total_resources], available[total_resources];

    // get allocation matrix
    printf("Enter allocation matrix: \n");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // get max matrix
    printf("Enter max matrix: \n");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // get available matrix
    printf("Enter available matrix: \n");
    for (int i = 0; i < total_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    // calculate need matrix
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // print allocation matrix
    printf("Allocation matrix: \n");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    // print max matrix
    printf("Max matrix: \n");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    // print need matrix
    printf("Need matrix: \n");
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // calculate initial available matrix
    // for (int i = 0; i < total_process; i++)
    // {
    //     for (int j = 0; j < total_resources; j++)
    //     {
    //         available[j] -= allocation[i][j];
    //     }
    // }

    // print available matrix
    printf("Available matrix: \n");
    for (int i = 0; i < total_resources; i++)
    {
        printf("%d ", available[i]);
    }

    // create finish array
    int finish[total_process];

    // initialize finish array
    for (int i = 0; i < total_process; i++)
    {
        finish[i] = 0;
    }

    // create safe sequence array
    int safe_sequence[total_process], safe_sequence_index = 0;

    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            // check if the process is not finished
            if (finish[i] == 0)
            {

                int flag = 0;
                // check if need is less than available
                for (int k = 0; k < total_resources; k++)
                {
                    if (need[i][k] > available[k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    // add process to safe sequence
                    safe_sequence[safe_sequence_index++] = i;

                    // add allocation to available
                    for (int k = 0; k < total_resources; k++)
                    {
                        available[k] += allocation[i][k];
                    }

                    // mark process as finished
                    finish[i] = 1;
                }
            }
        }
    }

    // check if all processes are finished
    int flag = 0;
    for (int i = 0; i < total_process; i++)
    {
        if (finish[i] == 0)
        {
            flag = 1;
            break;
        }
    }

    // print safe sequence
    if (flag == 0)
    {
        printf("\nSafe sequence: ");
        for (int i = 0; i < total_process; i++)
        {
            printf("%d ", safe_sequence[i]);
        }
    }
    else
    {
        printf("\nDeadlock occured!");
    }
}