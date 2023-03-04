#include<stdio.h>
#include<stdlib.h>
#include"DLL.h"
//#include"LRU_Cache.h"

void LRU_order(Queue* queue, hash* h, int order_num)
{
    QNode* order = h->array[(order_num)%h->size];
  
    // if the order is not in cache
    if (order == NULL)
        Enqueue(queue, h, order_num);
  
    // order is there,but not at front position
    else if (order != queue->front) {
        order->prev->next = order->next;
        if (order->next)
            order->next->prev = order->prev;
  
        // If the requested order is rear, then change rear
        if (order == queue->rear) {
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