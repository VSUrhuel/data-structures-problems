#include <stdio.h>
#include <stdlib.h>

int main()
{
    char data1 = 'X';
    int data2 = 100;
    float data3 = 3.14f;


    void *data = &data2;
    printf("%d\n", *((int*)data));

    data = &data3;
    printf("%f\n", *(float*)data);

    data = &data1;
    printf("%c\n", *(char*)data);

}
