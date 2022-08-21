#include <stdio.h>
#include <string.h>

typedef struct {
    char pName[20];
    int pRes;
} process;

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", p[i].pName);
        printf("Enter the resources required for process %d: ", i + 1);
        scanf("%d", &p[i].pRes);
    }
    int avalRes;
    printf("Enter the available resources: ");
    int flag = 1;
    scanf("%d", &avalRes);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pRes > p[j].pRes) {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
        if (p[i].pRes > avalRes) {
            printf("No safe sequence exists");
            flag = 0;
        }
    }
    if (flag) {
        printf("Safe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("(%s, %d)", p[i].pName, p[i].pRes);
            if (i < n - 1) {
                printf(" -> ");
            }
        }
    }
}
