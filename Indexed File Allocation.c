#include<stdio.h>
#include<stdlib.h>
void main(){
    int f[50], index[10],i, n, st, len, j, c, k, ind,count=0;
    for(i=0;i<50;i++)
        f[i]=0;
    do{
        x: printf("Enter the index block and length: ");
        scanf("%d %d",&ind, &n);
        if (f[ind]==1){
            printf("%d index is already allocated.\n",ind);
            goto x;
        }
        y: count=0;
        printf("Enter the %d indices for the index %d on the disk: ",n,ind);
        for(i=0;i<n;i++){
            scanf("%d", &index[i]);
            if(f[index[i]]==0)
                count++;
        }
        if(count==n){
            for(j=0;j<n;j++)
                f[index[j]]=1;
            printf("Allocated, File Indexed.\n");
            for(k=0;k<n;k++)
                printf("%d ---> %d : %d\n",ind,index[k],f[index[k]]);
        }
        else{
            printf("File in the index is already allocated.\n");
            goto y;
        }
        printf("\nContinue?(0/1): ");
        scanf("%d", &c);
        printf("\n");
    }while(c);
}