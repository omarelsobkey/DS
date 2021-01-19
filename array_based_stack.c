#include <stdio.h>
#include "array_based_stack.h"

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
