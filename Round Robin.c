#include<stdio.h>
struct rr
{
    int bt,tat,wt,no,dbt;
}p[20];

int main(){
    int j,n,i,q,time=0;
    float wt=0,tat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter burst times,\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].bt);
        p[i].dbt=p[i].bt;
        p[i].no=i;
    }
    printf("Enter time quantum: ");
    scanf("%d",&q);
    int full=n;
    while(full){
        for(i=0;i<n;i++){
            if (p[i].bt>0){
                if(p[i].bt>=q){
                    time+=q;
                    p[i].bt-=q;
                }
                else{
                    time+=p[i].bt;
                    p[i].bt=0;
                }    
                if(p[i].bt==0){
                        p[i].tat=time;
                        full-=1;
                        p[i].wt=time-p[i].dbt;
                        wt+=p[i].wt;
                        tat+=p[i].tat;
                }
            }
        }
    }
    printf("------------------------------------------------------");
    printf("\nProcess No Burst Time TAT\tWT\tCompletion Time\n");
    printf("------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d",p[i].no,p[i].dbt,p[i].tat,p[i].wt,p[i].tat);
        printf("\n");
    }
    printf("-------------------------------------------------------\n");
    printf("Avgwt:%f \t Avgtat:%f\n",wt/n,tat/n);
    printf("-------------------------------------------------------\n");
    return 0;
}