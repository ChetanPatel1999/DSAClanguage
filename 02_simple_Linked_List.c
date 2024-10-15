//simple linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head)
{
  printf("display linked list element : ");  
  struct node * temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");

}
void main()
{
  struct node *head,*second,*third,*fourth;
  head=(struct node *)malloc(sizeof(struct node));
  second=(struct node *)malloc(sizeof(struct node));
  third=(struct node *)malloc(sizeof(struct node));
  fourth=(struct node *)malloc(sizeof(struct node));
  head->data=12;
  head->next=second;
  second->data=34;
  second->next=third;
  third->data=56;
  third->next=fourth;
  fourth->data=78;
  fourth->next=NULL;
  display(head);
}