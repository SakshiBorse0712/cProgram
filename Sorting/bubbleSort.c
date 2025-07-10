// Time Complexity - O(n^2) and Space Complexity - O(1)

#include <stdio.h>

void bubbleSort(int a[100],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    bubbleSort(a,n);
    

    return 0;
}