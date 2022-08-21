#include<stdio.h>

int isPresent(int f[],int k,int target){
    for(int i=0;i<k;i++){
        if(f[i]==target){
            return 1;
        }
    }
    return 0;
}

void print(int f[],int k){
    for(int i=0;i<k;i++){
        printf("%d ",f[i]);
    }
    printf("\n");
}

void main(){
    int n;
    printf("Enter no of pages");
    scanf("%d",&n);
    int page[n];
    for(int i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter no of frames");
    int k;
    scanf("%d",&k);
    int f[k];
    for(int i=0;i<k;i++){
        f[i]=-1;
    }

    int index=0;
    int pagefault=0;
    for(int i=0;i<n;i++){
        if(!isPresent(f,k,page[i])){
            f[index]=page[i];
            pagefault++;
            index=(index+1)%k;

        }
        print(f,k);

    }

    printf("Page faults %d",pagefault);
    return;

}