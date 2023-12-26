#include <stdio.h>

int main()
{
	int start, end;
	printf("Start Count: ");
	scanf("%d", &start);
	printf("End Count: ");
	scanf("%d", &end);

	int ctr = 0;
	for(int i=start; i<=end;)
	{
		i += ((i/3) - (i/4));
		ctr++;
	}
	printf("Years: %d", ctr);
}