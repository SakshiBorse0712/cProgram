// Time Complexity - O(n^2) and Space Complexity - O(1)

#include <stdio.h>
void selectionSort(int a[100],int n)
{
    int min,i,j,swap;
   for(i=0;i<n;i++)
   {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
                swap = a[j];
                a[j] = a[min];
                a[min] = swap;
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
    selectionSort(a,n);

    return 0;
}