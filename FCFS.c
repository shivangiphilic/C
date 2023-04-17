#include <stdio.h>
int main()
{
    int i,n;
    printf("First Come First Serve Scheduling\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int process[n],burst[n],wait[n],turn[n];
    printf("Enter process numbers and burst times:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&process[i]);
        scanf("%d",&burst[i]);
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
        printf("|   %d\t|\t%d\t|\t%d\t|\t%d     |\n",process[i],burst[i],wait[i],turn[i]);
}