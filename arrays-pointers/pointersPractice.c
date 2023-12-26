#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    // Allocate dynamically an array with size n
    /*int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");*/
    int *arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for(int i=0; i<n; i++)
    {
        *(arr+i) = i+1;
    }
    printf("Address of previous array is %p\n",arr);
    // Increase the size of the existing array twice the previous one
    arr = (int*)realloc(arr, 2*n*sizeof(int));
    printf("Address of the current array is %p\n",arr);
    for(int i=n; i<n*2; i++)
    {
        *(arr+i) = i*2;
    }
    // Print the values
    for(int i=0; i<n*2; i++)
    {
        printf("%d ", arr[i]);
    }
    // Free the memory in the heap
    free(arr);
}
