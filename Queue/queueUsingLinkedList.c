# include <stdio.h>
# include <stdlib.h>
# define maxsize 10

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;
struct Node *front = NULL;

void enqueue(int x)
{
    struct Node *newnode;
    newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;

    if(rear == 0 && front == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next=newnode;
        rear = newnode;
    }
}

void display()
{
    struct Node *temp;
    if(rear==0 && front==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(temp->next!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    struct Node *temp;
    temp = front;
    if(rear==0 && front==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = front->next;
        free(temp);
    }
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