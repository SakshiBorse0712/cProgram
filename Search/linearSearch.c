#include <stdio.h>

void linearSearch(int a[100],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == k)
        {
            printf("Element is found in index %d\n",i);
        }
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

    linearSearch(a,n,k);


    return 0;
}