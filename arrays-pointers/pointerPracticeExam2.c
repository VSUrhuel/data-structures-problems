#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *b, *c, *d, *e;

	int *nums = (int*)malloc(sizeof(int)*5);

	for(int i=0; i<5; i++)
		scanf("%d",&nums[i]);
	for(int i=0; i<5; i++)
		printf("%d\n", nums[i]);

	nums[0] = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4])/5;

	printf("%d\n", nums[0]);
}