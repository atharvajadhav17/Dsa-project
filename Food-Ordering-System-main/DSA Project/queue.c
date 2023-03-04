#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "queue.h"
#include "main.h"
#include"linkedlist.h"

void init_Queue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue *q, char *Food, int Price, char *address, int quant)
{
    cart *nn = (cart *)malloc(sizeof(cart));
    int i = 0;
    while (Food[i] != '\0')
    {
        nn->food[i] = Food;
    }
    nn->price = Price;
    nn->addr = address;
    nn->quantity = quant;
    nn->next = NULL;
    if (q->front == NULL)
    {
        q->front = nn;
        q->rear = nn;
    }
    else
    {
        q->rear->next = nn;
        q->rear = nn;
    }
}

char *deQueue(Queue *q)
{
    cart *p;
    p = q->front;
    char *x;

    if (q->front == NULL)
        return INT_MIN;
    x = p->food;
    if (q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = p->next;
        free(p);
    }
    return x;
}

int is_Queue_Empty(Queue q)
{
    return (q.front == NULL);
}

int is_Queue_Full(Queue q)
{
    return 0;
}