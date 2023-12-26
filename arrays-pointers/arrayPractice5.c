#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the number of elements to be stored: ");
	scanf("%d",&n);

	int *ptr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
	    printf("enter: ");
		scanf("%d",&ptr[i]);
	}
	for(int i=0; i<n; i++)
	{
	    if(ptr[i]%3==0)
            printf("%d, ",ptr[i]);
	}
}

