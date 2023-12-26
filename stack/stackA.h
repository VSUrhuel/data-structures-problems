#ifndef STACK_A
#define STACK_A

#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct _stackarr
{
	Element* arr;
	int top;
	int size;
} *STACKARR;

STACKARR STACKARR_create(int size);
void STACKARR_push(STACKARR stack, Element data);
Element STACKARR_pop(STACKARR stack);
Element STACKARR_peek(STACKARR stack);
int STACKARR_isEmpty(STACKARR stack);
int STACKARR_isFull(STACKARR stack);
void STACKARR_display(STACKARR stack);

#endif