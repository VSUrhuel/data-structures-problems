#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int arr[1000];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	int min = 10000000, index = 0, flag = 0;
	for(int i=0; i<n; i++)
	{
		min = 100000000;
		for(int j=i; j<n; j++)
		{
			if(min > arr[j])
			{
				min = arr[j];
				index = j;
				flag = 1;
			}
		}
		if(flag)
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
		printf("%d ", arr[i]);
	}
}
