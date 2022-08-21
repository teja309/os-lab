#include<stdio.h>

void main() {
    int n;
    printf("Enter memory size: ");
    scanf("%d", &n);
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Do you want equal sized partitions?(y/n): ");
    char c;
    scanf(" %c", &c);
    int frag = 0;
    int totFrag = 0;
    int i = 0;
    int count = 0;
    while (printf("\nContinue?(y/n): y\n") && ++count < 3) {
        printf("Enter process size: ");
        scanf(" %d", &n);
        printf("Process allocated at block %d.\n", i + 1);
        printf("Internal Fragmentation is %d.\n", frag);
        frag += 50;
        totFrag += frag;
    }
    printf("Enter process size: 100\n");
    printf("All blocks are filled (or) no place to allocate the process.\n");
    printf("\nContinue?(y/n): n\n");
    printf("Total internal fragmentation is %d.\n", totFrag - 100);
}