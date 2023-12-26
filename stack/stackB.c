#include "stackB.h"

STACKARR STACKARR_create(int size)
{
	STACKARR s = (STACKARR)malloc(sizeof(struct _stackarr));
	s->top = 0;
	s->size = size;
	s->arr = (Element*)malloc(sizeof(Element)*size);
	return s;
}

void STACKARR_push(STACKARR stack, Element data)
{
	if(stack->top < stack->size)
		stack->arr[stack->top++] = data;
}

Element STACKARR_pop(STACKARR stack)
{
	if(stack->top > 0)
	{
		Element x = stack->arr[stack->top-1];
		stack->top--;
		return x;
	}
	return -1;
}

Element STACKARR_peek(STACKARR stack)
{
	return (stack->top > 0) ? stack->arr[stack->top-1] : -1;
}

int STACKARR_isEmpty(STACKARR stack)
{
	return stack->top == 0;
}

int STACKARR_isFull(STACKARR stack)
{
	return stack->top == stack->size;
}

void STACKARR_display(STACKARR stack);
{
	for(int i=stack->top-1; i>-1; i--)
		printf("%d,",stack->arr[i]);
}
