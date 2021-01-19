#include <stdio.h>

#define Linked_BASED_STACK
#include "stack.c"

int main(){
	Stack s;
	CreateStack(&s);
	Push(5, &s);
	return 0; 
}