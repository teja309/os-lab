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
    printf("Enter the directory name: ");
    char dirName[100] = "./";
    char temp[20];
    scanf("%s", temp);
    createDir(strcat(dirName, temp));
    dirName[strlen(dirName)] = '/';
    printf("Enter number of files: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the file name %d: ", i + 1);
        char fileName[20];
        int temp = strlen(dirName);
        scanf("%s", fileName);
        createFile(strcat(dirName, fileName));
        dirName[temp] = '\0';
    }
}
