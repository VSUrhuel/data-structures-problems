#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = (int*)malloc(sizeof(int));
    char *ptr2 = (char*)malloc(sizeof(char));
    double *ptr3 = (double*)malloc(sizeof(char));

    printf("%d\n",sizeof(ptr1));
    printf("%d\n",sizeof(ptr2));
    printf("%d\n",sizeof(ptr3));
}
