#ifdef ARRAY_BASED_QUEUE

#include "../include/queue.h"

// create a queue by initializing its variables with the start of the queue values
void CreateQueue(Queue *QueuePtr) {
    QueuePtr->front = 0;
    QueuePtr->rear = -1;
    QueuePtr->size = 0;
}

// add element to the queue
void Append(QueueEntry EntryValue, Queue *QueuePtr) {
    // check if the queue is full
    if (!QueueFull(QueuePtr)) {
        // append the new element to the queue
        QueuePtr->rear = (QueuePtr->rear + 1) % MAXQUEUE; // to make it a circular queue
        QueuePtr->entry[QueuePtr->rear] = EntryValue;
        QueuePtr->size++;
    } else {}
}

// remove the front element from the queue
void Serve(QueueEntry *EntryValuePtr, Queue *QueuePtr) {
    // check if the queue is empty
    if (!QueueEmpty(QueuePtr)) {
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

// re-initialize all the front, rear and the size of the queue with thier start values
// clear the elements by user definition
void ClearQueue(Queue *QueuePtr) {
    QueuePtr->front = 0;
    QueuePtr->rear = -1;
    QueuePtr->size = 0;
}

/*****************************************************************************/
#else

#include <stdlib.h>
#include "../include/queue.h"

// creates a queue by initializing all the values with (NULL, zero)
void CreateQueue(Queue *QueuePtr) {
    QueuePtr->front = NULL;
    QueuePtr->rear = NULL;
    QueuePtr->size = 0;
}

// add element to the end of the queue
int Append(QueueEntry EntryValue, Queue *QueuePtr) {
    // create a pointer pointing to position in the memory with the same size as QueueNode
    QueueNode *PtrToNew = (QueueNode *) malloc(sizeof(QueueNode));

    // check if the queue is not full
    if (!PtrToNew) {
        // print the error message :)
        return 0;
    } else {
        PtrToNew->next = NULL;
        PtrToNew->entry = EntryValue;

        // if the queue is empty modify the front position else modify the rear
        if (!QueuePtr->rear) QueuePtr->front = PtrToNew;
        else QueuePtr->rear->next = PtrToNew;

        QueuePtr->rear = PtrToNew;
        QueuePtr->size++;
        return 1;
    }
}

// remove element from the front of the queue
int Serve(QueueEntry *EntryValuePtr, Queue *QueuePtr) {
    QueueNode *PtrToNew = QueuePtr->front;
    // check if the queue is not empty
    if (!PtrToNew) {
        // print the error message :)
        return 0;
    } else {
        *EntryValuePtr = PtrToNew->entry;
        QueuePtr->front = PtrToNew->next;
        free(PtrToNew);

        // if the queue is empty modify the rear position
        if (!QueuePtr->front) QueuePtr->rear = NULL;
        else {}

        QueuePtr->size--;
        return 1;
    }
}

// access all the elements of the queue and do the operation the user chooses on them
void TraverseQueue(Queue *QueuePtr, void(*pf)(QueueEntry)) {
    for (QueueNode *PtrToNew = QueuePtr->front; PtrToNew; PtrToNew = PtrToNew->next) {
        (*pf)(PtrToNew->entry);
    }
}

// check if the queue is empty
int QueueEmpty(Queue *QueuePtr) {
    return !QueuePtr->size;
}

// check if the queue is full
int QueueFull(Queue *QueuePtr) {
    return 0;
}

// return the size of the array
int QueueSize(Queue *QueuePtr) {
    return QueuePtr->size;
}

// clear all the elements of the queue
void ClearQueue(Queue *QueuePtr) {
    while (QueuePtr->front) {
        QueuePtr->rear = QueuePtr->front->next;
        free(QueuePtr->front);
        QueuePtr->front = QueuePtr->rear;
    }
    QueuePtr->size = 0;
}

#endif
