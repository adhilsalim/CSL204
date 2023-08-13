/*
    First Fit Algorithm
        SAMPLE INPUT:

        Enter the number of processes: 4
        Enter the total memory available: 5
        Enter the memory required for each process:
        Process 1: 212
        Process 2: 417
        Process 3: 112
        Process 4: 426
        Enter the memory available for each block:
        Block 1: 100
        Block 2: 500
        Block 3: 200
        Block 4: 300
        Block 5: 600
*/
#include <stdio.h>
void main()
{

    int total_processes, total_memory;
    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the total memory available: ");
    scanf("%d", &total_memory);

    int process_size[2][total_processes];
    int memory[2][total_memory];

    printf("Enter the memory required for each process: \n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_size[0][i]);
        process_size[1][i] = 0; // flag
    }

    printf("Enter the memory available for each block: \n");
    for (int i = 0; i < total_memory; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &memory[0][i]);
        memory[1][i] = 0; // flag
    }

    printf("\nAllocated processes: \n");

    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < total_memory; j++)
        {
            if (memory[1][j] == 0 && memory[0][j] >= process_size[0][i])
            {
                memory[1][j] = 1;
                process_size[1][i] = 1;
                printf("Process %d is allocated to Block %d\n", i + 1, j + 1);
                break;
            }
        }
    }

    printf("\nUnallocated processes: ");
    for (int i = 0; i < total_processes; i++)
    {
        if (process_size[1][i] == 0)
        {
            printf("%d ", i + 1);
        }
    }
}