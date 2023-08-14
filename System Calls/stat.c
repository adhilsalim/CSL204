#include <stdio.h>
#include <sys/stat.h>
int main()
{
    struct stat sfile;

    if (stat("hello.txt", &sfile) == 0)
    {
        printf("st_mode=%o\n", sfile.st_mode);       // %o is octal and st_mode is the file mode
        printf("File st_uid %d\n", sfile.st_uid);    // st_uid is the user id of the owner
        printf("File st_size %ld\n", sfile.st_size); // st_size is the size of the file in bytes ld is long int
    }
    else
    {
        perror("Error getting file information");
    }
    return 0;
}