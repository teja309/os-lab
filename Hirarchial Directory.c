#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

void createFileOrDir(char path[], char isDir) {
    if (isDir == 'd') printf("Enter the directory name at %s: ", path);
    else printf("Enter the file name at %s: ", path);
    char name[20];
    scanf("%s", name);
    int temp = strlen(path);
    if (isDir == 'd') {
        mkdir(strcat(path, name), 0700);
        int temp2 = strlen(path);
        path[temp2] = '/';
        path[temp2 + 1] = '\0';
        printf("Enter number of subdirectories & files under %s: ", path);
        int n;
        scanf(" %d", &n);
        char ch;
        while (n-- > 0) {
            printf("Enter d for directory / f for file: ");
            scanf(" %c", &ch);
            createFileOrDir(path, ch);
        }
    } else fopen(strcat(path, name), "w");
    path[temp] = '\0';
}

void main() {
    char temp[] = "./";
    char path[100];
    createFileOrDir(strcat(path, temp), 'd');
}