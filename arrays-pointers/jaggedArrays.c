#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **arr = (int**)malloc(sizeof(int*)*5);
	for(int i=0; i<5; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*(i+1));
		for(int j=0; j <= i; j++)
			arr[i][j] = j;
	}

	int *temp = arr[1];
	arr[1] = arr[4];
	arr[4] = temp;

	for(int i=0; i<5; i++)
	{
		printf("[%d] ", i);
		if(i == 1)
		{
			for(int j=0; j < 5; j++)
				printf("%d ", arr[i][j]);
		}
		else if(i == 4)
		{
			for(int j=0; j < 2; j++)
				printf("%d ", arr[i][j]);
		}
		else
		{
			for(int j=0; j <= i; j++)
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}