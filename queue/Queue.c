#include "Queue.h"

QUEUE createQueue(int capacity)
{
	QUEUE q = (QUEUE)malloc(sizeof(struct _queue));
	q->storage = (Element*)malloc(sizeof(Element)*capacity);
	q->front = q->rear = q->size = 0;
	q->capacity = capacity;
	return q;
}

Element QUEUE_ARRAY_getFront(QUEUE q)
{
	return (q->size > 0) ? q->storage[q->front] : -1;
}

int QUEUE_ARRAY_enqueue(QUEUE q, Element data)
{
	if(q->size < q->capacity)
	{
		q->storage[q->rear] = data;
		q->rear = (q->rear+1)%q->capacity;
		q->size++; 
		return 1;
	}
	return 0;
}

Element QUEUE_ARRAY_dequeue(QUEUE q)
{
	if(q->size > 0)
	{
		Element res = q->storage[q->front];
		q->front = (q->front+1)%q->capacity;
		q->size--;
		return res;
	}
	return -1;
}

void QUEUE_ARRAY_display(QUEUE q)
{
	printf("\n[");
	for(int i=0; i<q->size; i++)
	{
		printf("%d ", q->storage[(q->front+i)%q->capacity]);
	}
	printf("]\n");
}