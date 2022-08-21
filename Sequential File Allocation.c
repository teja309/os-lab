#include <stdio.h>
#include <string.h>

int isEmpty(const int* arr, int start, int size) {
    int i;
    for (i = start; i < start + size; i++) {
        if (arr[i] != 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    printf("Enter disk size: ");
    int DISK_SIZE = 0;
    scanf("%d", &DISK_SIZE);
    int disk[DISK_SIZE];
    memset(disk, 0, sizeof(disk));
    while (printf("Continue?(y/n): ") && (getchar() == 'y' || getchar() == 'y')) {
        printf("Enter block number and size: ");
        int block_number, block_size;
        scanf("%d %d", &block_number, &block_size);
        if (block_number > DISK_SIZE || block_number < 0 || block_size < 0) {
            printf("Invalid block number or size\n");
        } else if (block_number + block_size > DISK_SIZE) {
            printf("Not enough space\n");
        } else if (!isEmpty(disk, block_number, block_size)) {
            printf("Block is already in use\n");
        } else {
            int i;
            for (i = block_number; i < block_number + block_size; i++) {
                disk[i] = 1;
            }
            printf("Block allocated\n");
        }
    }
}