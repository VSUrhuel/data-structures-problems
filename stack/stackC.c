#include "stackC.h"
#include <stdlib.h>

STACKARR STACKARR_create(int size)
{
	STACKARR s = (STACKARR)malloc(sizeof(struct _stackarr));
	s->size = size;
	s->top = 0;
	s->arr = (Element*)malloc(sizeof(Element) * size);
	return s;
}

void STACKARR_push(STACKARR stack, Element data)
{
	if(stack->top < stack->size)
		stack->arr[stack->top++] = data;
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
void STACKARR_display(STACKARR stack)
{
	for(int i=stack->top-1; i>-1; i--)
		printf("%d\n", stack->arr[i]);
}
