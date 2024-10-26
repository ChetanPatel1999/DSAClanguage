#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createTreeRecursivly()

{
    struct node *temp;
    int data, choice;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nPress 0 to exit\n");
    printf("Press 1 for new node\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return NULL;
    }
    else
    {
        printf("Enter the data:");
        scanf("%d", &data);
        temp->data = data;
        printf("Enter the left child of %d", data);
        temp->left = createTreeRecursivly();
        printf("Enter the right child of %d", data);
        temp->right = createTreeRecursivly();
        return temp;
    }
}
struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
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
void search(struct node *root,int data,int *f)
{
    if (root != NULL)
    {
        search(root->left,data,f);
        if(root->data==data)
        {
            *f=1;
        }
        search(root->right,data,f);
    }
   
}
void main()
{
    struct node *root, *l1, *r1, *l1l2, *l1r2, *r1l2, *r1r2;
    root = createnode(5);
    l1 = createnode(9);
    r1 = createnode(10);
    l1l2 = createnode(12);
    l1r2 = createnode(33);
    r1l2 = createnode(14);
    r1r2 = createnode(25);
    root->left = l1;
    root->right = r1;
    l1->left = l1l2;
    l1->right = l1r2;
    r1->left = r1l2;
    r1->right = r1r2;
    printf("\npre order : ");
    preorder(root);
    printf("\npost order : ");
    postorder(root);
    printf("\nin order : ");
    inorder(root);
    int f=0;
    search(root,33,&f);
    if(f)
    {
        printf("\nfind");
    }
    else
    {
        printf("\nnot find");
    }
}
