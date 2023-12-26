#include "stackC.h"
#include <stdio.h>

int main()
{
	STACKARR s = STACKARR_create(100);
	STACKARR_push(s, 2);
	STACKARR_push(s, 4);
	STACKARR_push(s, 21);
	STACKARR_push(s, 3);
	STACKARR_display(s);
	printf("Top: %d \t Is Empty: %d \t Is Full: %d\n", STACKARR_peek(s), STACKARR_isEmpty(s), STACKARR_isFull(s));
}