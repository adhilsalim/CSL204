#include <stdio.h>
// FIXING A BUG INCOMPLETE
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

    // print the frames - for testing
    for (int j = 0; j < total_frames; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            printf("%d ", FRAMES[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int pageIsPresent;
    int frame_pointer = 0;
    int frame_counter = 0;
    int page_faults = 0;
    int page_hit = 0;
    int testCounter = 1;
    for (int i = 0; i < total_pages; i++)
    {
        pageIsPresent = 0;

        for (int j = 0; j < total_frames; j++)
        {
            if (FRAMES[0][j] == PAGES[i])
            {
                pageIsPresent = 1;
                break;
            }
        }

        if (pageIsPresent == 0)
        {
            page_faults++;

            // frame has free space
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[0][k] == -1)
                {
                    FRAMES[0][k] = PAGES[i];
                    FRAMES[1][k] = frame_counter++;
                    break;
                }
            }

            // frame has no free space
            int minCounter = FRAMES[1][0];
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[1][k] < minCounter)
                {
                    minCounter = FRAMES[1][k];
                    frame_pointer = k;
                }
            }

            // replace the frame
            FRAMES[0][frame_pointer] = PAGES[i];
            FRAMES[1][frame_pointer] = frame_counter++;
        }
        else
        {
            page_hit++;

            // update the frame counter
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[0][k] == PAGES[i])
                {
                    FRAMES[1][k] = frame_counter++;
                    break;
                }
            }
        }

        printf("\ncounter: %d\n", testCounter++);
        for (int j = 0; j < total_frames; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                printf("%d ", FRAMES[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // print the frames - for testing
    for (int j = 0; j < total_frames; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            printf("%d ", FRAMES[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}