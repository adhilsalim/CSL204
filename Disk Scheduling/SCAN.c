#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int getSeek(int, int);

int getSeek(int postion_1, int position_2){
    int seek = postion_1-position_2;

    // that is negative number
    if(seek<0)
        return (seek * -1);

    return seek;
}

void main(){

    int head_pos, disk_range, number_of_tracks;

    printf("Enter the current of head position: ");
    scanf("%d", &head_pos);

    printf("Enter total number of tracks (max range): ");
    scanf("%d", &disk_range);

    printf("Enter the number of tracks to access: ");
    scanf("%d", &number_of_tracks);

    int TRACKS[number_of_tracks];

    for(int i=0; i<number_of_tracks; i++){
        printf("Enter the track %d: ", i+1);
        scanf("%d",&TRACKS[i]);

        if(TRACKS[i]>disk_range || TRACKS[i]<0){
            printf("\nTRACK EXCEEDED DISK RANGE. EXITING PROGRAM.\n");
            exit(0);
        }
    }

    printf("\nTRACKS ARRAY: \n");
    for(int i=0; i<number_of_tracks; i++){
        printf("%d ", TRACKS[i]);
    }
    printf("\n\n");
    
    int H_TRACK[number_of_tracks];
    int L_TRACK[number_of_tracks];
    H_TRACK[0] = head_pos;
    int h_track_pointer =1;
    int l_track_pointer =0;

    // sort the track array #3
    int temp;
    for(int i=0; i<number_of_tracks-1; i++){
        for(int j=0; j<number_of_tracks-i-1; j++){
            if(TRACKS[j]>TRACKS[j+1]){
                temp = TRACKS[j+1];
                TRACKS[j+1] = TRACKS[j];
                TRACKS[j] = temp;
            }
        }
    }

    printf("\nTRACKS ARRAY: \n");
    for(int i=0; i<number_of_tracks; i++){
        printf("%d ", TRACKS[i]);
    }
    printf("\n\n");

    // copy tracks array to lower and higher tracks
    for(int i=0; i<number_of_tracks; i++){
        if(TRACKS[i]>=head_pos){
            H_TRACK[h_track_pointer] = TRACKS[i];
            h_track_pointer++;
        }
        else{
            L_TRACK[l_track_pointer] = TRACKS[i];
            l_track_pointer++;
        }
    }
    // bug fix #4
    L_TRACK[l_track_pointer] = disk_range-1;
    l_track_pointer++;
    H_TRACK[h_track_pointer]=disk_range-1;
    h_track_pointer++;

    printf("\nL TRACKS ARRAY: \n");
    for(int i=0; i<l_track_pointer; i++){
        printf("%d ", L_TRACK[i]);
    }
    printf("\n\n");
    printf("\nH TRACKS ARRAY: \n");
    for(int i=0; i<h_track_pointer; i++){
        printf("%d ", H_TRACK[i]);
    }
    printf("\n\n");

    int seek_sum = 0;
    int seek = 0;

    // #2
    for(int i=0; i<h_track_pointer-1; i++){
        seek = getSeek(H_TRACK[i], H_TRACK[i+1]);
        seek_sum += seek;
        printf("head moves from %d to %d, with seek %d\n", H_TRACK[i], H_TRACK[i+1], seek);
    }
    for(int i=l_track_pointer-1; i>0; i--){
        seek = getSeek(L_TRACK[i], L_TRACK[i-1]);
        seek_sum += seek;
        printf("head moves from %d to %d, with seek %d\n", L_TRACK[i], L_TRACK[i-1], seek);
    }

    printf("\nTOTAL SEEKS: %d\nAVG SEEK: %f\n", seek_sum, (float)(seek_sum/number_of_tracks)); // #1 num_tracks will be total seeks
}
