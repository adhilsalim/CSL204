#include <stdio.h>

int main()
{
    int total_processes, total_memory;

    // Get the number of processes and available memory
    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the total memory available: ");
    scanf("%d", &total_memory);

    // Initialize arrays for process size, memory size, and allocation flags
    int process_size[2][total_processes];
    int memory[2][total_memory];

    // Get the memory required for each process
    printf("Enter the memory required for each process:\n");
    for (int i = 0; i < total_processes; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_size[0][i]);
        process_size[1][i] = 0; // flag
    }

    // Get the memory available for each block
    printf("Enter the memory available for each block:\n");
    for (int i = 0; i < total_memory; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &memory[0][i]);
        memory[1][i] = 0; // flag
    }

    // Allocate memory using best-fit algorithm
    printf("\nAllocated processes:\n");
    for (int i = 0; i < total_processes; i++)
    {
        int best_fit_index = -1;
        int best_fit_remaining_memory = total_memory;

        // Find the best fit block among available ones
        for (int j = 0; j < total_memory; j++)
        {
            if (memory[1][j] == 0 && memory[0][j] >= process_size[0][i])
            {
                int remaining_memory = memory[0][j] - process_size[0][i];
                if (best_fit_index == -1 || remaining_memory < best_fit_remaining_memory)
                {
                    best_fit_index = j;
                    best_fit_remaining_memory = remaining_memory;
                }
            }
        }

        // Allocate the best fit block if found
        if (best_fit_index != -1)
        {
            memory[1][best_fit_index] = 1;
            process_size[1][i] = 1;
            printf("Process %d is allocated to Block %d\n", i + 1, best_fit_index + 1);
        }
    }

    // Print unallocated processes
    printf("\nUnallocated processes: ");
    for (int i = 0; i < total_processes; i++)
    {
        if (process_size[1][i] == 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
