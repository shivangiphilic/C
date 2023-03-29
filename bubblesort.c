#include <stdio.h>
int main()
{
    int i,j,temp,n;
    printf("Enter the number of numbers\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)          //to compare with next element of array
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nAfter : ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
