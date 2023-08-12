#include <stdio.h>
#include <stdlib.h>

void main()
{
    int total_frames, total_pages;

    printf("Enter the number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &total_pages);

    int FRAMES[total_frames];
    int PAGES[total_pages];

    for (int i = 0; i < total_pages; i++)
    {
        printf("Enter the page number: ");
        scanf("%d", &PAGES[i]);
    }

    for (int j = 0; j < total_frames; j++)
    {
        FRAMES[j] = -1;
    }

    int pageIsPresent;
    int frame_pointer = 0;
    int page_faults = 0;
    int page_hit = 0;

    for (int i = 0; i < total_pages; i++)
    {

        pageIsPresent = 0;

        for (int j = 0; j < total_frames; j++)
        {
            if (FRAMES[j] == PAGES[i])
            {
                pageIsPresent = 1;
                break;
            }
        }

        if (pageIsPresent == 0)
        {
            FRAMES[frame_pointer] = PAGES[i];
            frame_pointer = (frame_pointer + 1) % total_frames;
            page_faults++;
        }
        else
        {
            page_hit++;
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}