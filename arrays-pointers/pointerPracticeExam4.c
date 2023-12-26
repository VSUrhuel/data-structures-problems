#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 21;
	char b = 'x';
	double c = 1.21;

	void *m, *o;
	int *p, **n;
	char *q;
	double *r;

	p = &a;
	n = &p;
	q = &b;
	r = &c;

	o = &n;
	m = &o;
	printf("%d\n", ****((int****)m));
	o = &q;
	printf("%c\n", ***((char***)m));
	m = &r;
	printf("%.2f\n", **((double**)m));
	o = &n;
	printf("%d\n", ***((int***)o));
	o = &q;
	printf("%c\n", **((char**)o));
	printf("%.2f\n", *r);
	printf("%d\n", **n);
	printf("%d\n", *p);
	printf("%c\n", *q);
	
	
	
	

	return 0;
}