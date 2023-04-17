#include <stdio.h>
int main()
{
    int i,n,j,pos,temp;
    printf("Shortest Job First Scheduling\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int process[n],burst[n],wait[n],turn[n];
    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i);
        scanf("%d",&burst[i]);
        process[i]=i;
    }   
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos])
                pos=j;
        }
  
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
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