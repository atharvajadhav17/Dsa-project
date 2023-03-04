#include<stdio.h>
#include<stdlib.h>
#include"DLL.h"


// typedef struct DLL_node
// {
//           int data;
//           struct DLL_node *next;
//           struct DLL_node *previous;
// } DLL_node;
// typedef DLL_node *DLlist;


// void init_DLlist(DLlist *L)
// {
//           *L = NULL;
//           return;
// }


// void insert_begin(DLlist *L, int d)
// {
//           DLL_node *nn, *p;
//           nn = (DLL_node *)malloc(sizeof(DLL_node));
//           nn->data = d;
//           nn->next = NULL;
//           nn->previous = NULL;
//           if (*L == NULL)
//           {
//                     *L = nn;
//                     return;
//           }
//           else
//           {
//                     p = *L;
//                     *L = nn;
//                     nn->next = p;
//                     p->previous = nn;
//                     return;
//           }
// }


// void delete_a_DLL_node(DLlist *L, int d, int pos)
// {
//           DLL_node *p, *q, *r;
//           int count;
//           p = *L;
//           q = NULL;
//           r = NULL;
//           if (p == NULL)
//           {
//                     return;
//           }
//           while (p != NULL)
//           {
//                     count++;
//                     p = p->next;
//           }
//           p = *L;

//           if (count == 1)
//           {
//                     if (p->data == d)
//                     {
//                               *L = NULL;
//                               free(p);
//                     }
//                     else
//                     {
//                               return;
//                     }
//           }
//           q = *L;
//           if (count > 1 && pos == 1)
//           {
//                     if (p->data == d)
//                     {
//                               q = q->next;
//                               q->previous = NULL;
//                               *L = p->next;
//                               free(p);
//                     }
//                     else
//                     {
//                               return;
//                     }
//           }
//           else if (count > 1 && pos != 1)
//           {
//                     p = p->next;
//                     while (p && p->data != d)
//                     {
//                               q = p;
//                               p = p->next;
//                     }
//                     if (p != NULL)
//                     {
//                               q->next = p->next;
//                               r = q;
//                               q = q->next;
//                               q->previous = r;

//                               free(p);
//                     }
//                     else
//                     {
//                               return;
//                     }
//           }
// }


// void init_Queue(Queue *Q1)
// {
//     Q1->front=NULL;
//     Q1->rear=NULL;
  
//     return;
// }

// int isQueueEmpty(Queue* Q1)
// {
//     return Q1->rear == NULL;
// }


// int is_capacity_full(Queue *Q1){
//     if(Q1->front==NULL && Q1->rear==NULL) return 0;
//     else if(Q1->front->next==Q1->rear) return 0;
//     else return 1;


// }

// void deQueue(Queue* Q1)
// {
//     if (isQueueEmpty(Q1))
//         return;
//     if (Q1->front == Q1->rear)
//         Q1->front = NULL;
//     QNode* temp = Q1->rear;
//     Q1->rear = Q1->rear->prev;
  
//     if (Q1->rear)
//         Q1->rear->next = NULL;
  
//     free(temp);
//     return;
// }

// void Enqueue(Queue* Q1,hash *h, int order_num)
// {
//     if (is_capacity_full(Q1)) {
//         h->array[(Q1->rear->orderno)%h->size] = NULL;
//         deQueue(Q1);
//     }
//     QNode *nn=(QNode*)malloc(sizeof(QNode));
//     nn->next=nn->prev=NULL;
//     nn->orderno=order_num;
//     nn->next = Q1->front;
  
//     // If Q1 is empty, change both front and rear pointers
//     if (isQueueEmpty(Q1))
//         Q1->rear = Q1->front = nn;
//     else // Else change the front
//     {
//         Q1->front->prev = nn;
//         nn->next=Q1->front;
//         Q1->front = nn;
//     }
  
//     // Add page entry to hash also
//     h->array[(order_num)%h->size] = nn;
//     return;
     
// }

// void display_queue(Queue *Q1){
   
//     if(isQueueEmpty) return;
//      QNode *p=Q1->front;
//      while(p){
//            printf("%d",p->orderno);
//            p=p->next;

//      }
// }
QNode* newQNode(unsigned order_num)
{
	// Allocate memory and assign 'order_num'
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->orderno = order_num;

	// Initialize prev and next as NULL
	temp->prev = temp->next = NULL;

	return temp;
}
Queue* createQueue(int numberOfFrames)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	// The queue is empty
	queue->count = 0;
	queue->front = queue->rear = NULL;

	// Number of frames that can be stored in memory
	queue->numberOfnodes = numberOfFrames;

	return queue;
}

hash* createhash(int capacity)
{
	// Allocate memory for hash
	hash* h = (hash*)malloc(sizeof(hash));
	h->size = capacity;

	// Create an array of pointers for referring queue nodes
	h->array = (QNode**)malloc(h->size * sizeof(QNode*));

	// Initialize all hash entries as empty
	int i;
	for (i = 0; i < h->size; ++i)
		h->array[i] = NULL;

	return h;
}

int AreAllNodesFull(Queue* queue)
{
	return queue->count == queue->numberOfnodes;
}

// A utility function to check if queue is empty
int isQueueEmpty(Queue* queue)
{
	return queue->rear == NULL;
}

// A utility function to delete a frame from queue
void deQueue(Queue* queue)
{
	if (isQueueEmpty(queue))
		return;

	// If this is the only node in list, then change front
	if (queue->front == queue->rear)
		queue->front = NULL;

	// Change rear and remove the previous rear
	QNode* temp = queue->rear;
	queue->rear = queue->rear->prev;

	if (queue->rear)
		queue->rear->next = NULL;

	free(temp);

	// decrement the number of full frames by 1
	queue->count--;
}

// A function to add a page with given 'order_num' to both queue
// and hash
void Enqueue(Queue* queue, hash* h, int order_no)
{
	// If all frames are full, remove the page at the rear
	if (AreAllNodesFull(queue)) {
		// remove page from hash
		h->array[queue->rear->orderno] = NULL;
		deQueue(queue);
	}

	// Create a new node with given page number,
	// And add the new node to the front of queue
	QNode* temp = newQNode(order_no);
	temp->next = queue->front;

	// If queue is empty, change both front and rear pointers
	if (isQueueEmpty(queue))
		queue->rear = queue->front = temp;
	else // Else change the front
	{
		queue->front->prev = temp;
		queue->front = temp;
	}

	// Add page entry to hash also
	h->array[order_no] = temp;

	// increment number of full frames
	queue->count++;
}

// This function is called when a page with given 'pageNumber' is referenced
// from cache (or memory). There are two cases:
// 1. Frame is not there in memory, we bring it in memory and add to the front
// of queue
// 2. Frame is there in memory, we move the frame to front of queue
void LRU_order(Queue* queue, hash* h, int order_num)
{
	QNode* reqPage = h->array[order_num];

	// the page is not in cache, bring it
	if (reqPage == NULL)
		Enqueue(queue, h, order_num);

	// page is there and not at front, change pointer
	else if (reqPage != queue->front) {
		// Unlink rquested page from its current location
		// in queue.
		reqPage->prev->next = reqPage->next;
		if (reqPage->next)
			reqPage->next->prev = reqPage->prev;

		// If the requested page is rear, then change rear
		// as this node will be moved to front
		if (reqPage == queue->rear) {
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}

		// Put the requested page before current front
		reqPage->next = queue->front;
		reqPage->prev = NULL;

		// Change prev of current front
		reqPage->next->prev = reqPage;

		// Change front to the requested page
		queue->front = reqPage;
	}
}
  