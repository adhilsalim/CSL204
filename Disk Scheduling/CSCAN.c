#include <stdio.h>
#include <stdlib.h>

int getSeek(int, int);

int getSeek(int postion_1, int position_2)
{

    // get the difference of the position
    int seek = postion_1 - position_2;

    /*
    The difference is a positive value so
    if the value is negative we make it
    positive by multiplying it by -1
    */
    if (seek < 0)
        return (seek * -1);

    return seek;
}

void main()
{

    int head_pos, disk_range, number_of_tracks;

    printf("Enter the current of head position: ");
    scanf("%d", &head_pos);

    printf("Enter total number of tracks: ");
    scanf("%d", &disk_range); // In this program if the total number of tracks is 100 then the tracks will be 0-99

    printf("Enter the number of tracks to access: ");
    scanf("%d", &number_of_tracks);

    int TRACKS[number_of_tracks];

    // get the tracks
    for (int i = 0; i < number_of_tracks; i++)
    {
        printf("Enter the track %d: ", i + 1);
        scanf("%d", &TRACKS[i]);

        // make sure the track is within the disk range, ie if disk range is 100 then tracks should be 0-99
        if (TRACKS[i] > disk_range || TRACKS[i] < 0)
        {
            printf("\nTRACK EXCEEDED DISK RANGE. EXITING PROGRAM.\n");
            exit(0);
        }
    }

    printf("\nTRACKS ARRAY: \n");
    for (int i = 0; i < number_of_tracks; i++)
    {
        printf("%d ", TRACKS[i]);
    }
    printf("\n\n");

    // split the tracks into lower and higher tracks
    int H_TRACK[number_of_tracks];
    int L_TRACK[number_of_tracks];

    // set the first element of the higher track to the head position
    H_TRACK[0] = head_pos;

    int h_track_pointer = 1; // first element is already set
    int l_track_pointer = 0;

    // sort the track array - bubble sort
    int temp;
    for (int i = 0; i < number_of_tracks - 1; i++)
    {
        for (int j = 0; j < number_of_tracks - i - 1; j++)
        {
            if (TRACKS[j] > TRACKS[j + 1])
            {
                temp = TRACKS[j + 1];
                TRACKS[j + 1] = TRACKS[j];
                TRACKS[j] = temp;
            }
        }
    }

    printf("\nTRACKS ARRAY: \n");
    for (int i = 0; i < number_of_tracks; i++)
    {
        printf("%d ", TRACKS[i]);
    }
    printf("\n\n");

    // copy the tracks into the higher track array
    for (int i = 0; i < number_of_tracks; i++)
    {
        if (TRACKS[i] >= head_pos) // if the track is greater than or equal to the head position
        {
            H_TRACK[h_track_pointer] = TRACKS[i];
            h_track_pointer++;
        }
    }

    /* C-SCAN Algorithm moves to both extremes of the disk,
    serving all the requests in between one direction,
    then reversing direction and serving the remaining requests
    So adding both extremes in the lower and higher track arrays respectively
    */

    L_TRACK[l_track_pointer] = disk_range - 1; // add the last element of the lower track to the last track of the disk range
    l_track_pointer++;

    L_TRACK[0] = 0; // add the first element of the lower track to the first track ie 0
    l_track_pointer++;

    H_TRACK[h_track_pointer] = disk_range - 1; // add the last element of the higher track to the last track of the disk range
    h_track_pointer++;

    // copy the tracks into the lower track array
    for (int i = 1; i < number_of_tracks; i++)
    {
        if (TRACKS[i] < head_pos)
        {
            L_TRACK[l_track_pointer] = TRACKS[i];
            l_track_pointer++;
        }
    }

    // print the lower and higher track arrays
    printf("\nL TRACKS ARRAY: \n");
    for (int i = 0; i < l_track_pointer; i++)
    {
        printf("%d ", L_TRACK[i]);
    }
    printf("\n\n");
    printf("\nH TRACKS ARRAY: \n");
    for (int i = 0; i < h_track_pointer; i++)
    {
        printf("%d ", H_TRACK[i]);
    }
    printf("\n\n");

    int seek_sum = 0;
    int seek = 0;

    // get the seek for the higher track array
    for (int i = 0; i < h_track_pointer - 1; i++)
    {
        seek = getSeek(H_TRACK[i], H_TRACK[i + 1]);
        seek_sum += seek;
        printf("head moves from %d to %d, with seek %d\n", H_TRACK[i], H_TRACK[i + 1], seek);
    }

    // get the seek for the lower track array
    for (int i = l_track_pointer - 1; i > 0; i--)
    {
        seek = getSeek(L_TRACK[i], L_TRACK[i - 1]);
        seek_sum += seek;
        printf("head moves from %d to %d, with seek %d\n", L_TRACK[i], L_TRACK[i - 1], seek);
    }

    printf("\nTOTAL SEEKS: %d\nAVG SEEK: %2.f\n", seek_sum, (float)(seek_sum / number_of_tracks));
}
