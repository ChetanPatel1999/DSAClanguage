//simple linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display1(struct node *head)
{
  printf("display linked list element : ");  
  struct node * temp=head;
  do
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  while(temp!=head);
  printf("\n");

}
void display2(struct node *head)
{
  printf("display linked list element : ");  
  struct node * temp=head;
  while(temp->next!=head)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("%d ",temp->data); 
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
  fourth->next=head;
  display1(head);
  display2(head);
}