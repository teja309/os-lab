#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

void createDir(char path[]) {
    mkdir(path, 0700);
}

void createFile(char path[]) {
    fopen(path, "w");
}

void main() {
    printf("Enter the root directory name: ");
    char rootName[100] = "./";
    char temp[20];
    scanf("%s", temp);
    createDir(strcat(rootName, temp));
    rootName[strlen(rootName)] = '/';
    printf("Enter number of users: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter directory name: %s", rootName);
        char dirName[20];
        int temp = strlen(rootName);
        scanf("%s", dirName);
        createDir(strcat(rootName, dirName));
        rootName[strlen(rootName)] = '/';
        printf("Enter number of files in %s: ", rootName);
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            printf("Enter file name %d in %s: ", j + 1, rootName);
            int temp2 = strlen(rootName);
            char fileName[20];
            scanf("%s", fileName);
            createFile(strcat(rootName, fileName));
            rootName[temp2] = '\0';
        }
        rootName[temp] = '\0';
    }
}
