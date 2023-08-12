#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(int processes[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j][0] > processes[j + 1][0] ||
                (processes[j][0] == processes[j + 1][0] && processes[j][1] > processes[j + 1][1]))
            {
                swap(&processes[j][0], &processes[j + 1][0]);
                swap(&processes[j][1], &processes[j + 1][1]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n][2];
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &processes[i][0], &processes[i][1]);
    }

    sortProcesses(processes, n);

    printf("Sorted processes based on arrival time and burst time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: Arrival Time = %d, Burst Time = %d\n", i + 1, processes[i][0], processes[i][1]);
    }

    return 0;
}
