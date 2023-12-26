#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *num1 = (int*)malloc(sizeof(int));
	int *num2 = (int*)malloc(sizeof(int));
	int *num3 = (int*)malloc(sizeof(int));

	*num1 = 1;
	*num2 = 12;
	*num3 = 67;

	scanf("%d", num1);

	*num2 += *num3;

	free(num3);
	num3 = NULL;

	char *num4 = (char*)malloc(sizeof(char));
	*num4 = 'h';

	void *num_ref;
	num_ref = &num1;
	printf("%d\n", *num1);
	num_ref = &num2;
	printf("%d\n", *num2);
	num_ref = &num4;
	printf("%c\n", *num4);
}