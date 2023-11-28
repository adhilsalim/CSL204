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
        int worst_fit_index = -1;

        for (int j = 0; j < total_memory; j++)
        {
            if (memory[1][j] == 0 && memory[0][j] >= process_size[0][i])
            {
                if (worst_fit_index == -1 || memory[0][j] > memory[0][worst_fit_index])
                {
                    worst_fit_index = j;
                }
            }
        }

        if (worst_fit_index != -1)
        {
            memory[1][worst_fit_index] = 1;
            process_size[1][i] = 1;
            printf("Process %d is allocated to Block %d\n", i + 1, worst_fit_index + 1);
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
