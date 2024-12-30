//circuler queue code in c language
#include <stdio.h>
#include <stdlib.h>
struct dequeue
{
    int size;
    int rear;
    int front;
    int *arr;
} typedef dequeue;
int is_empty(dequeue *q)
{
    if (q->front==-1)
    {
        return 1;
    }
    return 0;
}
int is_full(dequeue *q)
{
    if ((q->front==0 && q->rear==(q->size-1)) || q->front==q->rear+1)
    {
        return 1;
    }
    return 0;
}
void enqueue_front(dequeue *q, int n)
{
    if (is_full(q))
    {
        printf("queue is full \n");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else if(q->front==0)
        {
            q->front=q->size-1;
        }
        else
        {
            q->front--;
        }
        q->arr[q->front] = n;
    }
}
void enqueue_rear(dequeue *q, int n)
{
    if (is_full(q))
    {
        printf("queue is full \n");
    }
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else if(q->rear==q->size-1)
        {
            q->rear=0;
        }
        else
        {
            q->rear++;
        }
        q->arr[q->rear] = n;
    }
}
int dequeue_front(dequeue *q)
{
    int a = -1;
    if (is_empty(q))
    {
        printf("queue is empty \n");
        return a;
    }
    a=q->arr[q->front];
    if(q->rear==q->front)
    {
        q->front=q->rear=-1;
    }
    else if(q->front==q->size-1){
        q->front=0;
    }
    else{
        q->front++;
    }
    return a;
}
int dequeue_rear(dequeue *q)
{
    int a = -1;
    if (is_empty(q))
    {
        printf("queue is empty \n");
        return a;
    }
    a=q->arr[q->rear];
    if(q->rear==q->front)
    {
        q->front=q->rear=-1;
    }
    else if(q->rear==0){
        q->rear=q->size-1;
    }
    else{
        q->rear--;
    }
    return a;
}
void display(struct dequeue *q)
{
   int i;
   i=q->front;
   printf("Dequeu element are : ");
   while(i!=q->rear)
   {
    printf("%d ",q->arr[i]);
    i=(i+1)%q->size;
   }
   printf("%d ",q->arr[i]);
   printf("\n");
}
int get_rear(struct dequeue *q)
{
    if(is_empty(q))
    {
        printf("dequeue is empty\n");
        return -1;
    }
    else{
        return q->arr[q->rear];
    }
}
int get_front(struct dequeue *q)
{
    if(is_empty(q))
    {
        printf("dequeue is empty\n");
        return -1;
    }
    else{
        return q->arr[q->front];
    }
}
void main()
{
    dequeue q;
    q.size = 4;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue_front(&q, 12);
    enqueue_front(&q, 55);
    enqueue_rear(&q, 34);
    enqueue_rear(&q, 500);
    display(&q); //55 12 34 500
    printf("%d dequeue front element\n",dequeue_front(&q));
    printf("%d dequeue front element\n",dequeue_front(&q));
    printf("%d dequeue front element\n",dequeue_rear(&q));
    printf("%d  front element\n",get_front(&q));
}