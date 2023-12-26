#include "queueA.h"
#include <stdio.h>
#include <stdlib.h>

QUEUEARRAY QUEUEARRAY_create(int size)
{
	QUEUEARRAY q = (QUEUEARRAY)malloc(sizeof(struct _queuearray));
	q->front = q->rear = q->size = 0;
	q->arr = (Element*)malloc(sizeof(Element) * size);
	q->capacity = size;
	return q;
}

void QUEUEARRAY_enqueue(QUEUEARRAY queue, Element data)
{
	if(queue->size<queue->capacity)
	{
		queue->arr[queue->rear] = data;
		queue->rear = (queue->rear+1)%q->capacity;
		queue->size++; 
	}
}

Element QUEUEARRAY_dequeue(QUEUEARRAY queue)
{
	if(queue->size > 0)
	{
		Element x = queue->arr[queue->front];
		q->front = (queue->front-1)%q->capacity;
		q->size--;
		return x;
	}
	return 0;
}

Element QUEUE_ARRAY_getFront(QUEUEARRAY queue)
{
	if(queue->size > 0)
	{
		Element x = queue->arr[queue->front];
		return x;
	}
	return 0;
}

int QUEUEARRAY_isEmpty(QUEUEARRAY queue)
{
	return queue->size == 0;
}

int QUEUEARRAY_isFull(QUEUEARRAY queue)
{
	return queue->size == queue->capacity;
}

void QUEUEARRAY_display(QUEUEARRAY queue)
{
	for(int i=0; i<queue->size; i++)
		printf("%d,", queue->arr[(queue->front+i)%q->capacity]);
}