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
        printf("Checking for page %d\n", PAGES[i]);

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
            printf("Page fault for page %d\n", PAGES[i]);
            bool freeSpace = false;
            int freeSpacePointer;

            // Check if there is any free space in the frame
            printf("Checking for free space\n");
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
                printf("Free space found\n");
                arrivalCount++;
                FRAMES[freeSpacePointer].page_number = PAGES[i];
                FRAMES[freeSpacePointer].frequency = 1;
                FRAMES[freeSpacePointer].arrivalCount = arrivalCount;

                // print the frames
                for (int j = 0; j < total_frames; j++)
                {
                    printf("%d\t %d\t %d\t\n", FRAMES[j].page_number, FRAMES[j].frequency, FRAMES[j].arrivalCount);
                }

                continue;
            }

            // Frame has no free space
            printf("No free space found\n");
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
            printf("Frame with minimum frequency: %d with frequency %d\n", frame_pointer, minFrequency);

            // find the frames with same minimum frequency
            printf("Finding frames with same minimum frequency\n");
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

            // print the frames with same minimum frequency
            printf("Frames with same minimum frequency\n");
            for (int k = 0; k < min_frequency_frame_pointer; k++)
            {
                printf("INDEX\t ARRIVAL\n%d\t %d\n", MIN_FREQUENCY_FRAMES[0][k], MIN_FREQUENCY_FRAMES[1][k]);
            }

            // find the frame with the minimum arrival count
            printf("Finding frame with minimum arrival count\n");
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
            printf("Index of frame with minimum arrival count: %d with arrival count %d\n", MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer], minArrivalCount);
            for (int k = 0; k < total_frames; k++)
            {
                printf("%d\t %d\t %d\t\n", FRAMES[k].page_number, FRAMES[k].frequency, FRAMES[k].arrivalCount);
            }

            // Replace the frame
            arrivalCount++;
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].page_number = PAGES[i];
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].frequency = 1;
            FRAMES[MIN_FREQUENCY_FRAMES[0][minArrivalCountFramePointer]].arrivalCount = arrivalCount;
            printf("Frame replaced\n");
        }
        else
        {
            page_hit++;

            // update the frequency and arrival count of the page
            printf("Page hit for page %d\n", PAGES[i]);
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

        // print the frames
        for (int j = 0; j < total_frames; j++)
        {
            printf("%d\t %d\t %d\t\n", FRAMES[j].page_number, FRAMES[j].frequency, FRAMES[j].arrivalCount);
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hit);
}
