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
void insertion(struct node *root, int data)
{
    while (root != NULL)
    {
        if (root->data == data)
        {
            printf("duplicate node");
        }
        else if (root->data < data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    root = createnode(data);
}
void main()
{
    struct node *root = NULL;
    insertion(root, 12);
    insertion(root, 25);
    insertion(root, 55);
    inorder(root);
}