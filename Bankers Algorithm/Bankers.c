#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main()
{

    int total_resources, total_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &total_resources);

    // create allocation, max, need matrix
    int ALLOCATION[total_processes][total_resources];
    int MAX[total_processes][total_resources];
    int NEED[total_processes][total_resources];

    int AVAILABLE[total_resources];

    for (int i = 0; i < total_resources; i++)
    {
        printf("Enter the total available instances of resource %d: ", i + 1);
        scanf("%d", &AVAILABLE[i]);
    }

    // get allocation matrix
    printf("Enter the allocation matrix: \n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("Enter the allocation of process %d for resource %d: ", i + 1, j + 1);
            scanf("%d", &ALLOCATION[i][j]);
        }
    }

    // get max matrix
    printf("Enter the max matrix: \n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("Enter the max of process %d for resource %d: ", i + 1, j + 1);
            scanf("%d", &MAX[i][j]);
        }
    }

    // calculate need matrix
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
        }
    }

    // print allocation matrix
    printf("Allocation matrix: \n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", ALLOCATION[i][j]);
        }
        printf("\n");
    }

    // print max matrix
    printf("Max matrix: \n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", MAX[i][j]);
        }
        printf("\n");
    }

    // print need matrix
    printf("Need matrix: \n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_resources; j++)
        {
            printf("%d ", NEED[i][j]);
        }
        printf("\n");
    }

    // calculate initial available matrix
    for (int i = 0; i < total_resources; i++)
    {
        for (int j = 0; j < total_processes; j++)
        {
            AVAILABLE[i] -= ALLOCATION[j][i];
            if (AVAILABLE[i] < 0)
            {
                printf("Invalid input\n");
                exit(0);
            }
        }
    }

    // print available matrix
    printf("Available matrix: \n");
    for (int i = 0; i < total_resources; i++)
    {
        printf("%d ", AVAILABLE[i]);
    }
}