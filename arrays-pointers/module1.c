#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int **knows = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		knows[i] = (int*)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &knows[i][j]);
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ", knows[i][j]);
		}
		printf("\n");
	}

	int ctr = 0, check = 0;
	for(int i=0; i<n; i++)
	{
		ctr = 0;
		for(int j=0; j<n; j++)
		{
			if(knows[i][j]==0)
			{
				ctr++;
			}
		}
		if(ctr==(n-1))
		{
			ctr = 0;
			for(int j=0; j<n; j++)
			{
				if(knows[j][i] == 1)
				{
					ctr++;
				}
			}
			if(ctr == n)
			{
				printf("p%d\n", (i+1));
				check = 1;
				break;
			}
		}
	}
	if(check != 1)
		printf("None\n");

	for(int i=0; i<n; i++)
	{
		free(knows[i]);
		knows[i] = NULL;
	}
	free(knows);
	knows = NULL;
}