#include <stdio.h>
#include <sys/stat.h>
int main()
{
    struct stat sfile;
    if (stat("hello.txt", &sfile) == 0)
    {
        printf("st_mode=%o\n", sfile.st_mode);
        printf("File st_uid %d\n", sfile.st_uid);
        printf("File st_size %ld\n", sfile.st_size);
    }
    else
    {
        perror("Error getting file information");
    }
    return 0;
}