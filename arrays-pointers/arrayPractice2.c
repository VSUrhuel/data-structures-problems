#include <stdio.h>

int main()
{
    int arr[7];
    arr[0] = 10;
    arr[1] = 6;
    arr[2] = 3;
    arr[3] = 8;
    arr[4] = 5;
    arr[5] = 1;
    arr[6] = 2;

    int cumultative[7];
    cumultative[0] = 10;
    int prev = 10;
    for(int i=1; i<7;i++)
    {
        int next = arr[i];
        int sum = prev+next;
        cumultative[i] = sum;
        prev = cumultative[i];
    }
    for(int i=0; i<7; i++)
        printf("Arr[%d]: %d -- Cumultative[%d]: %d\n",i,arr[i],i,cumultative[i]);
}
