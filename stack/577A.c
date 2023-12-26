#include <stdio.h>

int main()
{
	int n, x, ctr = 0;
	scanf("%d %d", &n, &x);
	
	for(int i=1; i<n+1; i++)
		if(x%i==0 && (x<=(i*n)))
		{
			printf("%d\n", i);
			ctr++;
		}
	printf("%d\n", ctr);
}