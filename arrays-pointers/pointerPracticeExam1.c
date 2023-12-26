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

	o = &n = &q;
	m = &o = &r;

	printf("%d\n", (****(int****)m));
	printf("%c\n", *q);
	printf("%d\n", *p);
	printf("%d\n", **n);
	printf("%.2f\n", *r);
}