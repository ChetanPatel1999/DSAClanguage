#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void insertion(struct node **root, int data)
{
    struct node *current = *root;
    struct node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (current->data == data)
        {
            printf("duplicate node");
            return;
        }
        else if (current->data < data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    if (parent == NULL)
    {
        // Tree was empty
        *root = createnode(data);
    }
    else if (data < parent->data)
    {
        parent->left = createnode(data);
    }
    else
    {
        parent->right = createnode(data);
    }
}
void main()
{
    struct node *root = NULL;
    insertion(&root, 12);
    insertion(&root, 25);
    insertion(&root, 55);
    insertion(&root,5);
    inorder(root);
}