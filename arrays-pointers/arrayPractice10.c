#include <stdio.h>

void generateHintMap(int a[3][5], int row, int col, int r, int c);

int main()
{
	int mineSweeper[][5] = {{0,1,1,1},{0,0,1,0,1},{0,1,1,0,0}, {1,0,0,0,0}};
	int col = sizeof(mineSweeper[0])/sizeof(mineSweeper[0][0]);
	int row = sizeof(mineSweeper)/col;

	int r, c;
	printf("Enter an index locaion (row, col): ");
	scanf("%d %d", &r, &c);

	generateHintMap(mineSweeper, 3, 5, r, c);

	return 0;
}

void generateHintMap(int a[3][5], int row, int col, int r, int c)
{

	int newArr[3][5] = {0};
	int k = 0, l = 0, checker = 0;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if ((r-1 == i || r == i || r + 1 == i) && (c-1 == j || c == j || c +1 == j))
			{
				newArr[k][l] = a[i][j];
				l++;
				checker = 1;
				if((r == i && c == j) && a[i][j] == 1)
					printf("Location is in a Mine\n");
			}
			else
				break;

		}
		if(checker)
			k++;
	}

	int colSize = sizeof(newArr[0])/sizeof(newArr[0][0]);
	int rowSize = sizeof(newArr)/sizeof(colSize);
	for(int i=0;i<3; i++)
	{
		for(int j=0; j<3; j++)
			printf("%d ",newArr[i][j]);
		printf("\n");
	}
}