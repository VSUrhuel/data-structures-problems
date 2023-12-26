#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr = (int*)malloc(sizeof(int)*3);
	for(int i=0; i<3; i++)
		scanf("%d", &arr[i]);
	void *x, *y;
	int *a;

	a = &arr;
	y = &a;
	x = &y;

	for(int i=0; i<3; i++)
		printf("%d,", *((int*)***((int***)x)+i));
	printf("\n");
	for(int i=0; i<3; i++)
		printf("%d,", *((int*)**((int**)y)+i));
	printf("\n");
	for(int i=0; i<3; i++)
		printf("%d,",  *((int*)*((int*)a)+i));

	printf("\nEnter a 2D Array of size 3\n");
	int **arr2 = (int**)malloc(sizeof(int*)*3);
	for(int i=0; i<3; i++)
	{
		arr2[i] = (int*)malloc(sizeof(int)*3);
		for(int j=0; j<3; j++)
			scanf("%d", &arr2[i][j]);
	}

	a = &arr2;
	y = &a; 
	x = &y;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			printf("%d,", *((int*)*((int*)***((int***)x)+i)+j));
		printf("\n");
	}

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			printf("%d,", *((int*)*((int*)**((int**)y)+i)+j));
		printf("\n");
	}
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			printf("%d,", *((int*)*((int*)*((int*)a)+i)+j));
		printf("\n");
	}

	printf("\nEnter a 2D Array of size 3\n");
	int arr3[3][3];
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			scanf("%d", &arr3[i][j]);
		}
	}

	a = &arr3;
	y = &a;
	x = &y;

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
			printf("%d,",*((((*a))+i)+j));
		printf("\n");
	}
}