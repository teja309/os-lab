#include<stdio.h>
void main(){
    int f[50], p,i, st, len, j, c, k, a;
    for(i=0;i<50;i++)
        f[i]=0;
    printf("Enter how many blocks already allocated: ");
    scanf("%d",&p);
    printf("Enter already allocated blocks: ");
    for(i=0;i<p;i++){
        scanf("%d",&a);
        f[a]=1;
    }
    do{
        printf("Enter index starting block and length: ");
        scanf("%d %d", &st,&len);
        k=0;
        if(f[st]==0)
            for(j=st;k < len;j++){
                if(f[j]==0){
                    f[j]=1;
                    printf("%d ---> %d\n",j,f[j]);
                    k++;
                }
            }
        else
            printf("%d starting block is already allocated.\n",st);
        printf("Continue?(0/1): ");
        scanf("%d", &c);
    }while(c);
}