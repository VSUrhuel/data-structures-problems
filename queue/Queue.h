#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _queue
{
	Element* storage;
	int front, rear, size, capacity;

}*QUEUE;

QUEUE createQueue(int capacity);
Element QUEUE_ARRAY_enqueue(QUEUE q, Element data);
Element QUEUE_ARRAY_dequeue(QUEUE q);
Element QUEUE_ARRAY_getFront(QUEUE q);
void QUEUE_ARRAY_display(QUEUE q);


#endif