# include <stdio.h>
# include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char x)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void preOrder(struct Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%c ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    inOrder(root->left);
    printf("%c ",root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ",root->data);
}

int main()
{
    struct Node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');

    root->left->left = createNode('D');
    root->left->right = createNode('E');

    root->right->left = createNode('F');
    root->right->right = createNode('G');

    printf("Preorder Traversal : ");
    preOrder(root);
    printf("\nInoder Traversal : ");
    inOrder(root);
    printf("\nPostorder Traversal : ");
    postOrder(root);
    return 0;
}