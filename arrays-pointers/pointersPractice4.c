#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int *p;
    int **q;

    a = 14;
    p = &a;
    q = &p;

    printf("%d\n", a); // 14
    printf("%d\n",*p); // 14
    printf("%d\n",**q); // 14, since double dereference, it first dereference the p, then go to which the p derefer
    printf("%p\n",p);  // address of p
    printf("%p\n",q); // address of q

    printf("\n%p\n",*q); // address of p, because it will dereference at once, and it will go first to the address of p
}
