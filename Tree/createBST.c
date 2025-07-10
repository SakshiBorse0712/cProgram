#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int x)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL; 
    return newnode;
} 

struct Node *BST(struct Node *root,int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    if(data < root->data)
    {
        root->left = BST(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = BST(root->right,data);
    }

    return root;
}

void inorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int searchBST(struct Node *root,int key)
{
    while(root != NULL)
    {
        if(key == root->data)
        {
            return 1;
        }
        else if(key < root->left)
        {
           root = root->left ;
        }
        else if(key > root->right)
        {
           root = root->right ;
        }
    }
}

struct Node* insertion(struct Node *root,int x)
{
    if(root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if(x < root->data)
        {
            root->left = insertion(root->left,x);
        }
        else
        {
            root->right = insertion(root->right,x);
        }
    }
}

int main()
{
    struct Node *root = NULL;
    int n, data;

    printf("Enter the no. of elements in tree : ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);

    for (int i=0; i<n; i++)
    {
        scanf("%d",&data);
        root = BST(root, data);
    }

    printf("\nInorder traversal of BST:\n");
    inorder(root);
    return 0;
}