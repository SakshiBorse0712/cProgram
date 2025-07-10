// Time Complexity - O(n+k) and Space Complexity - O(n)

#include <stdio.h>

int max(int a[100],int n)
{
    int MAX=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i] > MAX)
        {
            MAX = a[i];
        }
    }
    return MAX;
}

void countingSort(int a[100],int b[100],int n)
{
    int k = max(a,n) +1;
    int c[k];
    for(int i=0;i<k;i++)
    {
        c[i] = 0;
    }   

    for(int j=0;j<n;j++)
    {
        c[a[j]]++;
    }

    for(int i=1;i<k;i++)
    {
        c[i] += c[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}

int main()
{
    int a[100],b[100],n,i;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    countingSort(a,b,n);
    printf("Sorted Array:");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",b[i]);
    }

    return 0;
}