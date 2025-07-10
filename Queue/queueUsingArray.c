# include <stdio.h>
# include <stdlib.h>
# define maxsize 10

int a[maxsize],rear=-1,front=-1;

void enqueue(int x)
{
    if(rear == maxsize-1)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front=0;
        rear=0;
        a[rear] = x;
    }
    else
    {
        rear++;
        a[rear] = x;
    }
}

void dequeue()
{
    if(rear ==-1 && front == -1)
    {
        printf("Queue is empty\n");
    }
    else if(rear == front)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if(rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue :");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",a[i]);
        }
    }
    printf("\n");
}

int main()
{
    int value,op;
    while(1)
    {
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter option:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                printf("Enter value to insert:");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Input");
                break;
        }
    }
    return 0;
}