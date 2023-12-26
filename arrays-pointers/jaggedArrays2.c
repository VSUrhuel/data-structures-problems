#include <stdio.h>
#include <stdlib.h>

double computeMedian(int *arr, int n)
{
	//sort
	int min = 10000, index =  0;
	for(int i=0; i<n; i++)
	{
		min = 10000;
		for(int j=i+1; j<n; j++)
		{
			if(min > arr[j])
			{
				index = j;
				min = arr[j];
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	return (n%2==0) ? ((float)(arr[n/2] + arr[(n/2)-1]) / 2.0f) : arr[n/2];
}

int main()
{
	int arr[] = {9, 1, 3, 11, 6, 5, 8};
	double n = computeMedian(arr, 7);
	printf("Median: %lf\n", n);
	return 0;
}