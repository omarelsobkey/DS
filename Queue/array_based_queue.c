#include "array_based_queue.h"

// create a queue by initializing its variables with the start of the queue values
void CreateQueue(Queue *QueuePtr) {
    QueuePtr->front = 0;
    QueuePtr->rear = -1;
    QueuePtr->size = 0;
}

// add element to the queue
void Append(QueueEntry EntryValue, Queue *QueuePtr) {
    // check if the queue is full
    if (QueueFull(QueuePtr)) {
        // append the new element to the queue
        QueuePtr->rear = (QueuePtr->rear + 1) % MAXQUEUE; // to make it a circular queue
        QueuePtr->entry[QueuePtr->rear] = EntryValue;
        QueuePtr->size++;
    } else {}
}

// remove the front element from the queue
void Serve(QueueEntry *EntryValuePtr, Queue *QueuePtr) {
    // check if the queue is empty
    if (QueueEmpty(QueuePtr)) {
        // remove the front element from the queue
        *EntryValuePtr = QueuePtr->entry[QueuePtr->front];
        QueuePtr->front = (QueuePtr->front + 1) % MAXQUEUE; // to make it a circular queue
        QueuePtr->size--;
    } else {}
}

// access all the elements of the stack to apply an action to all of them
void TraverseQueue(Queue *QueuePtr, void(*pf)(QueueEntry)) {
    int pos, size;
    for (pos = QueuePtr->front, size = 0; size < QueuePtr->size; size++) {
        (*pf)(QueuePtr->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}

// check if the queue is empty
int QueueEmpty(Queue *QueuePtr) {
    return !QueuePtr->size;
}

//check if the queue is full
int QueueFull(Queue *QueuePtr) {
    return (QueuePtr->size == MAXQUEUE);
}

// return the size of the queue
int QueueSize(Queue *QueuePtr) {
    return QueuePtr->size;
}

// clear all the elements of the queue
void ClearQueue(Queue *QueuePtr) {
    QueuePtr->front = 0;
    QueuePtr->rear = -1;
    QueuePtr->size = 0;
}