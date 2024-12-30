//circuler queue code in c language
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int rear;
    int front;
    int *arr;
} typedef queue;
int is_empty(queue *q)
{
    if (q->front==-1)
    {
        return 1;
    }
    return 0;
}
int is_full(queue *q)
{
    if (((q->rear)+1)%q->size == q->front)
    {
        return 1;
    }
    return 0;
}
void enqueue(queue *q, int n)
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
        else
        {
            q->rear=(q->rear+1)%q->size;
        }
        q->arr[q->rear] = n;
    }
}
int dequeue(queue *q)
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
    else{
        q->front=(q->front+1)%q->size;
    }
    return a;
}
void main()
{
    queue q;
    q.size = 3;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 55);
    enqueue(&q, 34);
    printf("dequeue element is %d\n",dequeue(&q));
    printf("dequeue element is %d\n",dequeue(&q));
    enqueue(&q,800);
    enqueue(&q, 1200);
    printf("dequeue element is %d\n",dequeue(&q));
    printf("dequeue element is %d\n",dequeue(&q));
    // if(is_empty(&q))
    // {
    //     printf("queue is underflow \n");
    // }
    // if(is_full(&q))
    // {
    //      printf("queue is overflow \n");
    // }
}