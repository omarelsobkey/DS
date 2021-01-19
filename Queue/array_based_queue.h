#define MAXQUEUE 100
#define QueueEntry int

typedef struct queue {
    int front; // indicates the item to be served
    int rear; // indicates the last item
    int size;
    QueueEntry entry[MAXQUEUE];
} Queue;

void CreateQueue(Queue *);

void Append(QueueEntry, Queue *);

void Serve(QueueEntry *, Queue *);

void TraverseQueue(Queue *, void(*)(QueueEntry));

int QueueEmpty(Queue *);

int QueueFull(Queue *);

int QueueSize(Queue *);

void ClearQueue(Queue *);