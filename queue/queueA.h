#ifndef QUEUE_A
#define QUEUE_A

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _queuearray
{
	Element *arr;
	int front, rear, size, capacity;
} *QUEUEARRAY;

QUEUEARRAY QUEUEARRAY_create(int size);
void QUEUEARRAY_enqueue(QUEUEARRAY queue, Element data);
Element QUEUEARRAY_dequeue(QUEUEARRAY queue);
Element QUEUE_ARRAY_getFront(QUEUEARRAY queue);
int QUEUEARRAY_isEmpty(QUEUEARRAY queue);
int QUEUEARRAY_isFull(QUEUEARRAY queue);
void QUEUEARRAY_display(QUEUEARRAY queue);

#endif