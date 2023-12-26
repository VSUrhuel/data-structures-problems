#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, *p, **q, **r, ***s, ***t, ***u, ***v; //allocated memory on stack;
	int ****specialPointer = (int****)malloc(sizeof(int)); //allocated memory on heap;

	a = 14;
	p = &a;
	q = r = &p;
	s = t = &q;
	u = v = &r;

	//printf("%p\n",p); //0061FF0C
	specialPointer = &s;

	/*printf("%d\n", ***u);
	printf("%d\n", ***s);*/

	scanf("%d", ***specialPointer);
	printf("%d\n", ***s);

	/*printf("Address of A: %p\n", **u);
	printf("Address: %p Value: %d\n",specialPointer, ****specialPointer);
	free(***specialPointer); // freeing the value
	printf("Address after freeing: %p Value: %d\n",specialPointer, ****specialPointer);
	printf("Address of A: %p\n", **u);
	printf("%d\n", ***u);
	specialPointer = NULL; // removing the value
	printf("Address after null: %p Value: %d\n",specialPointer, ****specialPointer);*/
}