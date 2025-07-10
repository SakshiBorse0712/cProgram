// Time Complexity - O(n^2) and Space Complexity - O(1)

#include <stdio.h>

void insertionSort(int a[100],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("Sorted array:");
    for(i=0;i<n;i++)
    {
            printf("%d ",a[i]);
    }
}

int main()
{
    int a[100],n,i;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);

    return 0;
}