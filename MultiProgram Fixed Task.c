#include<stdio.h>

void main() {
    int n;
    printf("Enter memory size: ");
    scanf("%d", &n);
    int m = n;
    int k;
    int count = 0;
    while (printf("\nContinue?(y/n): y\n") && count++ < 3) {
        printf("Enter process size: ");
        scanf("%d", &k);
        m -= k;
        printf("Process Allocated.\n");
        printf("Remaining size is %d.\n", m);
    }
    printf("Enter process size: ");
        scanf("%d", &k);
    printf("Not Enough space for the process.\n");
    printf("\nContinue?(y/n): n\n");
    printf("External fragmentation is %d.\n", m);
}