#include <stdio.h>
#include <stdlib.h>

void findEven(int ptr[], int n);

int main()
{
    int n;
    printf("Number of Elements: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(n));
    for(int i=0; i<n; i++)
    {
        printf("enter: ");
        scanf("%d",&arr[i]);
    }
    findEven(arr,n);
    for(int i=0;i<n; i++)
    {
        if(arr[i] == NULL)
            printf("");
        else
            printf("%d, ", arr[i]);
    }
    return 0;
}

void findEven(int ptr[], int n)
{
    int j = 0;
    for(int i=0; i<n; i++)
    {
        if(ptr[i]%2!=0)
        {
            ptr[j] = ptr[i];
            j++;
            ptr[i] = NULL;
        }
    }
}
