#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 0, x = 0;

// Function prototypes
int wait(int);
int signal(int);
void producer();
void consumer();

int main()
{
    int n;

    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

    while (1)
    {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if ((mutex == 1) && (full != 3))
                producer();
            else
                printf("BUFFER IS FULL");
            break;

        case 2:
            if ((mutex == 1) && (empty != 0))
                consumer();
            else
                printf("BUFFER IS EMPTY");
            break;

        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}

int wait(int s)
{
    return (--s); // Decrement semaphore value
}

int signal(int s)
{
    return (++s); // Increment semaphore value
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nproducer produces the item %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nconsumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}
