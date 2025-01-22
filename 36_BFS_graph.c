// Breadth - first search
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
    if (q->front == -1 || q->front > q->rear)
    {
        return 1;
    }
    return 0;
}
int is_full(queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(queue *q, int n)
{
    if (is_full(q))
    {
        printf("queue is overflow \n");
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
            q->rear++;
        }
        q->arr[q->rear] = n;
    }
}
int dequeue(queue *q)
{
    int a = -1;
    if (is_empty(q))
    {
        printf("queue is underflow \n");
    }
    else
    {
        a = q->arr[q->front];
        q->front++;
    }
    return a;
}
void main()
{
    queue q;
    q.size = 100;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int adjmat[][7] =
        {
            {0, 1, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0},
            {1, 0, 1, 0, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0},
        };
    int visited[] = {0, 0, 0, 0, 0, 0, 0};
    int i, j;
    i = 5;
    enqueue(&q, i);
    visited[i] = 1;
    printf("%d ", i);
    while (!is_empty(&q))
    {
        int node = dequeue(&q);
        for (j = 0; j < 7; j++)
        {
            if (adjmat[node][j] == 1 && visited[j] == 0)
            {
                enqueue(&q, j);
                visited[j] = 1;
                printf("%d ", j);
            }
        }
    }
}