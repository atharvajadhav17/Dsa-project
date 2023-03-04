typedef struct QNode
{
    struct QNode *prev, *next;
    int orderno;
   

} QNode;

typedef struct Queue
{
    int count; // Number of filled frames
	int numberOfnodes;
    QNode *front, *rear;
} Queue;

typedef struct hash
{
    int size;
    QNode **array;
} hash;

// hash *init_hash(int s);
// void init_Queue(Queue *Q1);
// int isQueueEmpty(Queue *Q1);
// int is_capacity_full(Queue *Q1);
// void deQueue(Queue *Q1);
// void Enqueue(Queue *Q1, hash *h, int order_num);
// void display_queue(Queue *Q1);
// void LRU_order(Queue* queue, hash* h, int order_num);

QNode* newQNode(unsigned order_num);
Queue* createQueue(int numberOfFrames);
hash* createhash(int capacity);
int AreAllNodesFull(Queue* queue);
int isQueueEmpty(Queue* queue);
void deQueue(Queue* queue);
void Enqueue(Queue* queue, hash* h, int order_no);
void LRU_order(Queue* queue, hash* h, int order_num);
