#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void swap(int *i,int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void preorder(int a[],int n,int i)
{
    if(i>n)
    {
        return;
    }
    printf("%d ",a[i]);
    preorder(a,n,2*i+1);
    preorder(a,n,2*i+2);
}

int left(int i)
{
    return (2*i+1);
}

int right(int i)
{
    return (2*i+2);
}

void Max_Heapify(int a[],int i,int n) // n = heap size
{
    int l = left(i);
    int r = right(i);
    int lenght;

    if(l < n  && a[l] > a[i])
    {
        lenght = l;
    }
    else 
    {
        lenght = i;
    }

    if(r < n && a[r] > a[i])
    {
        lenght = r;
    }

    if(lenght != i)
    {
        swap(&a[i] , &a[lenght]);
        Max_Heapify(a,lenght,n);
    }
}

void build_Max_Heap(int a[],int n)
{
    for(int i= n/2-1;i>=0;i--)
    {
        Max_Heapify(a,i,n);
    }
}

int insertion(int a[],int n,int data)
{
    a[n] = data;
    int i = n;

    while(i>0  &&  a[(i-1)/2] < a[i])
    {
        swap(&a[(i-1)/2],&a[i]);
        i=(i-1)/2;
    }

    return n+1;
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[MAX_SIZE] = {50, 30, 40, 10, 20};
    int n = 5;

    int value;
    printf("Original Array : ");
    print(a,n);

    build_Max_Heap(a,n);

    printf("After Building Max Heap : ");
    print(a,n);

    printf("\nEnter Element to insert :");
    scanf("%d",&value);

    n=insertion(a,n,value);
    print(a,n);
    return 0;
}