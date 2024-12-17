#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void push(int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("some issue in memorry allocation");
    }
    else
    {
        if (head == NULL)
        {
            new->data = n;
            new->next = NULL;
            head = new;
        }
        else
        {

            new->data = n;
            new->next = head;
            head = new;
        }
    }
}
void dispaly()
{
    if (head == NULL)
    {
        printf("stack is empty we cant display them\n");
    }
    else
    {
        printf("stack element are : ");
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int pop()
{
   if(head==NULL)
   {
    printf("stack is empty\n");
    return -1;
   }
   else{
      struct node *temp=head;
      head=head->next;
      int n=temp->data;
      free(temp);
      return n;
   }
}
void main()
{
    push(12);
    push(45);
    dispaly();
    push(56);
    push(123);
    dispaly();
    printf("%d element is pop\n",pop());
    printf("%d element is pop\n",pop());
    printf("%d element is pop\n",pop());
    printf("%d element is pop\n",pop());
    printf("%d element is pop\n",pop());
    dispaly();
}