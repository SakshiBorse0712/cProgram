// Time Complexity - O(n*log n) and Space Complexity - O(n)
#include <stdio.h>

void merge(int a[100],int n,int left ,int mid ,int right)
{
    int n1,n2;
    n1 = mid - left + 1;
    n2 = right - mid;
    int leftArray[n1],rightArray[n2];

    for(int i=0;i<n1;i++)
    {
        leftArray[i] = a[left + i];
    }

    for(int j=0;j<n2;j++)
    {
        rightArray[j] = a[mid + 1 + j];
    }

    int i=0,j=0,k=left;
    while(i < n1  &&  j < n2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }

}

void mergeSort(int a[100],int n,int left,int right)
{
    if(left < right)
    {
        int mid = left + (right-left) /2 ;
        mergeSort(a,n,left,mid);
        mergeSort(a,n,mid+1,right);
        merge(a,n,left,mid,right);
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

    mergeSort(a,n,0,n-1);
    printf("Sorted Array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}