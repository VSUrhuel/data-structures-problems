#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x = 5.9;
	int y = 7;

	float *a = &x;
	void *p = &a;

	**((float**)p) = 3;
	p = &y;
	printf("%d\n", *((int*)p) += *a);
}