#include<stdio.h>
#define MAX 100
main()
{
    int count=0,n,i,j,arr[MAX],temp;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter the element in array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nArray is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        count=0;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
            if(count==0)
                break;
        }
    }
    printf("\nArray after bubble sort is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
