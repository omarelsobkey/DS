#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// initialize the top location of the stack
void CreateStack(Stack *StackPtr) {
    StackPtr->top = NULL;
    StackPtr->size = 0;
}

// add element to the top of the stack
// change the location of the top
void Push(StackEntry EntryValue, Stack *StackPtr) {
    // malloc returns a pointer of type void
    // (Element*) is casting the returned pointer from void to Element
    Element *PtrToNew = (Element *) malloc(sizeof(Element));
    if (!PtrToNew) {
        // report error to the user :)
    }
    else {
        // the rest of your code
        PtrToNew->entry = EntryValue;
        PtrToNew->next = StackPtr->top;
        StackPtr->top = PtrToNew;
        StackPtr->size++;
    }
}

// remove the top element from the stack after assigning its value to EntryValuePtr
void Pop(StackEntry *EntryValuePtr, Stack *StackPtr) {
    if (StackPtr->top != NULL) {
        // malloc returns a pointer of type void
        // (StackNode*) is casting the returned pointer from void to StackNode
        Element *PtrToNew = StackPtr->top;
        *EntryValuePtr = StackPtr->top->entry;
        StackPtr->top = StackPtr->top->next;
        // make the place pn in memory free to be used again
        free(PtrToNew);
        StackPtr->size--;
    }
}

// check whether the stack is empty or not
int StackEmpty(Stack *StackPtr) {
    return StackPtr->top == NULL;
}

// check whether the stack is full or not
// the stack cant be full because it uses all the free space in memory with no limits
int StackFull(Stack *StackPtr) {
    return 0;
}

// free all used memory be the stack
void Clear(Stack *StackPtr) {
    Element *PtrToNew;
    while (StackPtr->top != NULL) {
        PtrToNew = StackPtr->top;
        StackPtr->top = StackPtr->top->next;
        free(PtrToNew);
    }
    StackPtr->size = 0;
}

// access all the elements of the stack to apply an action to all of them
void TraverseStack(Stack *StackPtr, void(*pf)(StackEntry)) {
    Element *PtrToNew = StackPtr->top;
    while (PtrToNew) {
        (*pf)(PtrToNew->entry);
        PtrToNew = PtrToNew->next;
    }
    /*
     * the funtion can be written as
     * for(StackNode *pn=ps->top;pn;pn=pn->next){
     * (*pf)(pn->entry);
     * }
     */
}

int StackSize(Stack *StackPtr) {
    return StackPtr->size;
}