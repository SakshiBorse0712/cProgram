# include <stdio.h>
# include <stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(char x)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}

int main()
{
    struct Node *root = createNode('A');
    root->prev = createNode('B');
    root->next = createNode('C');

    root->prev->prev = createNode('D');
    root->prev->next = createNode('E');

    root->next->prev = createNode('F');
    root->next->next = createNode('G');
    return 0;
}