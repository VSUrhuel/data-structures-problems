#include <stdio.h>
#include <stdlib.h>

int main()
{
	int val = 7;
	int *p;
	p = &val;
	*p = 10;

	float *pi = (float*)malloc(sizeof(float));
	*pi = 3.14;

	p  = pi;

	int **p_ptr = &p; 

	printf("%.2f\n", *((float*)*p_ptr));
	printf("%.2f\n",*((float*)p));
	printf("%.2f\n",*pi);
}