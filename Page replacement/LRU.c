#include <stdio.h>

void main()
{
    int total_frames, total_pages;

    printf("Enter the number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &total_pages);

    int FRAMES[2][total_frames]; // 2 rows, 1st row for page number, 2nd row for frame counter
    int PAGES[total_pages];

    // Input the pages
    for (int i = 0; i < total_pages; i++)
    {
        printf("Enter the page number: ");
        scanf("%d", &PAGES[i]);
    }

    // Initialize the frames
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < total_frames; j++)
        {
            FRAMES[i][j] = -1;
        }
    }

    int pageIsPresent;
    int frame_pointer = 0;
    int frame_counter = 0;
    int page_faults = 0;
    int page_hit = 0;
    int testCounter = 1;

    for (int i = 0; i < total_pages; i++)
    {
        pageIsPresent = 0;

        // check if the page is present in the frame
        for (int j = 0; j < total_frames; j++)
        {
            if (FRAMES[0][j] == PAGES[i])
            {
                pageIsPresent = 1;
                break;
            }
        }

        // page is not present
        if (pageIsPresent == 0)
        {
            page_faults++;

            int freeSpace = 0;
            int freeSpacePointer;

            // check if there is any free space in the frame
            for (int j = 0; j < total_frames; j++)
            {
                if (FRAMES[0][j] == -1)
                {
                    freeSpace = 1;
                    freeSpacePointer = j;
                    break;
                }
            }

            // frame has free space
            if (freeSpace == 1)
            {
                frame_counter += 1;
                FRAMES[0][freeSpacePointer] = PAGES[i];
                FRAMES[1][freeSpacePointer] = frame_counter;
                continue;
            }

            // frame has no free space
            int minCounter = 0;
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[1][k] < minCounter)
                {
                    printf("%d is less than %d\n", FRAMES[1][k], minCounter);
                    minCounter = FRAMES[1][k];
                    frame_pointer = k;
                }
            }

            // replace the frame
            frame_counter += 1;
            FRAMES[0][frame_pointer] = PAGES[i];
            FRAMES[1][frame_pointer] = frame_counter;
        }
        else
        {
            page_hit++;

            // update the frame counter
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[0][k] == PAGES[i])
                {
                    frame_counter += 1;
                    FRAMES[1][k] = frame_counter;
                    break;
                }
            }
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}