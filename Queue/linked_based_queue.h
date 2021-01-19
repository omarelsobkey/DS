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