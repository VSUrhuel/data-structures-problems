#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = (int*)malloc(sizeof(int));
    int *ptr2 = (int*)malloc(sizeof(int));
    *ptr1 = 78;
    *ptr2 = 78;

    *ptr1 = (*ptr1 + *ptr2)/2;
    free(ptr2);
    ptr2 = NULL;
    printf("%d\n",*ptr1);
    free(ptr1);
    ptr1 = NULL;
}
