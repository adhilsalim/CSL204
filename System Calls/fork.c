#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

int main()
{
    int pid = fork(); // fork() returns 0 to the child process and the process id of the child to the parent process

    if (pid < 0) // fork() returns -1 if the fork failed
    {
        printf("Fork failed");
        exit(1);
    }
    else if (pid == 0) // fork() returns 0 to the child process
    {
        execlp("/bin/date", "date", NULL);
        exit(0);
    }
    else // fork() returns the process id of the child to the parent process
    {
        printf("Process id is - %d\n", getpid());
        wait(NULL); // wait() causes the parent process to wait until the child process has finished executing
        exit(0);
    }
    return 0;
}
