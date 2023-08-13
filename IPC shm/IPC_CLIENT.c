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

    if ((shmid = shmget(key, SHM_SIZE, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    else
    {
        printf("Accessing shared memory id: %d\n", shmid);
    }

    // Attach the segment to our data space

    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    for (s = shm; *s != '\0'; s++)
    {
        putchar(*s);
    }
    putchar('\n');

    *shm = '*';

    return 0;
}