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
struct node * bst_search(struct node *root,int item)
{
    if(root==NULL || root->data == item )
    {
        return root;
    }
    else if (root->data<item)
    {
        return bst_search(root->right,item);
    }
    else
    {
         return bst_search(root->left,item);
    }
}
void main()
{
    struct node *root, *l1, *r1, *l1l2, *l1r2, *r1l2, *r1r2;
    root = createnode(45);
    l1 = createnode(15);
    r1 = createnode(79);
    l1l2 = createnode(10);
    l1r2 = createnode(20);
    r1l2 = createnode(55);
    r1r2 = createnode(90);
    root->left = l1;
    root->right = r1;
    l1->left = l1l2;
    l1->right = l1r2;
    r1->left = r1l2;
    r1->right = r1r2;
    printf("\nin order : ");
    inorder(root);
    if(bst_search(root,55) != NULL)
    {
        printf("\nfind ");
    }
    else{
        printf("\nnot find");
    }
}
