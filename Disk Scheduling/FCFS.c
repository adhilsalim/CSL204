#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getSeek(int, int);

int getSeek(int postion_1, int position_2)
{
    int seek = postion_1 - position_2;

    // that is negative number
    if (seek < 0)
        return (seek * -1);

    return seek;
}

void main()
{
    int head_pos, disk_range, number_of_tracks;

    // get head position, disk range, number of tracks
    printf("Enter the current of head position: ");
    scanf("%d", &head_pos);

    printf("Enter the range of disk (max range): ");
    scanf("%d", &disk_range);

    printf("Enter the number of tracks to access: ");
    scanf("%d", &number_of_tracks);

    int TRACKS[number_of_tracks + 1]; // why +1? because we have to include the head position
    TRACKS[0] = head_pos;             // adding head pos to array

    // get tracks
    for (int i = 1; i <= number_of_tracks; i++)
    {
        printf("Enter the track %d: ", i);
        scanf("%d", &TRACKS[i]);

        // check if track is out of range
        if (TRACKS[i] > disk_range || TRACKS[i] < 0)
        {
            printf("\nTRACK EXCEEDED DISK RANGE. EXITING PROGRAM.\n");
            exit(0);
        }
    }

    // print tracks
    printf("\nTRACKS ARRAY: \n");
    for (int i = 0; i <= number_of_tracks; i++)
    {
        printf("%d ", TRACKS[i]);
    }
    printf("\n\n");

    int seek_sum = 0;

    for (int i = 0; i <= number_of_tracks - 1; i++) // -1 because when we reach the last track, TRACKS[i + 1] will be out of range
    {
        int seek = getSeek(TRACKS[i], TRACKS[i + 1]);
        seek_sum += seek;
        printf("Head moves from %d to %d with seek %d\n", TRACKS[i], TRACKS[i + 1], seek);
    }

    printf("\nTOTAL SEEKS: %d\nAVG SEEK: %d\n", seek_sum, (seek_sum / number_of_tracks)); // num_tracks will be total seeks
}
