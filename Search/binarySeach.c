# include <stdio.h>

int binarySearch(int a[100],int n,int k)
{
    int start=0,end=n-1;
    int mid =( start + end )/2;

    if(mid == k)
    {
        return mid ;
    }
    else if (mid < k)
    {
        start = mid + 1;
    }
    else 
    {
        end = mid -1;
    }
    
}

int main()
{
    int a[100],n,k;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter element to find:");
    scanf("%d",&k);

    printf("Elemnet is found in index:%d\n" ,binarySearch(a,n,k));
    return 0;
}