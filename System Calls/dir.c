#include <stdio.h>
#include <dirent.h> // for opendir(), readdir(), closedir()
#include <stdlib.h>
#include <string.h>

struct dirent *directory_entry; // pointer for directory entry

int main()
{
    char buff[256];
    DIR *directory_pointer; // pointer for directory

    printf("Enter directory name: ");
    if (scanf("%255s", buff) != 1) // if scanf() fails to read input
    {
        printf("Error reading input.\n");
        return 1;
    }

    if ((directory_pointer = opendir(buff)) == NULL) // opendir() returns NULL if couldn't open directory
    {
        perror("Error");
        return 1;
    }

    while ((directory_entry = readdir(directory_pointer)) != NULL) // readdir() returns NULL when end of directory stream is reached
    {
        printf("%s\n", directory_entry->d_name);
    }

    closedir(directory_pointer);
    return 0;
}
