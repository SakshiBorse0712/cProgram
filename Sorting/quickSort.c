// Time Complexity - O(n^2) and Space Complexity - O(log n)
#include <stdio.h>

void swap(int a[100],int n,int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[100],int n,int low,int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a,n,i,j);
        }
    }
    swap(a,n,i+1,high);
    return i+1 ;
}

void quickSort(int a[100],int n,int low,int high)
{
    if(low < high)
    {
        int pi=partition(a,n,low,high);
        quickSort(a,n,low,pi-1);
        quickSort(a,n,pi+1,high);
        
    }
}

int main()
{
    int a[100],n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,n,0,n-1);
    printf("Sorted Array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}