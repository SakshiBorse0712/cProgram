# include <stdio.h>
# include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *linkedList()
{
    struct Node *p,*head;
    int i,n;

    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            p = head;
        }
        else
        {
            p ->next = (struct Node *)malloc(sizeof(struct Node));
            p = p -> next;
        }
        scanf("%d",& p -> data);
    }
    p -> next = NULL;
    return head;
};

void display(struct Node *head)
{
    struct Node *i;
    printf("Linked list:"); 
    for(i=head;i!=NULL;i=i->next)
    {
        printf("%d ",i->data);
    }
}

void insertionAtBeginning()
{
    struct Node *head,*newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert:");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;

    display(newnode);
}

void insertionAtEnd()
{
    struct Node *head,*newnode,*temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter element to insert:");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    
    temp = head; // traverse temp pointer to the end where the newnode is to be inserted
    while((temp->next) !=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode;

    display(newnode);
}


int main()
{
    struct Node *head;
    head = linkedList();
    // display(head);
    insertionAtBeginning();
    return 0;
}