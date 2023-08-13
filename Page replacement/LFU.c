#include <stdio.h>
#include <stdbool.h>

struct Frame
{
    int page_number;
    int frequency;
    int arrivalCount;
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
        FRAMES[i].frequency = 0;
        FRAMES[i].arrivalCount = 0;
    }

    bool pageIsPresent;

    int frame_pointer = 0;
    int frequency = 0;
    int arrivalCount = 0;

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
                arrivalCount++;
                FRAMES[freeSpacePointer].page_number = PAGES[i];
                FRAMES[freeSpacePointer].frequency = 1;
                FRAMES[freeSpacePointer].arrivalCount = arrivalCount;
                continue;
            }

            // Frame has no free space
            int minFrequency = 9999;
            frame_pointer = 0;

            // Find the frame with the minimum frequency
            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[k].frequency < minFrequency)
                {
                    minFrequency = FRAMES[k].frequency;
                    frame_pointer = k;
                }
            }

            // find the frames with same minimum frequency
            int MIN_FREQUENCY_FRAMES[2][total_frames];
            int min_frequency_frame_pointer = 0;

            for (int k = 0; k < total_frames; k++)
            {
                if (FRAMES[k].frequency == minFrequency)
                {
                    MIN_FREQUENCY_FRAMES[0][min_frequency_frame_pointer] = k;
                    MIN_FREQUENCY_FRAMES[1][min_frequency_frame_pointer] = FRAMES[k].arrivalCount;
                    min_frequency_frame_pointer++;
                }
            }

            // find the frame with the minimum arrival count
            int minArrivalCount = 9999;
            int minArrivalCountFramePointer = 0;
            for (int k = 0; k < min_frequency_frame_pointer; k++)
            {
                if (MIN_FREQUENCY_FRAMES[1][k] < minArrivalCount)
                {
                    minArrivalCount = MIN_FREQUENCY_FRAMES[1][k];
                    minArrivalCountFramePointer = k;
                }
            }

            // Replace the frame
            arrivalCount++;
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].page_number = PAGES[i];
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].frequency = 1;
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].arrivalCount = arrivalCount;
        }
        else
        {
            page_hit++;

            // update the frequency and arrival count of the page
            for (int j = 0; j < total_frames; j++)
            {
                if (FRAMES[j].page_number == PAGES[i])
                {
                    FRAMES[j].frequency++;
                    FRAMES[j].arrivalCount++;
                    break;
                }
            }
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}