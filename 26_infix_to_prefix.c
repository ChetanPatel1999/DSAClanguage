// infix to prefix change operation 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
struct node *head = NULL;
int is_empty()
{
    if (head == NULL)
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
    if (is_empty())
    {
        return 0;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        int n = temp->data;
        free(temp);
        return n;
    }
}
char stack_top()
{
    return head->data;
}
int operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}
char *infix_to_postfix(char *infix)
{
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (!is_empty())
            {
                if (precedence(infix[i]) >=precedence(stack_top()))
                {
                    push(infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = pop();
                    j++;
                }
            }
            else
            {
                push(infix[i]);
                i++;
            }
        }
    }
    while (!is_empty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
void main()
{
    char infix[] = "A*B+C/D";
    strrev(infix);
    char *res =infix_to_postfix(infix);
    strrev(res);
    printf("prifix exp : %s",res);
}