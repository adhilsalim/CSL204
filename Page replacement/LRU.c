#include <stdio.h>
#include <stdbool.h>
struct Frame
{
    int page_number;
    int frame_counter;
};

void main()
{
    int total_frames, total_pages;

    printf("Enter the number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &total_pages);

    struct Frame FRAMES[total_frames];
    int PAGES[total_pages];

    // Input the pages
    for (int i = 0; i < total_pages; i++)
    {
        printf("Enter the page number: ");
        scanf("%d", &PAGES[i]);
    }

    // Initialize the frames
    for (int i = 0; i < total_frames; i++)
    {
        FRAMES[i].page_number = -1;
        FRAMES[i].frame_counter = 0;
    }

    bool pageIsPresent;
    int frame_pointer = 0;
    int frame_counter = 0;
    int page_faults = 0;
    int page_hit = 0;

    for (int i = 0; i < total_pages; i++)
    {
        pageIsPresent = false;

        // Check if the page is present in the frame
        for (int j = 0; j < total_frames; j++)
        {
            if (FRAMES[j].page_number == PAGES[i])
            {
                pageIsPresent = true;
                break;
            }
        }

        // Page is not present
        if (!pageIsPresent)
        {
            page_faults++;

            bool freeSpace = false;
            int freeSpacePointer;

            // Check if there is any free space in the frame
            for (int j = 0; j < total_frames; j++)
            {
                if (FRAMES[j].page_number == -1)
                {
                    freeSpace = true;
                    freeSpacePointer = j;
                    break;
                }
            }

            // Frame has free space
            if (freeSpace)
            {
                frame_counter++;
                FRAMES[freeSpacePointer].page_number = PAGES[i];
                FRAMES[freeSpacePointer].frame_counter = frame_counter;
                continue;
            }

            // Frame has no free space
            int minCounter = FRAMES[0].frame_counter;
            frame_pointer = 0;

            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[k].frame_counter < minCounter)
                {
                    minCounter = FRAMES[k].frame_counter;
                    frame_pointer = k;
                }
            }

            // Replace the frame
            frame_counter++;
            FRAMES[frame_pointer].page_number = PAGES[i];
            FRAMES[frame_pointer].frame_counter = frame_counter;
        }
        else
        {
            page_hit++;

            // Update the frame counter
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[k].page_number == PAGES[i])
                {
                    frame_counter++;
                    FRAMES[k].frame_counter = frame_counter;
                    break;
                }
            }
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}
