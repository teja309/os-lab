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

int findMin(int dict[], int size) {
    int minIndex = 0;
    int min = dict[0];
    for (int i = 1; i < size; i++) {
        if (dict[i] < min) {
            min = dict[i];
            minIndex = i;
        }
    }
    return minIndex;
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
    int dictionary[frameSize];
    int occupied = 0;
    for (int i = 0; i < frameSize; i++) {
        currentFrames[i] = -1;
    }
    int index = 0;
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        if (occupied < frameSize) {
            currentFrames[occupied] = pages[i];
            dictionary[occupied++] = index++;
            pageFaults++;
        } else if (isPresent(currentFrames, frameSize, pages[i]) != -1) {
            dictionary[isPresent(currentFrames, frameSize, pages[i])] = index++;
        } else {
            currentFrames[findMin(dictionary, frameSize)] = pages[i];
            dictionary[findMin(dictionary, frameSize)] = index++;
            pageFaults++;
        }
        print(currentFrames, frameSize);
    }
    printf("Number of page faults: %d\n", pageFaults);
    printf("Page fault rate: %f%\n", (pageFaults * 100.0) / n);
}
