//wap to check BST is BST or Not using array.
#include <stdio.h>
#include <stdlib.h>
int arr[7];
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
void  inorder(struct node *root)
{
    static int i=0;
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        arr[i]=root->data;
        i++;
        inorder(root->right);
    }
}
void display(int arr[], int size)
{
    int i;
    printf("\narray element are : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int is_sort()
{
    int i;
    for(i=0;i<7-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            return 0;
        }
    }
    return 1;
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
    display(arr,7);
    if(is_sort())
    {
        printf("tree is BST");
    }
    else
    {
        printf("tree is not BST");
    }
}
