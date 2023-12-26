#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a data: ");
    scanf("%d", &a);

    int *p, **q, ***t, ***s, **r, ***u, ***v;

    p = &a;
    q = &p;
    r = &p;
    s = &q;
    t = &q;
    u = &r;
    v = &r;

    printf("%d\n",*p);
    printf("%d\n",**q);
    printf("%d\n",**r);
    printf("%d\n",***s);
    printf("%d\n",***t);
    printf("%d\n",***u);
    printf("%d\n",***v);

}
