# include <stdio.h>
# include <stdlib.h>
# define maxsize 10

int a[maxsize],rear=-1,front=-1;

void enqueue(int x)
{
    if((rear+1)%maxsize == front)
    {
        printf("Queue is empty\n");
    }
    else if(rear == -1 && front == -1)
    {
        front = rear = 0;
        a[(rear+1)%maxsize] = x;
    }
    else
    {
        rear = (rear+1)%maxsize;
        a[rear] = x;
    }
}

void dequeue()
{
    if(rear==-1 && front==-1)
    {
        printf("Queue is empty\n");
    }
    else if(rear == front)
    {
        rear = front = -1;
    }
    else
    {
        front=(front+1)%maxsize;
    }
}

void display()
{
    if(rear == -1 && front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue :");
        for(int i=front;i!=rear;i=(i+1)%maxsize)
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