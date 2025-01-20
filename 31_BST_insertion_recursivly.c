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
struct node * insertion(struct node *root, int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    else if(data>root->data)
    {
        root->right=insertion(root->right,data);
    }
    else{
        root->left=insertion(root->left,data);
    }
    return root;
}
void main()
{
    struct node *root = NULL;
    root=insertion(root, 12);
    root=insertion(root, 25);
    root=insertion(root, 55);
    root=insertion(root,5);
    inorder(root);
}