// typedef struct q_node
// {
//           int data;
//           struct q_node *next;

// } q_node;

typedef struct Queue
{
          cart *front;
          cart *rear;

} Queue;

void init_Queue(Queue *q);
void enQueue(Queue *q, char *Food,int Price,char*address,int quant);
char *deQueue(Queue *q);
int is_Queue_Empty(Queue q);
int is_Queue_Full(Queue q);