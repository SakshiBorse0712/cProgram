#include <stdio.h>
#include <stdlib.h>

struct Node  
{
    int data;
    struct Node *next;
};

struct Node *Head; 

void push()
{
    int value;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value in stack :");
    scanf("%d",&value);

    if(Head == NULL)
    {
        ptr -> data = value;
        ptr -> next = NULL;
        Head = ptr;
    }
    else
    {
        ptr -> data = value;
        ptr -> next = Head;
        Head = ptr;
    }
}

void pop()
{
    int item;
    struct Node *ptr;
    if(Head == NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        item = Head -> data ;
        ptr = Head;
        Head = Head -> next;
        free(ptr);
    }
}

void display()
{
    struct Node *ptr;
    ptr = Head;
    if(ptr == NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Stack :");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int op,value;
    while(1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&op);

        switch (op)
        {
            case 1 :
                push();
                break;
            
            case 2 :
                pop();
                break;
            
            case 3:
                display();
                break;

            case 4:exit(0);
                break;
        
            default: printf("Invalid Input");
            break;
        }
    }
    printf("\n");
    return 0;
}