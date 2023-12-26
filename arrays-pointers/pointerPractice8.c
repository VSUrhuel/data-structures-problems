#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = (int*)malloc(sizeof(int));
    int *ptr2 = (int*)malloc(sizeof(int));
    int *ptr3 = (int*)malloc(sizeof(int));
    *ptr1 = 7;
    *ptr2 = 5;
    *ptr3 = 10;

    float *ave = (float*)malloc(sizeof(float));
    *ave = (float)(((*ptr1) + (*ptr2) + (*ptr3))/3.0);

    printf("%.2f\n",*ave);

    free(ptr1);
    free(ptr2);
    free(ptr3);
    ptr1 = NULL;
    ptr2 = NULL;
    ptr3 = NULL;

    return 0;
}
