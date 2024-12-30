//queue with linked list 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rear = NULL;
void enqueue(int num)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->next = NULL;
    if (front == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}
int dequeue()
{
    int a = -1;
    if (front == NULL)
    {
        printf("queue is empty\n");
        return a;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        a = temp->data;
        free(temp);
        return a;
    }
}
void main()
{
    printf("%d element is deleted\n", dequeue());
    enqueue(12);
    enqueue(55);
    enqueue(13);
    enqueue(89);
    printf("%d element is deleted\n", dequeue());
    printf("%d element is deleted\n", dequeue());
    printf("%d element is deleted\n", dequeue());
    printf("%d element is deleted\n", dequeue());
    printf("%d element is deleted\n", dequeue());
    enqueue(500);
    printf("%d element is deleted\n", dequeue());
}