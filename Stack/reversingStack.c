#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10 

int a[MAXSIZE],top = -1,b[MAXSIZE];

void push(int data)
{
    if(top == (MAXSIZE - 1))
    {
        printf("Stack is full\n");
    }
    else 
    {
        top++;
        a[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleted : %d\n",a[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack :");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack top most element : %d\n",a[top]);
    }
}

void reverse()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    for(int i=top;i>=0;i--)
    {
        b[top-i] = a[i];
    }
    for(int i=top;i>=0;i--)
    {
        a[i] = b[i];
    }
}

int main()
{
    int op,value;
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Reverse\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&op);

        switch (op)
        {
            case 1 :
                printf("Enter the value to insert:");
                scanf("%d",&value);
                push(value);
                break;
            
            case 2 :
                pop();
                break;
            
            case 3:
                display();
                break;

            case 4:
                peek();
                break;
            
            case 5:reverse();
                break;

            case 6:exit(0);
                break;

            default: printf("Invalid Input");
            break;
        }
    }

    return 0;
}