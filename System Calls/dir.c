#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

struct dirent *dptr;

int main()
{
    char buff[256];
    DIR *dirp;

    printf("Enter directory name: ");
    if (scanf("%255s", buff) != 1)
    {
        printf("Error reading input.\n");
        return 1;
    }

    if ((dirp = opendir(buff)) == NULL)
    {
        perror("Error");
        return 1;
    }

    while ((dptr = readdir(dirp)) != NULL)
    {
        printf("%s\n", dptr->d_name);
    }

    closedir(dirp);
    return 0;
}
