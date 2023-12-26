#include <stdio.h>

int main()
{
	char arr[2][100] = {"I hate that", "I love that"};
	int n;
	scanf("%d", &n);
	if(n==1)
		printf("I hate it");
	else 
		printf("I hate that ");

	for(int i=2; i<n; i++)
	{
		if(i%2==0)
			printf("%s ", arr[1]);
		else
			printf("%s ", arr[0]);
	}
	if(n>1 && n%2==0)
		printf("I love it");
	else if(n>1)
		printf("I hate it");
}