#include<stdio.h>
#define MAX 100
void merge(int arr1[],int arr2[],int arr3[],int n1,int n2);
int main()
{
    int i,n1,n2,arr1[MAX],arr2[MAX],arr3[2*MAX];
    printf("Enter the size of first array : ");
    scanf("%d",&n1);
    printf("Enter element in first array ; ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Element in first array : ");
    for(i=0;i<n1;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\nEnter the size of second array : ");
    scanf("%d",&n2);
    printf("Enter element in second array ; ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("Element in second array : ");
    for(i=0;i<n2;i++)
    {
        printf("%d ",arr2[i]);
    }
    merge(arr1,arr2,arr3,n1,n2);
    printf("\n\nAfter merge sort array is : ");
    for(i=0;i<n1+n2;i++)
    {
        printf("%d ",arr3[i]);
    }
}
void merge(int arr1[],int arr2[],int arr3[],int n1,int n2)
{
    int i=0,j=0,k=0;
    while(i<=n1 && j<=n2)
    {
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else
            arr3[k++]=arr2[j++];
    }
    while(i<=n1)
        arr3[k++]=arr1[i++];
    while(j<=n2)
        arr3[k++]=arr2[j++];
}
