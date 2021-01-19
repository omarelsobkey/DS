#ifdef ARRAY_BASED_STACK

#include "../include/stack.h"

// initialize stack top with 0
void CreateStack(Stack *StackPtr) {
    StackPtr->top = 0;
}

// add element EntryValue to the top of the stack and increase (top) by one
void Push(StackEntry EntryValue, Stack *StackPtr) {
    //check the stack is full or not before accessing elements
    if (StackPtr->top != MAXSTACK)
        StackPtr->entry[StackPtr->top++] = EntryValue;
}

/*
 * remove the top element of the stack after assigning its value to (EntryValue)
 * and decrease top by one
 */
void Pop(StackEntry *EntryValuePtr, Stack *StackPtr) {
    //check the stack is empty or not before accessing elements
    if (StackPtr->top)
        *EntryValuePtr = StackPtr->entry[--StackPtr->top];
}

// assigning the top of the stack to (EntryValue)
void StackTop(StackEntry *EntryValuePtr, Stack *StackPtr) {
    //check the stack is empty or not before accessing elements
    if (StackPtr->top)
        *EntryValuePtr = StackPtr->entry[StackPtr->top - 1];
}
/*
 * in user level the function will be:
 * void StackTop(StackEntry *pe, Stack *ps){
 * pop(pe, pe);
 * push(*pe, ps);
 * }
 * now the top of the stack is assigned to the variable e
 */

// check whether the stack is full or not
int StackFull(Stack *StackPtr) {
    return StackPtr->top >= MAXSTACK;
}

// check whether the stack is empty or not
int StackEmpty(Stack *StackPtr) {
    return !StackPtr->top;
}

//return the number of elements
int StackSize(Stack *StackPtr) {
    return StackPtr->top;
}

// remove all the elements from the stack
void ClearStack(Stack *StackPtr) {
    StackPtr->top = 0;
}

// print all elements in the stack
void Display(Stack *StackPtr) {
    for (int i = StackPtr->top; i > 0; i--) {
        printf("%d\n", StackPtr->entry[i - 1]);
    }
}

/*******************************************************/
#else

#include <stdlib.h>
#include "../include/stack.h"

// initialize the top location of the stack
void CreateStack(Stack *StackPtr) {
    StackPtr->top = NULL;
    StackPtr->size = 0;
}

// add element to the top of the stack
// change the location of the top
void Push(StackEntry EntryValue, Stack *StackPtr) {
    // malloc returns a pointer of type void
    // (StackNode*) is casting the returned pointer from void to StackNode
    StackNode *PtrToNew = (StackNode *) malloc(sizeof(StackNode));
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
        StackNode *PtrToNew = StackPtr->top;
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
    StackNode *PtrToNew;
    while (StackPtr->top != NULL) {
        PtrToNew = StackPtr->top;
        StackPtr->top = StackPtr->top->next;
        free(PtrToNew);
    }
    StackPtr->size = 0;
}

// access all the elements of the stack to apply an action to all of them
void TraverseStack(Stack *StackPtr, void(*pf)(StackEntry)) {
    StackNode *PtrToNew = StackPtr->top;
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

#endif
