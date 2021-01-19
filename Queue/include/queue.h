#ifdef ARRAY_BASED_QUEUE

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

/***************************************/
#else

#define QueueEntry int

typedef struct queueNode {
    QueueEntry entry;
    struct queueNode *next;
} QueueNode;

typedef struct queue {
    QueueNode *front; // pointer points to the first item in the queue
    QueueNode *rear; // pointer points to the last item in the queue
    int size;
} Queue;

void CreateQueue(Queue *QueuePtr);

int Append(QueueEntry EntryValue, Queue *QueuePtr);

int Serve(QueueEntry *EntryValuePtr, Queue *QueuePtr);

void TraverseQueue(Queue *QueuePtr, void(*pf)(QueueEntry));

int QueueEmpty(Queue *QueuePtr);

int QueueFull(Queue *QueuePtr);

int QueueSize(Queue *QueuePtr);

void ClearQueue(Queue *QueuePtr);

#endif
