#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int is_empty(struct stack *s1)
{
    if (s1->top == -1)
    {
        return 1;
    }
    return 0;
}
int is_full(struct stack *s1)
{
    if (s1->top == s1->size - 1)
    {
        return 1;
    }

    return 0;
}
void push(struct stack *s1, int n)
{
    if (is_full(s1))
    {
        printf("stack is overflow ,can not push element\n");
    }
    else
    {
        s1->top++;
        s1->arr[s1->top] = n;
    }
}
int pop(struct stack *s1)
{
    if (is_empty(s1))
    {
        printf("stack is underflow ,can not pop element\n");
    }
    else
    {
        int val = s1->arr[s1->top];
        s1->top--;
        return val;
    }
}
void display(struct stack *s1)
{
    if (is_empty(s1))
    {
        printf("stack is underflow ,can not display element\n");
    }
    else
    {
        int i;
        printf("stack element are : ");
        for (i = 0; i <= s1->top; i++)
        {
            printf("%d ", s1->arr[i]);
        }
        printf("\n");
    }
}
int peek(struct stack *s1)
{
    if (is_empty(s1))
    {
        printf("Stack is empty! No element to peek\n");
        return -1;
    }
    return s1->arr[s1->top]; // Return the top element
}
int count(struct stack *s1)
{
    if (is_empty(s1))
    {
        return -1;
    }
    else
    {
        return s1->top + 1;
    }
}
void main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    push(s1, 34);
    push(s1, 45);
    push(s1, 67);
    printf("total element count : %d\n", count(s1));
    push(s1, 88);
    push(s1, 888);
    printf("total eleemnt count : %d\n", count(s1));
    push(s1, 55);
    display(s1);
    printf("%d element is pop\n", pop(s1));
    printf("total eleemnt count : %d\n", count(s1));
    push(s1, 90);
    display(s1);
    printf("last elemet is %d\n", peek(s1));
}