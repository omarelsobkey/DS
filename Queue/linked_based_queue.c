#include <stdlib.h>
#include "linked_based_queue.h"

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