#include <stdio.h>

int isPresent(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (target == arr[i]) return 1;
    }
    return 0;
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    for (int i = 0; i < frameSize; i++) {
        currentFrames[i] = -1;
    }
    int index = 0;
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        if (!isPresent(currentFrames, frameSize, pages[i])) {
            currentFrames[index++] = pages[i];
            index = index % frameSize;
            pageFaults++;
        }
        print(currentFrames, frameSize);
    }
    printf("Number of page faults: %d\n", pageFaults);
    printf("Page fault rate: %f%\n", (pageFaults * 100.0) / n);
}
