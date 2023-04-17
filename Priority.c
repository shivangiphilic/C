#include <stdio.h>
int main()
{
    int i,n,j,pos,temp;
    printf("Priority Scheduling\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int process[n],burst[n],wait[n],turn[n],priority[n];
    printf("Enter burst times and priority:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d: ",i);
        printf("\n");
        printf("Burst Time: ");
        scanf("%d",&burst[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
        process[i]=i;
    }   
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
  
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;

        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
    }

    wait[0] = 0;
    turn[0] = burst[0];
    for(i=1;i<=n;i++)
    {
        wait[i] = burst[i-1] + wait[i-1];
        turn[i] = turn[i-1] + burst[i];
    }
    printf(" Process   Burst Time\t  Waiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("|   P%d\t|\t%d\t|\t%d\t|\t%d     |\n",process[i],burst[i],wait[i],turn[i]);
}