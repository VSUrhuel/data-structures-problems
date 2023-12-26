#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1002;
    int *p;
    p = &a;
    a = 8490;

    float *pi = (float*)malloc(sizeof(float));
    *pi = 3.14;

    p = pi;
    printf("%f",*p);
    int *p_ptr;
    p_ptr = p;

    printf("%f",*p_ptr);
    free(pi);

}
