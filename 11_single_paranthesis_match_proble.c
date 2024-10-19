//single parenthesis match problem
#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *head = NULL;
int is_empty()
{
    if(head==NULL)
    {
        return 1;
    }
    return 0;
}
void push(char n)
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
char pop()
{
   if(is_empty())
   {
    return 0;
   }
   else{
      struct node *temp=head;
      head=head->next;
      int n=temp->data;
      free(temp);
      return n;
   }
}
int paranthesis(char *exp)
{
  int i;
  for(i=0;i<exp[i]!='\0';i++)
  {
    if(exp[i]=='(')
    {
        push(exp[i]);
    }
    else if(exp[i]==')')
    {
        if(is_empty())
        {
            return 0;
        }
        pop();
    }
  }
  if(is_empty())
  {
    return 1;
  }
  else{
    return 0;
  }
}
void main()
{
  char *exp="(3*3)+(4+4())()()";
  if(paranthesis(exp))
  {
    printf("parenthesis matching");
  }
  else
  {
    printf("parenthesis not matching");
  }
}