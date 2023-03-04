#include <stdio.h>
#include <stdlib.h>
//#include "DLL.h"

typedef struct QNode
{
    struct QNode *prev, *next;
    int orderno;

} QNode;

typedef struct Queue
{
    QNode *front, *rear;
} Queue;

typedef struct hash
{
    int size;
    QNode **array;
} hash;

hash *init_hash(int s)
{
    hash *h = (hash *)malloc(sizeof(hash));
    h->size = s;
    h->array = (QNode **)malloc(h->size * sizeof(QNode *));
    int i=0;
    for(i=0;i<h->size;i++){
        h->array[i]=(QNode*)malloc(h->size * sizeof(QNode));
    }

    for (i = 0; i < h->size; ++i)
        h->array[i] = NULL;

    return h;
}

void init_Queue(Queue *Q1)
{
    Q1->front = NULL;
    Q1->rear = NULL;

    return;
}

int isQueueEmpty(Queue *Q1)
{
    return Q1->rear == NULL;
}

int is_capacity_full(Queue *Q1)
{
    if (Q1->front == NULL && Q1->rear == NULL)
        return 0;
    else if (Q1->front->next == Q1->rear)
        return 0;
    else
        return 1;
}

void deQueue(Queue *Q1)
{
    if (isQueueEmpty(Q1))
        return;
    if (Q1->front == Q1->rear)
        Q1->front = NULL;
    QNode *temp = Q1->rear;
    Q1->rear = Q1->rear->prev;

    if (Q1->rear)
        Q1->rear->next = NULL;

    free(temp);
    return;
}

void Enqueue(Queue *Q1, hash *h, int order_num)
{
    if (is_capacity_full(Q1))
    {
        h->array[(Q1->rear->orderno) % h->size] = NULL;
        deQueue(Q1);
    }
    QNode *nn = (QNode *)malloc(sizeof(QNode));
    nn->next = nn->prev = NULL;
    nn->orderno = order_num;
    nn->next = Q1->front;

    // If Q1 is empty, change both front and rear pointers
    if (isQueueEmpty(Q1))
        Q1->rear = Q1->front = nn;
    else // Else change the front
    {
        Q1->front->prev = nn;
        nn->next = Q1->front;
        Q1->front = nn;
    }

    // Add page entry to hash also
    h->array[(order_num) % h->size] = nn;
    return;
}

void display_queue(Queue *Q1)
{

    if (isQueueEmpty)
        return;
    QNode *p = Q1->front;
    while (p)
    {
        printf("%d", p->orderno);
        p = p->next;
    }
}
void LRU_order(Queue *queue, hash *h, int order_num)
{
    // QNode *order = h->array[(order_num) % h->size];
    if(isQueueEmpty(queue)) Enqueue(queue, h, order_num);


    QNode *order = NULL;
    if(queue->front->orderno==order_num) order=queue->front;
    else if(queue->rear->orderno==order_num) order=queue->rear;
    else if(queue->front->next->orderno==order_num) order=queue->front->next;
    else Enqueue(queue, h, order_num);
    

    // if the order is not in cache
    if (order == NULL)
        Enqueue(queue, h, order_num);

    // order is there,but not at front position
    else if (order != queue->front)
    {
        order->prev->next = order->next;
        if (order->next)
            order->next->prev = order->prev;

        // If the requested order is rear, then change rear
        if (order == queue->rear)
        {
            queue->rear = order->prev;
            queue->rear->next = NULL;
        }

        // Put the requested order before current front
        order->next = queue->front;
        order->prev = NULL;

        order->next->prev = order;

        queue->front = order;
    }
}

int main()
{
    Queue Q1;
    hash h1;
    init_Queue(&Q1);
    init_hash(3);

    LRU_order(&Q1, &h1, 1);
    display_queue(&Q1);
    LRU_order(&Q1, &h1, 2);
    display_queue(&Q1);
    LRU_order(&Q1, &h1, 3);
    display_queue(&Q1);
    LRU_order(&Q1, &h1, 4);
    display_queue(&Q1);
    //  LRU_order(&Q1,&h1,1);
}
