#include <stdio.h>

int isPresent(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (target == arr[i]) return i;
    }
    return -1;
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int pages[], int pageLength, int frames[], int frameLength, int position) {
    int dictionary[frameLength];
    for (int i = 0; i < frameLength; i++) dictionary[i] = 0;
    for (int i = position; i < frameLength + position; i++) {
        if (isPresent(frames, frameLength, pages[i]) != -1)
            dictionary[isPresent(frames, frameLength, pages[i])] = 1;
    }
    for (int i = 0; i < frameLength; i++) {
        if (dictionary[i] == 0) return i;
    }
    return 0;
}

void main() {
    printf("Enter number of pages: ");
    int n;
    scanf("%d", &n);
    int pages[n];
    printf("Enter pages: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    int frameSize;
    scanf("%d", &frameSize);
    int currentFrames[frameSize];
    int occupied = 0;
    for (int i = 0; i < frameSize; i++) {
        currentFrames[i] = -1;
    }
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        if (occupied < frameSize) {
            currentFrames[occupied++] = pages[i];
            pageFaults++;
        } else if (isPresent(currentFrames, frameSize, pages[i]) == -1) {
            currentFrames[search(pages, n, currentFrames, frameSize, i)] = pages[i];
            pageFaults++;
        }
        print(currentFrames, frameSize);
    }
    printf("Number of page faults: %d\n", pageFaults);
    printf("Page fault rate: %f%\n", (pageFaults * 100.0) / n);
}
