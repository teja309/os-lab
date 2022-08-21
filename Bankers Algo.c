#include <malloc.h>
#include <stdio.h>

typedef struct {
  int *max;
  int *need;
  int *alloc;
  int isDone;
} process;

int n;
int m;

int *alloc() { return malloc(m * sizeof(int)); }

void read(int *arr) {
  for (int i = 0; i < m; i++) {
    scanf("%d", &arr[i]);
  }
}

void add(int *arr1, const int *arr2) {
  for (int i = 0; i < m; i++) {
    arr1[i] += arr2[i];
  }
}

void sub(int *arr1, const int *arr2) {
  for (int i = 0; i < m; i++) {
    arr1[i] -= arr2[i];
  }
}

int canExec(const int *available, const int *need) {
  for (int i = 0; i < m; i++) {
    if (need[i] > available[i])
      return 0;
  }
  return 1;
}

void main() {
  printf("Enter number of processes: ");
  scanf("%d", &n);
  printf("Enter number of resources: ");
  scanf("%d", &m);
  process p[n];

  for (int i = 0; i < n; i++) {
    p[i].max = alloc();
    p[i].alloc = alloc();
    p[i].need = alloc();
    p[i].isDone = 0;
  }

  printf("Enter max alloc matrix,\n");
  for (int i = 0; i < n; i++) {
    read(p[i].max);
  }

  printf("Enter alloc matrix,\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &p[i].alloc[j]);
      p[i].need[j] = p[i].max[j] - p[i].alloc[j];
    }
  }

  printf("Enter total resources: ");
  int *totalResources = alloc();
  read(totalResources);
  int *avail = alloc();
  for (int i = 0; i < m; i++) {
    avail[i] = totalResources[i];
  }

  for (int i = 0; i < n; i++) {
    sub(avail, p[i].alloc);
  }

  int isPExec = 1;
  int noOfExecP = 0;
  while (isPExec) {
    isPExec = 0;
    for (int i = 0; i < n; i++) {
      if (canExec(avail, p[i].need) && !p[i].isDone) {
        isPExec = 1;
        sub(avail, p[i].need);
        add(p[i].alloc, p[i].need);
        sub(p[i].need, p[i].need);
        p[i].isDone = 1;
        noOfExecP++;
        printf("\nProcess %d is finished\n", i);
        add(avail, p[i].alloc);
        printf("Available resources: ");
        for (int j = 0; j < m; j++) {
          printf("%d ", avail[j]);
        }
      }
    }
    if (!isPExec) {
      if (noOfExecP == n)
        printf("\nSystem is in safe mode.\n");
      else
        printf("\nSystem is in unsafe mode.\n");
    }
  }
}
