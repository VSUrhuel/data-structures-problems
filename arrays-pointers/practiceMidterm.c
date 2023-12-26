#include <stdio.h>
#include <stdlib.h>

int main()
{
	void **arr = (void**)malloc(sizeof(void*)*5);
	arr[1] = (void*)malloc(sizeof(void)*4);
	//((int*)arr[1])[3] = 82;
	*((int*)*((int*)*((int*)arr)+1)+3)=100;
	printf("%d\n", *((int*)*((int*)*((int*)arr)+1)+3));
}