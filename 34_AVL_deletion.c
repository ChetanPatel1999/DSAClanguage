#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
    int height;
};
int height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
struct node *createnode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}
int getbelence_fact(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (height(n->left) - height(n->right));
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct node *right_rotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    // now rotate
    x->right = y;
    y->left = t2;
    // update belance factor
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return x;
}
struct node *left_rotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;
    // now rotate
    y->left = x;
    x->right = t2;
    // update belance factor
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }
    if (root->data > key)
    {
        root->left = insert(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getbelence_fact(root);
    if (bf > 1 && key > root->left->data)
    {
        return right_rotate(root);
    }
    if (bf > 1 && key < root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (bf < -1 && key > root->right->data)
    {
        return left_rotate(root);
    }
    if (bf < -1 && key < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
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
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getbelence_fact(root);
    //LL rotation
    if (bf > 1 && getbelence_fact(root->left)>=0)
    {
        return right_rotate(root);
    }
    //LR rotation
    if (bf > 1 && getbelence_fact(root->left)<0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    //RR rotation
    if (bf < -1 && getbelence_fact(root->right)<=0)
    {
        return left_rotate(root);
    }
    if (bf < -1 && data < getbelence_fact(root->right)>0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    printf("\n");
    inOrder(root);
    root = delete_node(root, 5);
    root = delete_node(root, 6);
    printf("\n");
    preOrder(root);
    printf("\n");
    inOrder(root);
}