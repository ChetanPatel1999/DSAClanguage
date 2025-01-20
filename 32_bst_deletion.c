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
struct node *insertion(struct node *root, int data)
{
    if (root == NULL)
    {
        return createnode(data);
    }
    else if (data > root->data)
    {
        root->right = insertion(root->right, data);
    }
    else
    {
        root->left = insertion(root->left, data);
    }
    return root;
}
struct node *inorder_successor(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *delete_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    // Traverse the tree to find the node to delete
    if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else
    {
        // Node to be deleted found
        // Case 1: Node has no children or
        // Case 2: Only one child
        if (root->left == NULL)
        {
            struct node *temp;
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp;
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // Case 2: Node has two children
            struct node *temp;
            temp = inorder_successor(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}
void main()
{
    struct node *root = NULL;
    root = insertion(root, 12);
    root = insertion(root, 25);
    root = insertion(root, 55);
    root = insertion(root, 5);
    root = insertion(root, 28);
    root = insertion(root, 34);
    root = insertion(root, 45);
    inorder(root);
    printf("\n");
    root = delete_node(root, 5);
    inorder(root);
    printf("\n");
    root = delete_node(root, 34);
    inorder(root);
    printf("\n");
    root = delete_node(root, 25);
    inorder(root);
    printf("\n");
    root = insertion(root, 15);
    inorder(root);
    printf("\n");
}