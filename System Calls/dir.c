#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
struct dirent *dptr;
int main()
{
    char buff[256];
    DIR *dirp;
    printf("Enter directory name: ");
    scanf("%s", buff);
    if ((dirp = opendir(buff)) == NULL)
    {
        perror("Error");
        exit(1);
    }
    while ((dptr = readdir(dirp)) != NULL)
    {
        printf("%s\n", dptr->d_name);
    }
    closedir(dirp);
    return 0;
}
