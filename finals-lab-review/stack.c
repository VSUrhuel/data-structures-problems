#include "stack.h"

STACKARR STACKARR_create(int size)
{
	STACKARR stack = (STACKARR)malloc(sizeof(struct _stackarr));
	stack->arr = (Element*)malloc(sizeof(Element) * size);
	stack->top = 0;
	stack->size = size;
	return stack;
}

void STACKARR_push(STACKARR stack, Element data)
{
	if(stack->top < stack->size)
		stack->arr[stack->top++]= data;
	else
		printf("Stack Overflow\n");
}

Element STACKARR_pop(STACKARR stack)
{
	Element x = (stack->top > 0) ? stack->arr[stack->top-1] : -1;
	if(stack->top > 0)
		stack->top--;
	else
		printf("Empty Stack\n");
	return x;
}

Element STACKARR_peek(STACKARR stack)
{
	if(stack->top > 0)
		return stack->arr[stack->top-1];
	return -1;
}

int STACKARR_isEmpty(STACKARR stack)
{
	return stack->top == 0;
}

int STACKARR_isFull(STACKARR stack)
{
	return stack->top == stack->size;
}

void STACKARR_display(STACKARR stack)
{
	for(int i=stack->top-1; i>-1; i--)
		printf("%d, ", stack->arr[i]);
}
