#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHM_SIZE 27

int main()
{

    int shmid;
    key_t key = 2013;
    char *shm, *s;

    // Create the segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    printf("shmid: %d\n", shmid);

    // Attach the segment to our data space

    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Put some things into the memory for the other process to read
    memset(shm, 0, SHM_SIZE);
    s = shm;

    for (char c = 'a'; c <= 'z'; c++)
    {
        *s++ = c;
    }

    *s = '\0';

    // Wait until the other process changes the first character of our memory
    while (*shm != '*')
        ;

    printf("client finished\n");

    if (shmdt(shm) != 0)
    {
        perror("shmdt");
        exit(1);
    }

    shmctl(shmid, IPC_RMID, 0);

    return 0;
}