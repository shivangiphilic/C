#include <stdio.h>
int main()
{
    int i,n,j,counter,tq = 2,x,sum=0;
    printf("Shortest Remaining Time First Scheduling\n");
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int process[n],burst[n],arr[n],wait[n],turn[n],temp[i];
    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i);
        printf("\nBurst Time: ");
        scanf("%d",&burst[i]);
        printf("Arrival Time: ");
        scanf("%d",&arr[i]);
        process[i]=i;
        temp[i] = burst[i];      //temp has org copy of burst times
    }  
    for(sum=0;i=0;x!=0)
    {
        if (burst[i] <= tq && burst[i] > 0)
        {
            //run for tq
            sum +=burst[i];
            burst[i] = 0;
            counter = 1;
        }
        else if(burst[i] > 0)
        {
            //run p for bt
            burst[i] -= tq;
            sum += tq;
        }
        if(burst[i] == 0 && counter == 1)
        {
            x--;
            wait[i] = sum - arr[i] - burst[i];
            //waiting = completion - arrival - burst
            turn[i] = sum - arr[i];
            counter = 0;
        }
        if(i == n-1)
            i = 0;
        else if(arr[i] <= sum)
            i++;
        else
            i = 0;
    }
    printf(" Process   Burst Time\t  Waiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("|   %d\t|\t%d\t|\t%d\t|\t%d     |\n",process[i],temp[i],wait[i],turn[i]);
}