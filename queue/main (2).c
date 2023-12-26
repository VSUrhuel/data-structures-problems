#include "Queue.h"

int main()
{
	int m, n;
	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);

	int limit = n+1;
	QUEUE q = createQueue(n);
	for(int i=1; i<limit; i++)
	{
		QUEUE_ARRAY_enqueue(q,i);
	}
	while(q->size > 1)
	{
		limit = m-1;
		for(int i=0; i<limit; i++)
			QUEUE_ARRAY_enqueue(q, QUEUE_ARRAY_dequeue(q));
		QUEUE_ARRAY_dequeue(q);
	}
	printf("Winner: %d", QUEUE_ARRAY_getFront(q));
	return 0;
}