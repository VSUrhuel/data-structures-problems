#include <stdio.h>
#include <stdlib.h>

int *findEven(int *arr, int n)
{
	int ctr = 0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]%2 == 0 && arr[i] >= 0)
			ctr++;
	}
	int *arr2 = (int*)malloc(sizeof(int)*ctr);
	arr2[0] = ctr;
	int ctr2 = 1;
	for(int i=0; i<n; i++)
	{
		if(arr[i]%2 == 0 && arr[i] >= 0)
		{
			arr2[ctr2] = arr[i];
			ctr2++;
		}
	}
	return arr2;
}
int main()
{
	int arr[] = {56, 7, 1, 8, 10, 6};
	int *newArr = findEven(arr, 6);
	for(int i=0; i<newArr[0]; i++)
		printf("%d ", newArr[i]);
}