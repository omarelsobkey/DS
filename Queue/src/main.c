#include <stdio.h>

#define LINKED_BASED_QUEUE
#include "queue.c"

int main(){
	Queue q;
	CreateQueue(&q);
	Append(5, &q);
	Append(5, &q);
	printf("%d", QueueSize(&q));
	return 0;
}