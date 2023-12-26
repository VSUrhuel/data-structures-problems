#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1025;
    int *p;
    p = &a;
    int *baseAddress = &a;
    int n;
    printf("How many addresses you want to play: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("%d ",(p+i));
    }
    printf("\n");
    int k = 0;
    for(int i=0; i<n; i++)
    {
        arr[i] = ((int)(baseAddress)) + k * sizeof(int);
        k++;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}
