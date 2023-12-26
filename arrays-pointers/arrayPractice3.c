#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the number of elements to be stored: ");
	scanf("%d",&n);

	char *ptr = (char*)malloc(n*sizeof(char));
	for(int i=0; i<n; i++)
	{
		scanf("%c",&ptr[i]);
		printf("\n");
	}
	for(int i=0; i<n; i++)
	{
		printf("%c",ptr[i]);
	}
}