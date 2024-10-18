//simple doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void displayf(struct node *head)
{
    printf("display doubly linked list element Forword: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displayr(struct node *fourth)
{
    printf("display doubly linked list element reversed: ");
    struct node *temp = fourth;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->prev=NULL;
    head->data = 12;
    head->next = second;
    second->prev=head;
    second->data = 34;
    second->next = third;
    third->prev=second;
    third->data = 56;
    third->next = fourth;
    fourth->prev=third;
    fourth->data = 78;
    fourth->next = NULL;
    displayf(head);
    displayr(fourth);
}
